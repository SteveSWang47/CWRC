#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btncalc_clicked()
{
    int heads = ui->headspin->value();
    int legs = ui->legspin->value();
    int ansr = 0, ansc = 0;
    if(legs % 2 != 0)
    {
        ui->rablcd->display(-1);
        ui->chicklcd->display(-1);
        return;
    }
    ansc = legs / 2;
    if(ansc < heads)
    {
        ui->rablcd->display(-1);
        ui->chicklcd->display(-1);
        return;
    }
    ansr = ansc - heads;
    ansc = (legs - 4 * ansr) / 2;
    ui->rablcd->display(ansr);
    ui->chicklcd->display(ansc);
}
