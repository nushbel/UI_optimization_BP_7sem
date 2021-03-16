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
    ~MainWindow();

private slots:
    void on_pushButton_optimize_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
