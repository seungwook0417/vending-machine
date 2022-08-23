#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    ~Widget();
    int money = 0;

    void changeMoney(int diff);

private slots:
    void on_pb500_clicked();

    void on_pb100_clicked();

    void on_pb50_clicked();

    void on_pb10_clicked();

    void on_pbcoffee_clicked();

    void on_pbmilk_clicked();

    void on_pbmango_clicked();

    void on_pbreset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
