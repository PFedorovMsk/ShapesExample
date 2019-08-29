#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAddCircle_clicked()
{
    QColor color;
    if (ui->rbRedCircle->isChecked()) {
        color = Qt::red;
    } else if (ui->rbGreenCircle->isChecked()) {
        color = Qt::green;
    } else {
        color = Qt::blue;
    }

    Shape *circle = new Circle(color, Qt::black, ui->dsbBorderWidth->value(),
                               QPointF(ui->dsbCenterX->value(), ui->dsbCenterY->value()), ui->dsbRadius->value());
    circle->setScaleFactor(ui->dsbScale->value());

    ui->scene->addShape(circle);
}

void MainWindow::on_btnAddQuadrilateral_clicked()
{
    QColor color;
    if (ui->rbRedQuadrilateral->isChecked()) {
        color = Qt::red;
    } else if (ui->rbGreenQuadrilateral->isChecked()) {
        color = Qt::green;
    } else {
        color = Qt::blue;
    }

    QVector<QPointF> vertices;
    vertices.append(QPointF(ui->dsbVertex1X->value(), ui->dsbVertex1Y->value()));
    vertices.append(QPointF(ui->dsbVertex2X->value(), ui->dsbVertex2Y->value()));
    vertices.append(QPointF(ui->dsbVertex3X->value(), ui->dsbVertex3Y->value()));
    vertices.append(QPointF(ui->dsbVertex4X->value(), ui->dsbVertex4Y->value()));

    Shape *rect = new Quadrilateral(color, Qt::black, ui->dsbBorderWidth->value(), vertices);
    rect->setRotationAngle(ui->dsbRotation->value());
    rect->setScaleFactor(ui->dsbScale->value());

    ui->scene->addShape(rect);
}

void MainWindow::on_btnApply_clicked()
{
    ui->scene->setBorderWidth(ui->dsbBorderWidth->value());
    ui->scene->setRotationAngle(ui->dsbRotation->value());
    ui->scene->setScaleFactor(ui->dsbScale->value());

    emit ui->scene->update();
}

void MainWindow::on_btnClear_clicked()
{
    ui->scene->clear();
}
