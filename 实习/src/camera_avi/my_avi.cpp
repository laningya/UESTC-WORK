#include "my_avi.h"

my_avi::my_avi()
{
    mode="mjpg";
    keyframe=1;
}

void my_avi::setSavePath(QString path)
{
    SavePath=path;
}

int my_avi::setFileName(QString name)
{
    char* filename=QString(SavePath+name).toUtf8().data();
    out_fd=AVI_open_output_file(filename);
    if(out_fd==NULL)
    {
        qDebug()<<"open file error";
        return -1;
    }
    return 0;
}

void my_avi::setMode(int pic_height, int pic_width, int avi_fps, int q, char *avi_mode="mjpg")
{
    height=pic_height;
    width=pic_width;
    fps=avi_fps;
    mode=avi_mode;
    quality=q;
    AVI_set_video(out_fd,height,width,fps,mode);
}

void my_avi::write(QPixmap map)
{
    QByteArray ba;
    QBuffer bf(&ba);
    if(!map.save(&bf,"jpg",quality))
    {
        qDebug()<<"save file error";
        exit(0);
    }
    if(AVI_write_frame(out_fd,ba.data(),ba.length(),keyframe)<0)
        qDebug()<<"save file error";
}

void my_avi::stopwrite()
{
    AVI_close(out_fd);
}
