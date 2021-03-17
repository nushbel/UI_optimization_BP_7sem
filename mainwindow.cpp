#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->plot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mousePos(QMouseEvent*)));
    connect(ui->plot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mouseClick(QMouseEvent*)));
    Plot(ui->plot);
    x0 = -10^5;
    y0 = -10^5;
    startPointType = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Plot(QCustomPlot * customPlot){

      customPlot->clearPlottables();
      customPlot->axisRect()->setupFullAxesBox(true);
      customPlot->xAxis->setLabel("x");
      customPlot->yAxis->setLabel("y");

      QCPColorMap *colorMap = new QCPColorMap(customPlot->xAxis, customPlot->yAxis);
      int numOfx = 100;
      int numOfy = 100;


      colorMap->data()->setSize(numOfx, numOfy);
      colorMap->data()->setRange(QCPRange(area_xl, area_xr), QCPRange(area_yl, area_yr));
      double x, y, z;

      for (int x_i = 0; x_i < numOfx; ++x_i)
      {
        for (int y_i = 0; y_i < numOfy; ++y_i)
        {
          colorMap->data()->cellToCoord(x_i, y_i, &x, &y);
          switch (fType){
                  case 1:
                    z = x*x + y*y;
                    break;
                  case 2:
                    z = y*y + cos(x + y) + 1;
                    break;
          }
          colorMap->data()->setCell(x_i, y_i, z);
        }
      }


      QCPColorScale *colorScale = new QCPColorScale(customPlot);
      customPlot->plotLayout()->addElement(0, 1, colorScale);
      colorScale->setType(QCPAxis::atRight);
      colorMap->setColorScale(colorScale);

      colorMap->setGradient(QCPColorGradient::gpCandy);

      colorMap->rescaleDataRange();


      QCPMarginGroup *group = new QCPMarginGroup(customPlot);
      colorScale->setMarginGroup(QCP::msTop|QCP::msBottom, group);
      customPlot->axisRect()->setMarginGroup(QCP::msTop|QCP::msBottom, group);


      customPlot->rescaleAxes();
      customPlot->replot();

}

void MainWindow::on_pushButton_optimize_clicked()
{

    QString combobox_func = ui->comboBox_func->currentText();
    if(combobox_func == "f(x, y) = x^2 + y^2")
    {
        fType = 1;
    }
    else if(combobox_func == "f(x, y) = y^2 + cos(x + y) + 1")
    {
        fType = 2;
    }

    QString combobox_method = ui->comboBox_method->currentText();
    if(combobox_method == "Gradient descent")
    {
        optMethodType = 1;
    }
    else if(combobox_method == "Random search")
    {
        optMethodType = 2;
    }

    QString combobox_stop = ui->comboBox_stop->currentText();
    if(combobox_stop == "f-epsilon")
    {
        stopType = 1;
    }

    area_xl = ui->lineEdit_xleft->text().toDouble();
    area_xr = ui->lineEdit_xright->text().toDouble();
    area_yl = ui->lineEdit_yleft->text().toDouble();
    area_yr = ui->lineEdit_yright->text().toDouble();

    area.left = {area_xl, area_yl};
    area.right = {area_xr, area_yr};

    if (startPointType == 1)
    {
        x0 = ui->lineEdit_x0->text().toDouble();
        y0 = ui->lineEdit_y0->text().toDouble();
        x0y0 = {x0, y0};
    }

    switch (fType) {
            case 1:
            {
                f = new Function1();
                break;

            }
            case 2:
            {
                f = new Function2();
                break;
            }
        }

    Plot(ui->plot);
    ui->plot->replot();

    switch (stopType) {
            case 1:
            {
                stop = new stopCritEpsilon(f);
                break;

            }
        }


    switch (optMethodType) {
    case 1:
            {
                opt = new gradientDescent(&area, stop, f);
                break;
            }
            case 2:
            {
                opt = new randomSearch(&area, stop, f);
                break;
            }
        }

    int iterNum = 0;
        std::vector<double> result = opt->argMin(x0y0, iterNum);
        double a = result[0];
        double b = result[1];

        double fInArgMin = f->eval(result);

        ui->label_consoleResult->setText("Result\nArg min:\n(" + QString::number(a) + ", " + QString::number(b) + ")\nFunction in arg min:\n" + QString::number(fInArgMin) + "\nNumber of iterations:\n" + QString::number(iterNum));

        Plot(ui->plot);
        ui->plot->replot();

        //plot trajectory
        QVector<double> xPlot = QVector<double>(opt->xPlot.begin(), opt->xPlot.end());
        QVector<double> yPlot = QVector<double>(opt->yPlot.begin(), opt->yPlot.end());

        QCPCurve *trajectory = new QCPCurve(ui->plot->xAxis, ui->plot->yAxis);
        trajectory->setData(xPlot, yPlot);
        trajectory->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 0), QBrush(Qt::black), 4));
        trajectory->setPen(QPen(Qt::black, 1));

        ui->plot->replot();

}

void MainWindow::mousePos(QMouseEvent* event)
{

}

void MainWindow::mouseClick(QMouseEvent* event)
{
    if (startPointType == 2)
    {
    QString num, num2;
    ui->plot->mouseMove(event);
    geomx = area_xl + (area_xr-area_xl)*(double(event->x()) - 52.)/413;
    geomy = -(area_yl + (area_yr-area_yl)*(double(event->y()) - 14.)/454);
    ui->label_x0y0->setText("x_0 = " +  QString::number(geomx) + "\ny_0 = " + QString::number(geomy) + "\n");
    x0 = geomx;
    y0 = geomy;
    x0y0 = {x0, y0};
    }

}

void MainWindow::on_pushButton_plot_clicked()
{

    ui->label_x0y0->setText("Click on the graph to select \na starting point");
    QString combobox_func = ui->comboBox_func->currentText();
        if(combobox_func == "f(x, y) = x^2 + y^2")
        {
            fType = 1;
        }
        else if(combobox_func == "f(x, y) = y^2 + cos(x + y) + 1")
        {
            fType = 2;
        }

        area_xl = ui->lineEdit_xleft->text().toDouble();
        area_xr = ui->lineEdit_xright->text().toDouble();
        area_yl = ui->lineEdit_yleft->text().toDouble();
        area_yr = ui->lineEdit_yright->text().toDouble();

        area.left = {area_xl, area_yl};
        area.right = {area_xr, area_yr};


        switch (fType) {
                case 1:
                {
                    f = new Function1();
                    break;
                }
                case 2:
                {
                    f = new Function2();
                    break;
                }
            }
        Plot(ui->plot);
        ui->plot->replot();
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if (index == 0)
    {
        startPointType = 1;
    }
    else
    {
        startPointType = 2;
    }
}
