#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "circle.h"
#include "quadrilateral.h"
#include <QMainWindow>


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAddCircle_clicked();

    void on_btnAddQuadrilateral_clicked();

    void on_btnApply_clicked();

    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
