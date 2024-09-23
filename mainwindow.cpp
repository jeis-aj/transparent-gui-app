#include "mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPalette>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    // Set window properties for transparency
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create a central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Set a transparent background color
    QPalette palette = centralWidget->palette();
    palette.setColor(QPalette::Background, Qt::transparent);
    centralWidget->setAutoFillBackground(true);
    centralWidget->setPalette(palette);

    // Create a label with "Hello, World!" text
    QLabel *label = new QLabel("Hello, World!", this);
    label->setStyleSheet("QLabel { color : white; font-size: 30px; }");

    // Create a layout and add the label
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(label);
    layout->setAlignment(label, Qt::AlignCenter);
}

MainWindow::~MainWindow() {}

