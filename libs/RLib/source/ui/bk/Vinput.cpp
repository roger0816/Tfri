#include "Vinput.h"
#include "ui_Vinput.h"
#include "Vkeybord.h"


static QPoint kPoint;

static QSize kSize;

Vinput::Vinput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vinput)
{
    ui->setupUi(this);
    setObjectName("Vinput");
    ui->wBg->setStyleSheet("background-color:rgba(193,193,193,40)");
}

Vinput::~Vinput()
{
    delete ui;
}

void Vinput::setAlignment(Qt::Alignment alignment)
{
    ui->label->setAlignment(alignment);
}

void Vinput::setKeyboardSize(QSize size)
{
    kSize = size;
}

void Vinput::setKeyboardPos(QPoint point)
{
    kPoint = point;
}

void Vinput::setKeyboardFont(QFont font)
{
    Vkeybord *keybord= &Vkeybord::Instance();
    keybord->setFontSize(font);
}

QString Vinput::text()
{
    return ui->label->text();
}

void Vinput::mouseReleaseEvent(QMouseEvent *)
{
    // GLOBAL().callKeybord(ui->label);

    Vkeybord *keybord= &Vkeybord::Instance();

    keybord->setParent(dynamic_cast<QWidget*>(this->parent()));

    keybord->resize(kSize);

    keybord->move(kPoint);

    keybord->raise();

    keybord->slotOpenKeyBord(ui->label);

}

void Vinput::setText(const QString &text)
{
    ui->label->setText(text);
}

QLabel* Vinput::label()
{
    return ui->label;
}
