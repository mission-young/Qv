#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "convert.h"
#include <QListWidgetItem>
#include "rename.h"
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
    void on_btn_start_clicked();

    void on_btn_ipf_clicked();

    void on_btn_opf_clicked();

    void on_btn_delete_clicked();

    void on_btn_clear_clicked();

    void on_btn_rawopf_clicked();

    void on_lw_opf_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
