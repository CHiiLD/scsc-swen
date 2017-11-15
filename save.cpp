#include "save.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

bool Save::ToFile(QWidget* parent, QString text, QString& error, const char* codec)
{
    QString fileName = QFileDialog::getSaveFileName(parent, "데이터를 저장합니다");

    if (fileName.isEmpty())
    {
        error = "파일이름을 공백으로 저장할 수 없습니다.";
        return false;
    }

    QFile file(fileName);
    bool ret = false;
    do
    {
        if (!file.open(QIODevice::WriteOnly))
        {
            error = file.errorString();
            break;
        }
        QTextStream stream(&file);
        stream.setCodec(codec);
        stream << text;
        ret = true;
    } while(false);

    file.close();
    return ret;
}
