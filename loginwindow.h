#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "appmanager.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <userwindow.h>


class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);

private:

    QLineEdit* txtUsername;
    QLineEdit* txtPassword;
    QPushButton* btnLogin;
    QLabel* lblLogo;
    QLabel* lblAutore;


public slots:
    void test_login();

signals:

};

#endif // LOGINWINDOW_H
