#ifndef RENAME_H
#define RENAME_H

#include <QDialog>

namespace Ui {
class reName;
}

class reName : public QDialog
{
    Q_OBJECT

public:
    explicit reName(QWidget *parent = nullptr);
    explicit reName(QString name,QWidget *parent = nullptr);
    QString name();
    ~reName();

private:
    Ui::reName *ui;
};

#endif // RENAME_H
