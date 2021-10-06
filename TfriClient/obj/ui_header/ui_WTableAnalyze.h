/********************************************************************************
** Form generated from reading UI file 'WTableAnalyze.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WTABLEANALYZE_H
#define UI_WTABLEANALYZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WTableAnalyze
{
public:
    QGridLayout *gridLayout;
    QWidget *wBg;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QWidget *wColorArea;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnTest;
    QPushButton *btnOutput;
    QPushButton *btnUpload;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *sbCount;
    QPushButton *btnChangeCount;
    QLabel *label_3;
    QLabel *lbTotalCount;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPrePage;
    QSpinBox *sbNowPage;
    QLabel *label;
    QLabel *lbTotalPage;
    QPushButton *btnNextPage;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *WTableAnalyze)
    {
        if (WTableAnalyze->objectName().isEmpty())
            WTableAnalyze->setObjectName(QString::fromUtf8("WTableAnalyze"));
        WTableAnalyze->resize(1207, 445);
        QFont font;
        font.setPointSize(14);
        WTableAnalyze->setFont(font);
        gridLayout = new QGridLayout(WTableAnalyze);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        wBg = new QWidget(WTableAnalyze);
        wBg->setObjectName(QString::fromUtf8("wBg"));
        QFont font1;
        font1.setPointSize(12);
        wBg->setFont(font1);
        gridLayout_2 = new QGridLayout(wBg);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget = new QTableWidget(wBg);
        if (tableWidget->columnCount() < 21)
            tableWidget->setColumnCount(21);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(20, __qtablewidgetitem20);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(40);

        gridLayout_2->addWidget(tableWidget, 2, 0, 1, 1);

        wColorArea = new QWidget(wBg);
        wColorArea->setObjectName(QString::fromUtf8("wColorArea"));
        wColorArea->setMinimumSize(QSize(0, 20));
        wColorArea->setMaximumSize(QSize(16777215, 20));

        gridLayout_2->addWidget(wColorArea, 1, 0, 1, 1);

        widget_2 = new QWidget(wBg);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 30));
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer = new QSpacerItem(925, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        btnTest = new QPushButton(widget_7);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));

        horizontalLayout_5->addWidget(btnTest);

        btnOutput = new QPushButton(widget_7);
        btnOutput->setObjectName(QString::fromUtf8("btnOutput"));

        horizontalLayout_5->addWidget(btnOutput);

        btnUpload = new QPushButton(widget_7);
        btnUpload->setObjectName(QString::fromUtf8("btnUpload"));

        horizontalLayout_5->addWidget(btnUpload);


        horizontalLayout_6->addWidget(widget_7);


        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);


        gridLayout->addWidget(wBg, 0, 0, 1, 1);

        widget_3 = new QWidget(WTableAnalyze);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 60));
        widget_3->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        widget_5->setMinimumSize(QSize(200, 0));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sbCount = new QSpinBox(widget_5);
        sbCount->setObjectName(QString::fromUtf8("sbCount"));
        sbCount->setMinimum(10);
        sbCount->setMaximum(1000);
        sbCount->setValue(50);

        horizontalLayout_3->addWidget(sbCount);

        btnChangeCount = new QPushButton(widget_5);
        btnChangeCount->setObjectName(QString::fromUtf8("btnChangeCount"));
        btnChangeCount->setMinimumSize(QSize(110, 0));
        btnChangeCount->setFont(font1);

        horizontalLayout_3->addWidget(btnChangeCount);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lbTotalCount = new QLabel(widget_5);
        lbTotalCount->setObjectName(QString::fromUtf8("lbTotalCount"));
        lbTotalCount->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(lbTotalCount);

        horizontalSpacer_2 = new QSpacerItem(212, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        horizontalLayout_2->addWidget(widget_5);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        btnPrePage = new QPushButton(widget_4);
        btnPrePage->setObjectName(QString::fromUtf8("btnPrePage"));
        btnPrePage->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(btnPrePage);

        sbNowPage = new QSpinBox(widget_4);
        sbNowPage->setObjectName(QString::fromUtf8("sbNowPage"));
        sbNowPage->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbNowPage->setMinimum(1);
        sbNowPage->setMaximum(9999);
        sbNowPage->setValue(1);

        horizontalLayout->addWidget(sbNowPage);

        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        lbTotalPage = new QLabel(widget_4);
        lbTotalPage->setObjectName(QString::fromUtf8("lbTotalPage"));
        lbTotalPage->setMinimumSize(QSize(60, 0));
        lbTotalPage->setMaximumSize(QSize(60, 16777215));
        lbTotalPage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lbTotalPage);

        btnNextPage = new QPushButton(widget_4);
        btnNextPage->setObjectName(QString::fromUtf8("btnNextPage"));
        btnNextPage->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(btnNextPage);


        horizontalLayout_2->addWidget(widget_4);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        sizePolicy.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy);
        widget_6->setMinimumSize(QSize(200, 0));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        horizontalLayout_2->addWidget(widget_6);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        gridLayout->addWidget(widget_3, 1, 0, 1, 1);


        retranslateUi(WTableAnalyze);

        QMetaObject::connectSlotsByName(WTableAnalyze);
    } // setupUi

    void retranslateUi(QWidget *WTableAnalyze)
    {
        WTableAnalyze->setWindowTitle(QCoreApplication::translate("WTableAnalyze", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WTableAnalyze", "Sid", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WTableAnalyze", "FileName", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WTableAnalyze", "User", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WTableAnalyze", "Building", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WTableAnalyze", "Bicyclist", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WTableAnalyze", "Car  ", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WTableAnalyze", "Fence", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WTableAnalyze", "Pavement", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WTableAnalyze", "Pedestrian", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WTableAnalyze", "Pole", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("WTableAnalyze", "Road", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("WTableAnalyze", "Road Marking", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("WTableAnalyze", "Sky  ", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("WTableAnalyze", "SignSymbol", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("WTableAnalyze", "Tree", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("WTableAnalyze", "Unlabelled", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("WTableAnalyze", "Timer  ", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("WTableAnalyze", "Result", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("WTableAnalyze", "CreateTime", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("WTableAnalyze", "UpdateTime", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(20);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("WTableAnalyze", "Picture", nullptr));
        btnTest->setText(QCoreApplication::translate("WTableAnalyze", "TEST", nullptr));
        btnOutput->setText(QCoreApplication::translate("WTableAnalyze", "\345\214\257\345\207\272", nullptr));
        btnUpload->setText(QCoreApplication::translate("WTableAnalyze", "\344\270\212\345\202\263\345\234\226\347\211\207", nullptr));
        btnChangeCount->setText(QCoreApplication::translate("WTableAnalyze", "\350\256\212\346\233\264\345\226\256\351\240\201\347\255\206\346\225\270", nullptr));
        label_3->setText(QCoreApplication::translate("WTableAnalyze", "\350\263\207\346\226\231\347\270\275\346\225\270:", nullptr));
        lbTotalCount->setText(QString());
        btnPrePage->setText(QCoreApplication::translate("WTableAnalyze", "<", nullptr));
        label->setText(QCoreApplication::translate("WTableAnalyze", "/", nullptr));
        lbTotalPage->setText(QCoreApplication::translate("WTableAnalyze", "1", nullptr));
        btnNextPage->setText(QCoreApplication::translate("WTableAnalyze", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WTableAnalyze: public Ui_WTableAnalyze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WTABLEANALYZE_H
