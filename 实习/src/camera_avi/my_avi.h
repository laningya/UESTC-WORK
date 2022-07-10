#ifndef MY_AVI_H
#define MY_AVI_H

extern "C"
{
#include <avilib.h>
}
#include <QDateTime>
#include <QImage>
#include <QPixmap>
#include <QBitArray>
#include <QBuffer>
#include <QString>
#include <QDebug>

class my_avi
{
public:
    my_avi();
    QString SavePath;
    avi_t *out_fd;
    int height;
    int width;
    int fps;
    char* mode;
    int keyframe;
    int quality;

    void setSavePath(QString);
    int setFileName(QString);
    void setMode(int,int,int,int,char*);
    void write(QPixmap);
    void stopwrite();
};

#endif // MY_AVI_H
