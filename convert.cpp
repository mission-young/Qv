#include "convert.h"
#include <QProcess>
Convert::Convert()
{

}

Convert::Convert(QString ipf, QString opf,int threads)
{
    QProcess *process=new QProcess();
    QStringList args;
    args<<"-i"<<ipf<<opf<<"-threads"<<QString(threads);
    process->execute("/usr/locin/ffmpeg",args);
}
//Qv测试
