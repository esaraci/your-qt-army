#include "loginwindow.h"


LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setFixedSize(250,250);
    move(500,150);
    setWindowTitle("YourQtArmy - Login");
    setStyleSheet("LoginWindow {background-image: url(:images/sfondo.jpg);}");


    txtUsername=new QLineEdit("Username", this);
    txtUsername->setGeometry(35,80,175,30);
    txtPassword=new QLineEdit("password", this);
    txtPassword->setGeometry(35,115,175,30);
    txtPassword->setEchoMode( QLineEdit::Password );
    lblLogo=new QLabel(this);
    lblLogo->setGeometry(0,0,250,60);
    lblLogo->setPixmap(QPixmap::fromImage(QImage(":images/logo.png")));
    lblAutore =new QLabel(QString("<font color='white'>Eugen Saraci - 1073559</font>"),this);
    lblAutore->setGeometry(5,230,250,15);
    lblAutore->setFont(QFont("Mono", 10));
    btnLogin = new QPushButton (tr("Log In"), this);
    btnLogin->setGeometry(35,155,175,30);
    connect(btnLogin, SIGNAL(clicked()),this,SLOT(test_login()));

}


void LoginWindow::test_login() {

    int utente;
    if ((AppManager::try_login(txtUsername->text(), txtPassword->text()))<0) {
        QMessageBox::critical(0,"Errore","Combinazione utente e password non trovata.");
    }
    else
    {
        utente=AppManager::try_login(txtUsername->text(), txtPassword->text());
        userWindow* finestra = new userWindow(utente);
        finestra->show();
        this->close();
    }
}

