#ifndef REPLAY_AVI_H
#define REPLAY_AVI_H

extern "C"
{
#include <avilib.h>
}
#include <QPixmap>
#include <QByteArray>
#include <QBuffer>
#include <QDebug>

class replay_avi
{
public:
    replay_avi();

    char *filename;
    avi_t *avifile;
    long frames;
    long frame;
    int frame_width;
    int frame_height;
    double frame_rate;

    void open(char*);
    QPixmap read(int);
    void close();
};

#endif // REPLAY_AVI_H
