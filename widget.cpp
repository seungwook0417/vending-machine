#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbcoffee->setEnabled(false);
    ui->pbmilk->setEnabled(false);
    ui->pbmango->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);

    ui->pbcoffee->setEnabled(100<=money);
    ui->pbmilk->setEnabled(300<=money);
    ui->pbmango->setEnabled(500<=money);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);

}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbcoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbmilk_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbmango_clicked()
{
    changeMoney(-500);

}

void Widget::on_pbreset_clicked()
{
    int coin[4] = {500, 100 , 50, 10};
    int result[4] = {0, 0, 0, 0};
    for(int i=0; i<4; i++)
    {
        while (coin[i] <= money)
        {
            money -= coin[i];
            result[i]++;
            if (money == 0)
                break;
        }
        
    }
    QString msg = "500원 : " + QString::number(result[0]) + "개\n" +
            "100원 : " + QString::number(result[1]) + "개\n" +
            "50원 : " + QString::number(result[2]) + "개\n" +
            "10원 : " + QString::number(result[3]) + "개\n";
    QMessageBox::information(this, "잔돈", msg);
    ui->lcdNumber->display(money);
}
