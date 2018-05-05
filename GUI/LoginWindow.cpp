#include "LoginWindow.h"
#include "AdminPanel.h"
#include "ClientPanel.h"
#include "ManagerPanel.h"
#include "ui_loginwindow.h"
#include "../AuxClass/Authentication.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_buttonLogin_clicked()
{

    switch(Authentication::checkCredentials(ui->lineEditUsername->text(), ui->lineEditPassword->text()))
    {
        case Authentication::VALID_ADMIN:
        {
            this->hide();
            AdminPanel adminPanel;
            adminPanel.setModal(true);
            adminPanel.exec();
            ui->lineEditUsername->clear();
            ui->lineEditPassword->clear();
            this->show();
            break;
        }
        case Authentication::VALID_CLIENT:
        {
            this->hide();
            ClientPanel clientPanel;
            clientPanel.setModal(true);
            clientPanel.exec();
            ui->lineEditUsername->clear();
            ui->lineEditPassword->clear();
            this->show();
            break;
        }
        case Authentication::VALID_MANGER:
        {
            this->hide();
            ManagerPanel managerPanel;
            managerPanel.setModal(true);
            managerPanel.exec();
            ui->lineEditUsername->clear();
            ui->lineEditPassword->clear();
            this->show();
            break;
        }
        case Authentication::INCORRECT_CREDENTAILS:
        {
            QMessageBox::information(this, "Authentication failed", "Incorrect user or password.");
            ui->lineEditPassword->clear();
            break;
        }

        case Authentication::ACCOUNT_INACTIVE:
        {
            QMessageBox::information(this, "Authentication failed", "Inactive account.");
            ui->lineEditPassword->clear();
            break;
        }
    }
}
