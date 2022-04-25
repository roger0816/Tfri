#include "DialogUser.h"
#include "ui_DialogUser.h"

DialogUser::DialogUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUser)
{
    ui->setupUi(this);

    setWindowTitle("設定");

    connect(ui->btnPassword,&QPushButton::clicked,this,&DialogUser::changePage);
    connect(ui->btnSetClass,&QPushButton::clicked,this,&DialogUser::changePage);
    connect(ui->btnEditUser,&QPushButton::clicked,this,&DialogUser::changePage);

    connect(ui->btnBack0,&QPushButton::clicked,this,&DialogUser::changePage);
    connect(ui->btnBack1,&QPushButton::clicked,this,&DialogUser::changePage);
    connect(ui->btnBack2,&QPushButton::clicked,this,&DialogUser::changePage);

    setTabOrder(ui->txtOld,ui->txtNew);

    setTabOrder(ui->txtNew,ui->txtCheck);

    setTabOrder(ui->txtCheck,ui->btnOk);

    changePage();
}

DialogUser::~DialogUser()
{
    delete ui;
}

void DialogUser::setData(QString sUser,QString sPassword, QStringList listClass)
{
    ui->lbUser->setText(sUser);

    m_sPassword = sPassword;

    m_listClass = listClass;

    ui->cbClass->clear();

    ui->cbClass->addItems(m_listClass);

    ui->btnEditUser->setEnabled(sUser.trimmed().toLower()=="root");

 //   ui->btnEditUser->hide();
}



void DialogUser::setUserList(QStringList listUser, QStringList listPass)
{
    m_listUser = listUser;

    m_listPass = listPass;

    ui->cbUser->clear();


    QStringList listTmp  = m_listUser;

    listTmp.removeOne("root");

    ui->cbUser->addItems(listTmp);

}

void DialogUser::checkData()
{
    bool bOk = false;

    if(ui->stackedWidget->currentWidget()==ui->pagePassword)
    {
        bOk = checkPass();
    }

    else if(ui->stackedWidget->currentWidget()==ui->pageClass)
    {
        bOk = checkSetClass();
    }


    ui->btnOk->setEnabled(bOk);

}

bool DialogUser::checkPass()
{
    bool bRe = false;

    bool bOldPwd = false;

    if(ui->txtOld->text().trimmed()=="")
    {
        ui->lbMsg0_0->setText("尚未輸入密碼");
    }
    else
    {
        if(ui->txtOld->text().trimmed() != m_sPassword)
        {
           ui->lbMsg0_0->setText("密碼錯誤");
        }
        else
        {
            bOldPwd = true;

            ui->lbMsg0_0->setText("");

            m_sReData = ui->txtNew->text().trimmed();
        }
    }

    bool bNewPwd = false;

    if(ui->txtNew->text().trimmed() =="")
    {
    //   ui->lbMsg0_2->setText("請輸入新密碼");
        ui->lbMsg0_1->setText("");
    }
    else if(ui->txtNew->text().trimmed().length()<4 || ui->txtNew->text().trimmed().length()>12)
    {
        ui->lbMsg0_1->setText("請設4~12位英數字");
    }
    else
    {

        ui->lbMsg0_1->setText("");
        if(ui->txtCheck->text().trimmed()!="")
        {
            if(ui->txtNew->text().trimmed()!= ui->txtCheck->text().trimmed())
            {
                  ui->lbMsg0_2->setText("新密碼不符合");
            }
            else
            {
                 ui->lbMsg0_2->setText("");
                bNewPwd = true;
            }
        }
    }

    if(bOldPwd && bNewPwd)
        bRe = true;

    return bRe;
}

bool DialogUser::checkSetClass()
{
    bool bRe = false;

    bRe = ui->txAddClass->text().trimmed().length()!=0;

    ui->btnAddClass->setEnabled(bRe);

    return bRe;
}

bool DialogUser::checkEditUser()
{
    bool bRe = false;

    return bRe;
}

void DialogUser::changePage()
{
    QPushButton *btn = dynamic_cast<QPushButton*>(sender());

    ui->btnOk->setVisible(true);

    ui->btnOk->setEnabled(false);

    if(btn==ui->btnPassword)
    {
        ui->stackedWidget->setCurrentWidget(ui->pagePassword);
    }
    else if(btn==ui->btnSetClass)
    {
        ui->stackedWidget->setCurrentWidget(ui->pageClass);
    }
    else if(btn==ui->btnEditUser)
    {
        ui->stackedWidget->setCurrentWidget(ui->pageAddUser);


    }
    else
    {
        ui->stackedWidget->setCurrentWidget(ui->page);

        ui->btnOk->setVisible(false);

    }

    checkData();


}




void DialogUser::on_txtOld_textChanged(const QString &)
{
    checkData();
}


void DialogUser::on_txtNew_textChanged(const QString &)
{
    checkData();
}


void DialogUser::on_txtCheck_textChanged(const QString &)
{
    checkData();
}


void DialogUser::on_btnCancel_clicked()
{
    done(0);
}


void DialogUser::on_btnOk_clicked()
{
    if(ui->stackedWidget->currentWidget() == ui->pagePassword)
        done(1);

    else if(ui->stackedWidget->currentWidget() == ui->pageClass)
        done(2);

    else if(ui->stackedWidget->currentWidget() == ui->pageAddUser)
        done(3);
}


void DialogUser::on_txAddClass_textChanged(const QString &)
{
    checkSetClass();
}


void DialogUser::on_btnDelClass_clicked()
{
    if(ui->cbClass->currentIndex()==0)
    {
        DialogMsg msg;

        msg.setMsg("刪除分類","預設分類不能刪除。",QStringList()<<"OK");

        msg.exec();
    }
    else
    {
        DialogMsg msg;

        msg.setMsg("刪除分類",QString("是否刪除分類 '%1' ? "),QStringList()<<"否"<<"是");


        if(msg.exec() ==1 )
        {
            m_listClass.removeOne(ui->cbClass->currentText());

            ui->cbClass->clear();

            ui->cbClass->addItems(m_listClass);

            ui->btnOk->setEnabled(true);
        }
    }
}


void DialogUser::on_btnAddClass_clicked()
{
    m_listClass.append(ui->txAddClass->text().trimmed());

    ui->cbClass->clear();

    ui->cbClass->addItems(m_listClass);

    DialogMsg msg;

    msg.setMsg("新增分類",QString("已新增分類'%1'").arg(ui->txAddClass->text()),QStringList()<<"OK");

    msg.exec();

    ui->btnOk->setEnabled(true);
}


void DialogUser::on_btnAddUser_clicked()
{
    ui->lbAddMsg->clear();

    if(ui->txAddPass->text().trimmed()=="" || ui->txAddPass_2->text().trimmed()== ""  || ui->txUser->text().trimmed()== "")
    {
        ui->lbAddMsg->setText("帳號密碼不能空白");
    }

    else if(ui->txAddPass->text().trimmed()!= ui->txAddPass_2->text())
    {
        ui->lbAddMsg->setText("密碼再確認不符合");
    }
    else
    {
        DialogMsg msg;

        msg.setMsg("新增使用者",QString("是否要新增使用者 : '%1'").arg(ui->txUser->text().trimmed()),QStringList()<<"否"<<"是");

        if(msg.exec() ==1)
        {
//            m_listUser.append(ui->txUser->text().trimmed());

//            m_listUser.append(ui->txAddPass->text().trimmed());

            m_editUser.first=ui->txUser->text().trimmed();

            m_editUser.second = ui->txAddPass->text().trimmed();

            done(4);
        }

    }

}


void DialogUser::on_btnDelUser_clicked()
{
    DialogMsg msg;

    msg.setMsg("刪除使用者",QString("是否要刪除使用者 : '%1'").arg(ui->txUser->text().trimmed()),QStringList()<<"否"<<"是");

    if(msg.exec() ==1)
    {

        m_editUser.first=ui->cbUser->currentText();

        m_editUser.second = ui->txAddPass->text().trimmed();

        done(5);
    }
}

