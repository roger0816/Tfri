#include "ItemKey.h"
#include "ui_ItemKey.h"

ItemKey::ItemKey(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemKey)
{
    ui->setupUi(this);

}

ItemKey::~ItemKey()
{
    delete ui;
}

void ItemKey::setListText(QStringList listText)
{
    m_listText=listText;

    if(m_listText.length()>0)
        ui->pushButton->setText(m_listText.at(0));

}

void ItemKey::setText(QString sText)
{
    ui->pushButton->setText(sText);
}

QString ItemKey::text()
{
    return ui->pushButton->text();
}

void ItemKey::setFont(const QFont &font)
{
    ui->pushButton->setFont(font);
}

void ItemKey::mouseReleaseEvent(QMouseEvent *)
{
   // emit clicked();
}

void ItemKey::on_pushButton_clicked()
{
    emit clicked();
}
