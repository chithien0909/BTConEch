#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void drawWindmill(QPainter &painter);
    double h=height();
    double w=width();
//    void timerEvent(QTimerEvent *);
//    double position;
//    double timerId;
    void blueFrog1Move1();
    void blueFrog1Move2();
    void blueFrog2Move1();
    void blueFrog2Move2();
    void blueFrog3Move1();
    void blueFrog3Move2();

    void yellowFrog1Move1();
    void yellowFrog1Move2();
    void yellowFrog2Move1();
    void yellowFrog2Move2();
    void yellowFrog3Move1();
    void yellowFrog3Move2();
    QPointF pstart,pstart1, pstart2, pstart3, pcenter, pnew, pnew1, pnew2, pnew3;
    int angle;
    QPointF quay(QPointF p, QPointF c, int deta);
    QPointF tinhtien(QPointF p, double kc, int huong);
    QPointF tile(QPointF p, QPointF c, int sx, int sy);
    QPoint Translation(QPoint p, int px, int py);
    void Vecot (QPainter &painter, int x, int y, int w, int h);

    int columnBaseX;
    int pBlFrg1;
    int pBlFrg2;
    int pBlFrg3;
    int pYlFrg1;
    int pYlFrg2;
    int pYlFrg3;

signals:

public slots:
};

#endif // GRAPHICS_H
