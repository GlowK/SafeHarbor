#include "LoginWindow.h"
#include "ui_loginwindow.h"
#include "Authentication.h"
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
    if( Authentication::areCredentialsCorrect(ui->lineEditUsername->text(), ui->lineEditPassword->text()) )
    {
        //ToDo: Open main screen of application.
        QMessageBox::information(this, "Success", "You are logged in!");
    }
    else
    {
        //ToDo: Show message about incorrect credentials.
        QMessageBox::information(this, "Failure", "Error!");
    }
}
