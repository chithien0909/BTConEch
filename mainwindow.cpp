#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    blueFrog1Move1();

        if(true){
            switch (1) {
                case 1:
                    ui->widget->graphics::blueFrog1Move1();
                    break;
                case 2:
                    ui->widget->graphics::blueFrog1Move2();
                    break;
                case 3:
                    ui->widget->graphics::blueFrog2Move1();
                    break;
                case 4:
                    ui->widget->graphics::blueFrog2Move2();
                    break;
                case 5:
                    ui->widget->graphics::blueFrog3Move1();
                    break;
                case 6:
                    ui->widget->graphics::blueFrog3Move2();
                    break;
                case 7:
                    ui->widget->graphics::yellowFrog1Move1();
                    break;
                case 8:
                    ui->widget->graphics::yellowFrog1Move2();
                    break;
                case 9:
                    ui->widget->graphics::yellowFrog2Move1();
                    break;
                case 10:
                    ui->widget->graphics::yellowFrog2Move2();
                    break;
                case 11:
                    ui->widget->graphics::yellowFrog3Move1();
                    break;
                case 12:
                     ui->widget->graphics::yellowFrog3Move2();
                    break;
                default: break;
            }

        }

//    this->
}
