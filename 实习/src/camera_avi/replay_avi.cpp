#include "replay_avi.h"

replay_avi::replay_avi()
{
    frame=0;
}

void replay_avi::open(char* name)
{
    avifile=AVI_open_input_file(name,1);
    frames=AVI_video_frames(avifile);
    frame_width=AVI_video_width(avifile);
    frame_height=AVI_video_height(avifile);
    frame_rate=AVI_frame_rate(avifile);
}

QPixmap replay_avi::read(int locate)
{
    int iskeyframe;
    if(locate>=frames)
        frame=frames-1;
    else
        frame=locate;
    QPixmap map;
    QByteArray ba;
    QBuffer bf(&ba);
    char *rawdata;
    int datasize=AVI_frame_size(avifile,frame);
    rawdata=(char*)malloc(sizeof(char)*datasize);
    AVI_set_video_position(avifile,frame);
    AVI_read_frame(avifile,rawdata,&iskeyframe);
    bf.setData(rawdata,datasize);
    map.loadFromData(ba);
    return map;
}

void replay_avi::close()
{
    AVI_close(avifile);
}
