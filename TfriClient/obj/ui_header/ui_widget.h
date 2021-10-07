/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "WTableAnalyze.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QWidget *wBg;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *pageLogin;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QPushButton *btnLogin;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnTestPage;
    QWidget *widget_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *txUser;
    QLabel *label_3;
    QLineEdit *txPassword;
    QLabel *lbMsg;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QWidget *pageAnalyze;
    QGridLayout *gridLayout_6;
    WTableAnalyze *widget_4;
    QWidget *pageTest;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QPushButton *btnTestBack;
    QWidget *page_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1280, 720);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        wBg = new QWidget(Widget);
        wBg->setObjectName(QString::fromUtf8("wBg"));
        QFont font;
        font.setPointSize(12);
        wBg->setFont(font);
        gridLayout_2 = new QGridLayout(wBg);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stackedWidget = new QStackedWidget(wBg);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pageLogin = new QWidget();
        pageLogin->setObjectName(QString::fromUtf8("pageLogin"));
        gridLayout_4 = new QGridLayout(pageLogin);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 3, 2, 1, 1);

        widget_3 = new QWidget(pageLogin);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnLogin = new QPushButton(widget_3);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setMaximumSize(QSize(120, 16777215));
        QFont font1;
        font1.setPointSize(16);
        btnLogin->setFont(font1);

        gridLayout_3->addWidget(btnLogin, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 0, 1, 1, 2);

        btnTestPage = new QPushButton(widget_3);
        btnTestPage->setObjectName(QString::fromUtf8("btnTestPage"));
        btnTestPage->setFont(font1);

        gridLayout_3->addWidget(btnTestPage, 3, 0, 1, 1);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        formLayout = new QFormLayout(widget_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(40, 0));
        label_2->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        txUser = new QLineEdit(widget_2);
        txUser->setObjectName(QString::fromUtf8("txUser"));
        txUser->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, txUser);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        txPassword = new QLineEdit(widget_2);
        txPassword->setObjectName(QString::fromUtf8("txPassword"));
        txPassword->setFont(font1);
        txPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, txPassword);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 3);

        lbMsg = new QLabel(widget_3);
        lbMsg->setObjectName(QString::fromUtf8("lbMsg"));
        lbMsg->setFont(font1);
        lbMsg->setStyleSheet(QString::fromUtf8("color: rgb(220, 73, 0);"));

        gridLayout_3->addWidget(lbMsg, 2, 0, 1, 3);


        gridLayout_4->addWidget(widget_3, 3, 1, 1, 1);

        label_5 = new QLabel(pageLogin);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_5, 4, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 4, 1, 1, 1);

        label_4 = new QLabel(pageLogin);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setPointSize(20);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 0, 1, 1, 1);

        label_6 = new QLabel(pageLogin);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_6, 1, 1, 1, 1);

        stackedWidget->addWidget(pageLogin);
        pageAnalyze = new QWidget();
        pageAnalyze->setObjectName(QString::fromUtf8("pageAnalyze"));
        gridLayout_6 = new QGridLayout(pageAnalyze);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        widget_4 = new WTableAnalyze(pageAnalyze);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        gridLayout_6->addWidget(widget_4, 0, 0, 1, 1);

        stackedWidget->addWidget(pageAnalyze);
        pageTest = new QWidget();
        pageTest->setObjectName(QString::fromUtf8("pageTest"));
        horizontalLayout_2 = new QHBoxLayout(pageTest);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(pageTest);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_5->addWidget(pushButton, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_5->addWidget(pushButton_2, 1, 1, 1, 1);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(9999);
        spinBox->setSingleStep(1);
        spinBox->setValue(10);

        gridLayout_5->addWidget(spinBox, 1, 3, 1, 1);

        btnTestBack = new QPushButton(widget);
        btnTestBack->setObjectName(QString::fromUtf8("btnTestBack"));

        gridLayout_5->addWidget(btnTestBack, 0, 1, 1, 1);


        horizontalLayout_2->addWidget(widget);

        stackedWidget->addWidget(pageTest);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 1, 0, 1, 1);


        gridLayout->addWidget(wBg, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnLogin->setText(QCoreApplication::translate("Widget", "\347\231\273\345\205\245", nullptr));
        btnTestPage->setText(QCoreApplication::translate("Widget", "TEST", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\270\263\350\231\237:", nullptr));
        txUser->setText(QCoreApplication::translate("Widget", "root", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\257\206\347\242\274:", nullptr));
        txPassword->setText(QCoreApplication::translate("Widget", "Aa111111", nullptr));
        lbMsg->setText(QString());
        label_5->setText(QCoreApplication::translate("Widget", "v1.0.1003", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\347\222\260\345\242\203\350\276\250\350\255\230\345\271\263\345\217\260", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "TFRI", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "decode pic", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "history", nullptr));
        btnTestBack->setText(QCoreApplication::translate("Widget", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
