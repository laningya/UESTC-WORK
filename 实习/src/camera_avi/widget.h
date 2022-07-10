#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "videodevice.h"
#include "QPixmap"
#include "QImage"
#include "QTimer"
#include "QDateTime"
#include "my_avi.h"
#include "replay_avi.h"

#include <QPaintEvent>
#include <QUdpSocket>
#include <QHostAddress>
#include <QBuffer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *event);
    void yuyv422_to_rgb888(unsigned char *yuyvdata, unsigned char *rgbdata, int w, int h);

private slots:
    void on_record_clicked();

    void on_stop_clicked();

    void on_replay_clicked();

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::Widget *ui;

    int lcd_height;
    int lcd_width;
    int lcd_rgb_bpp;

    QPixmap *pix;

    QString cam_name;
    VideoDevice *cam_vd;
    int ret;

    QString camera_video_fmt;
    int camera_video_width;
    int camera_video_height;
    int camera_video_bpp;

    uchar *camera_buff_raw;
    uchar *camera_buff_rgb888;
    size_t frame_len;
    QImage *image;
    QTimer *timer;

    int fps;
    QDateTime curdatetime;
    QDateTime predatetime;

    int savecont;
    int replaycont;
    bool save_en;
    bool replay_en;
    int save_v;
    int replay_v;

    my_avi avi;
    replay_avi re_avi;
    QPixmap *re_pix;
    double re_frame;

    QUdpSocket *udpSocketSrv;
    QHostAddress ip;
    quint16 port;
    QImage *img;
    QImage tmp_img;
};
#endif // WIDGET_H
