#include "rename.h"
#include "ui_rename.h"

reName::reName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reName)
{
    ui->setupUi(this);
}

reName::reName(QString name, QWidget *parent):
    QDialog(parent),
    ui(new Ui::reName)
{
    ui->setupUi(this);
    ui->le_rename->setText(name);
}

QString reName::name()
{
    return ui->le_rename->text();
}

reName::~reName()
{
    delete ui;
}
