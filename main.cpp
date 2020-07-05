#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>


int main(int argc, char *argv[])
{
    // READ FILE
    FILE *f = fopen("D:/DHMT/EchNhay/echnhayquacau/input.txt", "r");
    int data[100][7];
    int i = 0;
    int j;

    while(!feof(f)) {
        for (j=0; j<7; j++) {
            int t;
            fscanf(f, "%d", &t);
//            printf("%d ---", t);
            data[i][j] = t;
        }
        i++;
    }
    for (i=0; i<15; i++) {
        for (j=0; j<7; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    QApplication a(argc, argv);
    MainWindow w;
      w.setWindowState(Qt::WindowMaximized);
    w.show();
    
    fclose(f);
    return a.exec();
}
