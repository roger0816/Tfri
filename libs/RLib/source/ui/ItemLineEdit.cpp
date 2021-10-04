#include "ItemLineEdit.h"

ItemLineEdit::ItemLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void ItemLineEdit::mousePressEvent(QMouseEvent *)
{
    if(!isReadOnly())
        LayerKeyborad::Instance()->setBinding(this);

}
