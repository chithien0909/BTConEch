#include "graphics.h"
#include <QPainter>
#include <QPointF>
#include <math.h>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{

    columnBaseX = 220;
    pBlFrg1 = columnBaseX * 0;
    pBlFrg2 = columnBaseX * 1;
    pBlFrg3 = columnBaseX * 2;
    pYlFrg1 = columnBaseX * 4;
    pYlFrg2 = columnBaseX * 5;
    pYlFrg3 = columnBaseX * 6;
}
void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    int r=20;
    int x = 100;

    int w = 300;
    int h = 600;
    int y = height () - h;
    painter.setRenderHint(QPainter::Antialiasing);

    QString filename3 = "D:/DHMT/EchNhay/troii.JPG";
    painter.drawPixmap(0,0,r*80,r*28,QPixmap(filename3));

    painter.setPen(Qt::NoPen);
//    painter.setBrush(QBrush("#ffffcc"));
//    painter.drawRect(0,0,1600,1600);
    painter.setBrush(QBrush("#b3f0ff"));
    painter.drawRect(0,450,1600,1600);

    QString laSenFile = "D:/DHMT/EchNhay/lasen.png";

    painter.drawPixmap(columnBaseX * 0, 530, r*10, r*8, QPixmap(laSenFile));
    painter.drawPixmap(columnBaseX * 1, 530, r*10, r*8, QPixmap(laSenFile));
    painter.drawPixmap(columnBaseX * 2, 530, r*10, r*8, QPixmap(laSenFile));
    painter.drawPixmap(columnBaseX * 3, 530, r*10, r*8, QPixmap(laSenFile));
    painter.drawPixmap(columnBaseX * 4, 530, r*10, r*8, QPixmap(laSenFile));
    painter.drawPixmap(columnBaseX * 5, 530, r*10, r*8, QPixmap(laSenFile));
    painter.drawPixmap(columnBaseX * 6, 530, r*10, r*8, QPixmap(laSenFile));

    QString echXanhFile = "D:/DHMT/EchNhay/echxanh.png";
     painter.drawPixmap(pBlFrg1, 490,r*10,r*8,QPixmap(echXanhFile));
     painter.drawPixmap(pBlFrg2, 490,r*10,r*8,QPixmap(echXanhFile));
     painter.drawPixmap(pBlFrg3, 490,r*10,r*8,QPixmap(echXanhFile));

     QString echVangFile = "D:/DHMT/EchNhay/echvang.png";
     painter.drawPixmap(pYlFrg1, 490,r*10,r*8,QPixmap(echVangFile));
     painter.drawPixmap(pYlFrg2, 490,r*10,r*8,QPixmap(echVangFile));
     painter.drawPixmap(pYlFrg3, 490,r*10,r*8,QPixmap(echVangFile));
}


QPointF graphics::tinhtien(QPointF p, double kc, int huong){
    QPointF pnew;
    pnew.setX(p.x()+kc*cos(M_PI*huong/180));
    pnew.setY(p.y()+kc*sin(M_PI*huong/180));
    return pnew;
}

QPointF graphics::tile(QPointF p, QPointF c, int sx, int sy){
    QPointF pnew;
    pnew.setX(p.x()*sx+c.x()*(1-sx));
    pnew.setY(p.y()*sy+c.y()*(1-sy));
    return pnew;
}
void graphics::Vecot (QPainter &painter, int x, int y, int w, int h){
    QPolygon veCot;
    QPoint p;
    p.setX (x);
    p.setY (y);
    QPoint diemveCot[4];
    diemveCot[0] = Translation (p, -w/10, 0);
    diemveCot[1] = Translation (p, -w/10,-h/2);
    diemveCot[2] = Translation (p, w/10, -h/2);
    diemveCot[3] = Translation (p, w/10, 0);
    for(int i = 0; i < 4; i++)
        veCot.append (diemveCot[i]);
    painter.setBrush(QBrush("#000000"));
    painter.drawPolygon (veCot);
}

QPoint graphics::Translation(QPoint p, int px, int py){
    QPoint pnew;
    pnew.setX(p.x() + px);
    pnew.setY(p.y() + py);
    return pnew;
}

/*********************************/

void graphics::blueFrog1Move1 () {
    pBlFrg1 = pBlFrg1 + columnBaseX;
    repaint();
}

void graphics::blueFrog1Move2 () {
    pBlFrg1 = pBlFrg1 + columnBaseX * 2;
    repaint();
}

void graphics::blueFrog2Move1 () {
    pBlFrg2 = pBlFrg2 + columnBaseX;
    repaint();
}

void graphics::blueFrog2Move2 () {
    pBlFrg2 = pBlFrg2 + columnBaseX * 2;
    repaint();
}


void graphics::blueFrog3Move1 () {
    pBlFrg3 = pBlFrg3 + columnBaseX;
    repaint();
}

void graphics::blueFrog3Move2 () {
    pBlFrg3 = pBlFrg3 + columnBaseX * 2;
    repaint();
}

void graphics::yellowFrog1Move1 () {
    pYlFrg1 -= columnBaseX;
    repaint();
}

void graphics::yellowFrog1Move2 () {
    pYlFrg1 -= columnBaseX * 2;
    repaint();
}

void graphics::yellowFrog2Move1 () {
    pYlFrg2 -= columnBaseX;
    repaint();
}

void graphics::yellowFrog2Move2 () {
    pYlFrg2 -= columnBaseX * 2;
    repaint();
}

void graphics::yellowFrog3Move1 () {
    pYlFrg3 -= columnBaseX;
    repaint();
}

void graphics::yellowFrog3Move2 () {
    pYlFrg3 -= columnBaseX * 2;
    repaint();
}
