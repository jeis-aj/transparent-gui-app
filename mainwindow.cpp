#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // Set up transparent window
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create the QCustomPlot object for the plot
    customPlot = new QCustomPlot(this);

    // Set transparent background for the plot
    customPlot->setBackground(Qt::transparent);
    customPlot->axisRect()->setBackground(Qt::transparent);

    // Call method to setup the plot
    setupPlot();

    // Layout for the plot
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(customPlot);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    // Custom clean-up logic
}

void MainWindow::setupPlot() {
    // Add some data for the line plot
    QVector<double> x(100), y(100); // Create vectors for x and y data
    for (int i = 0; i < 100; ++i) {
        x[i] = i / 10.0;
        y[i] = qSin(x[i]); // y = sin(x)
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);

    // Style the plot
    customPlot->graph(0)->setPen(QPen(Qt::white)); // Set line color to white
    customPlot->xAxis->setRange(0, 10);
    customPlot->yAxis->setRange(-1, 1);

    // Set axis color to transparent (if required)
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setBasePen(QPen(Qt::white));

    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));

    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setTickLabelColor(Qt::white);
}

