#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>

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

void MainWindow::on_btn_start_clicked()
{

    if(ui->lw_ipf->count()==0) {
        QMessageBox::information(this,"输入为空","请检测文件是否存在!");
        return;
    }
    if(ui->lw_opf->count()==0) {
        QMessageBox::information(this,"输出为空","请输入输出目录!");
        return;
    }
    for (int i = 0; i < ui->lw_ipf->count(); ++i) {
        Convert s(ui->lw_ipf->item(i)->text(),ui->lw_opf->item(i)->text(),ui->sb_thread->value());
    }
}

void MainWindow::on_btn_ipf_clicked()
{
    foreach (auto ipfname, QFileDialog::getOpenFileNames()) {
        ui->lw_ipf->addItem(QFileInfo(ipfname).path()+"/"+QFileInfo(ipfname).fileName());
    }
}

void MainWindow::on_btn_opf_clicked()
{
    QFileInfo opfname(QFileDialog::getExistingDirectory());
    for (int i = 0; i < ui->lw_ipf->count(); ++i) {
        QString opfitem=opfname.path()+"/"+opfname.fileName()+"/"+QFileInfo(ui->lw_ipf->item(i)->text()).baseName()+"."+ui->cbb_format->currentText();
        ui->lw_opf->addItem(opfitem);
    }
}

void MainWindow::on_btn_delete_clicked()
{
    foreach (auto item, ui->lw_ipf->selectedItems()) {
        int row=ui->lw_ipf->row(item);
        if(ui->lw_opf->count()>0) delete ui->lw_opf->takeItem(row);
        delete ui->lw_ipf->takeItem(row);
    }
}

void MainWindow::on_btn_clear_clicked()
{
    ui->lw_opf->clear();
}

void MainWindow::on_btn_rawopf_clicked()
{
    if(ui->lw_opf->count()==0){
        for (int i = 0; i < ui->lw_ipf->count(); ++i) {
            QFileInfo ipfitem(ui->lw_ipf->item(i)->text());
            QString opfitem=ipfitem.path()+"/"+ipfitem.baseName()+"."+ui->cbb_format->currentText();
            ui->lw_opf->addItem(opfitem);
        }
    }
}

void MainWindow::on_lw_opf_itemDoubleClicked(QListWidgetItem *item)
{
    reName s(item->text());
    if(s.exec()==QDialog::Accepted){
        ui->lw_opf->currentItem()->setText(s.name());
    }
    //test 2
}


