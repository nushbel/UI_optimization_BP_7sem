#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Math/Function.h"
#include "Math/area.h"
#include "Math/gradientDescent.h"
#include "Math/randomSearch.h"
#include "Math/stopCrit.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QMouseEvent* qme;
    double geomx;
    double geomy;

    Function* f;
    int fType;
    int optMethodType;
    int stopType;
    area area;
    double area_xl;
    double area_xr;
    double area_yl;
    double area_yr;
    double x0;
    double y0;
    std::vector<double> x0y0;
    stopCrit* stop;
    optimizationMethod* opt;
    double iterNum;
    MainWindow(QWidget *parent = nullptr);
    void Plot(QCustomPlot * customPlot);
    //void mouseClick(QMouseEvent* event);
    ~MainWindow();

    int startPointType;

private slots:
    void on_pushButton_optimize_clicked();
    void mousePos(QMouseEvent* event);

    void mouseClick(QMouseEvent* event);

    void on_pushButton_plot_clicked();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
