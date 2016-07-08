#include "userwindow.h"

userWindow::userWindow(int p, QWidget *parent) : QMainWindow(parent), utenteLoggato(p)
{

    setFixedSize(670, 515);
    move(300,150);
    setWindowTitle("YourQtArmy");
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    groupBox_profilo = new QGroupBox(centralWidget);
    groupBox_profilo->setObjectName(QString::fromUtf8("groupBox_profilo"));
    groupBox_profilo->setGeometry(QRect(20, 10, 280, 490));
    groupBox_profilo->setTitle("Profilo");
    label = new QLabel(groupBox_profilo);
    label->setGeometry(QRect(20, 40, 71, 16));
    label->setText("Username:");
    label_2 = new QLabel(groupBox_profilo);
    label_2->setGeometry(QRect(20, 70, 31, 16));
    label_2->setText("ATK:");
    label_3 = new QLabel(groupBox_profilo);
    label_3->setGeometry(QRect(150, 70, 31, 16));
    label_3->setText("DEF:");
    label_4 = new QLabel(groupBox_profilo);
    label_4->setGeometry(QRect(150, 90, 31, 16));
    label_4->setText("Gold:");
    label_5 = new QLabel(groupBox_profilo);
    label_5->setGeometry(QRect(20, 90, 52, 15));
    label_5->setText("Tipo:");
    label_6 = new QLabel(groupBox_profilo);
    label_6->setGeometry(QRect(20, 110, 41, 16));
    label_6->setText("Vinte:");
    label_7 = new QLabel(groupBox_profilo);
    label_7->setGeometry(QRect(155, 110, 52, 15));
    label_7->setText("Perse:");
    lblUsername = new QLabel(groupBox_profilo);
    lblUsername->setGeometry(QRect(120, 40, 141, 16));
    lblATK = new QLabel(groupBox_profilo);
    lblATK->setGeometry(QRect(60, 70, 52, 15));
    lblDEF = new QLabel(groupBox_profilo);
    lblDEF->setGeometry(QRect(190, 70, 52, 15));
    lblTipo = new QLabel(groupBox_profilo);
    lblTipo->setGeometry(QRect(60, 90, 61, 16));
    lblGold = new QLabel(groupBox_profilo);
    lblGold->setGeometry(QRect(190, 90, 61, 16));
    lblVinte = new QLabel(groupBox_profilo);
    lblVinte->setGeometry(QRect(60, 112, 52, 15));
    lblPerse = new QLabel(groupBox_profilo);
    lblPerse->setGeometry(QRect(200, 110, 52, 15));
    label_9 = new QLabel(groupBox_profilo);
    label_9->setGeometry(QRect(10, 150, 150, 16));
    label_9->setText("<b>Il mio esercito:</b>");
    tableArmy = new QTableWidget(0,5,groupBox_profilo);
    QStringList armyHeaders;
    armyHeaders << "Nome" << "ATK" << "DEF" << "Valore" <<"Tipo";
    tableArmy->setHorizontalHeaderLabels(armyHeaders);
    tableArmy->setGeometry(QRect(10, 170, 260, 270));
    tableArmy->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableArmy->setAlternatingRowColors(true);
    tableArmy->verticalHeader()->hide();
    tableArmy->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableArmy->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    btnVendi = new QPushButton(groupBox_profilo);
    btnVendi->setGeometry(QRect(10, 450, 260, 27));
    btnVendi->setText("Vendi");
    btnVendi->setEnabled(false);


    groupBox_nemici = new QGroupBox(centralWidget);
    groupBox_nemici->setGeometry(QRect(330, 10, 321, 241));
    groupBox_nemici->setTitle("Nemici");
    tablePlayers = new QTableWidget(0,3,groupBox_nemici);
    QStringList playerHeaders;
    playerHeaders << "Nome" << "Vinte" << "Perse";
    tablePlayers->setHorizontalHeaderLabels(playerHeaders);
    tablePlayers->setGeometry(QRect(10, 30, 301, 161));
    tablePlayers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tablePlayers->setAlternatingRowColors(true);
    tablePlayers->verticalHeader()->hide();
    tablePlayers->setSelectionBehavior(QAbstractItemView::SelectRows);
    tablePlayers->horizontalHeader()->setStretchLastSection(true);
    tablePlayers->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    btnAttacca = new QPushButton(groupBox_nemici);
    btnAttacca->setGeometry(QRect(10, 200, 301, 27));
    btnAttacca->setText("Attacca");
    btnAttacca->setEnabled(false);

    groupBox_marketPlace = new QGroupBox(centralWidget);
    groupBox_marketPlace->setGeometry(QRect(330, 260, 321, 241));
    groupBox_marketPlace->setTitle("Marketplace");
    tableMarketPlace = new QTableWidget(0,5,groupBox_marketPlace);
    QStringList marketHeaders;
    marketHeaders << "Nome" << "ATK" << "DEF" << "Prezzo"<< "Tipo";
    tableMarketPlace->setHorizontalHeaderLabels(marketHeaders);
    tableMarketPlace->setGeometry(QRect(10, 30, 301, 161));
    tableMarketPlace->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableMarketPlace->setAlternatingRowColors(true);
    tableMarketPlace->verticalHeader()->hide();
    tableMarketPlace->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableMarketPlace->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);


    btnCompra = new QPushButton(groupBox_marketPlace);
    btnCompra->setGeometry(QRect(10, 200, 301, 27));
    btnCompra->setText("Compra");
    btnCompra->setEnabled(false);

    connect(tableArmy, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(tableArmyClicked()));
    connect(tablePlayers, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(tablePlayersClicked()));
    connect(tableMarketPlace, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(tableMarketPlaceClicked()));
    connect(btnVendi, SIGNAL(clicked()), this, SLOT(vendi()));
    connect(btnAttacca, SIGNAL(clicked()), this, SLOT(fight()));
    connect(btnCompra, SIGNAL(clicked()), this, SLOT(compra()));
    connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(salva()));

    updateUserProfile();
    updatePlayers();
    updateMarketPlace();
}

void userWindow::updateUserProfile() {
    lblUsername->setText(AppManager::pv[utenteLoggato]->Username());
    lblATK->setText(QString::number(AppManager::pv[utenteLoggato]->getATK()));
    lblDEF->setText(QString::number(AppManager::pv[utenteLoggato]->getDEF()));
    lblGold->setText(QString::number(AppManager::pv[utenteLoggato]->getGOLD()));
    lblVinte->setText(QString::number(AppManager::pv[utenteLoggato]->getM_WON()));
    lblPerse->setText(QString::number(AppManager::pv[utenteLoggato]->getM_LOST()));

    if(dynamic_cast<FreePlayer*>(AppManager::pv[utenteLoggato]))
        lblTipo->setText("Free");
    else if(dynamic_cast<PremiumPlayer*>(AppManager::pv[utenteLoggato]))
        lblTipo->setText("Premium");



    tableArmy->setRowCount(0);
    int c=tableArmy->rowCount();

    if (!AppManager::pv[utenteLoggato]->cloneArmy().isEmpty()){
        for (Army::Iterator it=AppManager::pv[utenteLoggato]->cloneArmy().begin(); it!=AppManager::pv[utenteLoggato]->cloneArmy().end(); ++it ) {

            tableArmy->insertRow(c);
            tableArmy->setItem(c,0,new QTableWidgetItem(AppManager::pv[utenteLoggato]->cloneArmy()[it]->unitPtr->getName()));
            tableArmy->setItem(c,1,new QTableWidgetItem(QString::number(AppManager::pv[utenteLoggato]->cloneArmy()[it]->unitPtr->ATK())));
            tableArmy->setItem(c,2,new QTableWidgetItem(QString::number(AppManager::pv[utenteLoggato]->cloneArmy()[it]->unitPtr->DEF())));

            if(dynamic_cast<FreePlayer*>(AppManager::pv[utenteLoggato]))
                tableArmy->setItem(c,3,new QTableWidgetItem(QString::number(AppManager::pv[utenteLoggato]->cloneArmy()[it]->unitPtr->getPrice()/2)));
            else if(dynamic_cast<PremiumPlayer*>(AppManager::pv[utenteLoggato]))
                tableArmy->setItem(c,3,new QTableWidgetItem(QString::number(static_cast<int>(AppManager::pv[utenteLoggato]->cloneArmy()[it]->unitPtr->getPrice()/PremiumPlayer::premiumMultiplier))));

            if (!AppManager::pv[utenteLoggato]->cloneArmy()[it]->unitPtr->isPremium())
                tableArmy->setItem(c,4,new QTableWidgetItem("Free"));
            else if (AppManager::pv[utenteLoggato]->cloneArmy()[it]->unitPtr->isPremium())
                tableArmy->setItem(c,4,new QTableWidgetItem("Premium"));
        }

    }
}


void userWindow::updatePlayers() {

    tablePlayers->setRowCount(0);
    int c=tablePlayers->rowCount();

    for (int i=0; i<AppManager::pv.size(); i++) {
        tablePlayers->insertRow(c);
        tablePlayers->setItem(c,0,new QTableWidgetItem(AppManager::pv[i]->Username()));
        tablePlayers->setItem(c,1,new QTableWidgetItem(QString::number(AppManager::pv[i]->getM_WON())));
        tablePlayers->setItem(c,2,new QTableWidgetItem(QString::number(AppManager::pv[i]->getM_LOST())));
    }
}

void userWindow::updateMarketPlace() {

    tableMarketPlace->setRowCount(0);
    int c=tableMarketPlace->rowCount();

    if (!AppManager::mp->isEmpty()) {

      for(MarketList::Iterator it=AppManager::mp->begin(); it!=AppManager::mp->end(); ++it) {

        tableMarketPlace->insertRow(c);
        tableMarketPlace->setItem(c,0,new QTableWidgetItem((*AppManager::mp)[it]->unitPtr->getName()));
        tableMarketPlace->setItem(c,1,new QTableWidgetItem(QString::number((*AppManager::mp)[it]->unitPtr->ATK())));
        tableMarketPlace->setItem(c,2,new QTableWidgetItem(QString::number((*AppManager::mp)[it]->unitPtr->DEF())));
        tableMarketPlace->setItem(c,3,new QTableWidgetItem(QString::number((*AppManager::mp)[it]->unitPtr->getPrice())));

        if (!(*AppManager::mp)[it]->unitPtr->isPremium())
            tableMarketPlace->setItem(c,4,new QTableWidgetItem("Free"));
        else if ((*AppManager::mp)[it]->unitPtr->isPremium())
            tableMarketPlace->setItem(c,4,new QTableWidgetItem("Premium"));
    }
    }
}

void userWindow::tableArmyClicked() {
    btnVendi->setEnabled(true);
}

void userWindow::tableMarketPlaceClicked() {
    btnCompra->setEnabled(true);
}

void userWindow::tablePlayersClicked() {
    btnAttacca->setEnabled(true);

    //se per caso un utente dovesse attaccare se stesso il risultato sarebbe un pareggio senza cambiamento in nessun dato.
    //per sensatezza blocco la possibiltà.
    if (tablePlayers->item(tablePlayers->currentRow(),0)->text() == AppManager::pv[utenteLoggato]->Username())
        btnAttacca->setEnabled(false);

}

void userWindow::vendi() {
    AppManager::pv[utenteLoggato]->sell(tableArmy->item(tableArmy->currentRow(),0)->text());
    btnVendi->setEnabled(false);
    updateUserProfile();
}

void userWindow::fight() {
    BattleManager BM;
    Player* winner = BM.fight(AppManager::pv[utenteLoggato]->Username(), tablePlayers->item(tablePlayers->currentRow(),0)->text());
    if (!winner)
        QMessageBox::information(0,"Pareggio","Pareggio! Non hai gaudagnato o perso nulla.");
    else if (winner->Username()==AppManager::pv[utenteLoggato]->Username())
        QMessageBox::information(0,"Vittoria","Vittoria! Complimenti, hai vinto lo scontro.");
    else
        QMessageBox::warning(0,"Sconfitta","Sconfitta! Peccato, hai perso lo scontro.");

    btnAttacca->setEnabled(false);
    updatePlayers();
    updateUserProfile();
}

void userWindow::compra() {
    if (!dynamic_cast<PremiumPlayer*>(AppManager::pv[utenteLoggato]) && (tableMarketPlace->item(tableMarketPlace->currentRow(),4)->text()=="Premium"))
        QMessageBox::warning(0,"Errore","L'unità che stai cercando di comprare è dedicata ai giocatori Premium.");

    if (tableMarketPlace->item(tableMarketPlace->currentRow(),3)->text().toInt() > AppManager::pv[utenteLoggato]->getGOLD())
        QMessageBox::warning(0,"Errore","Non hai abbastanza soldi per comprare questa unità. Attacca gli altri giocatori per ottenere denaro.");

    //esegue comunque, è già previsto nel codice che un utente normale non possa comprare un certo tipo di unità
    //o che non abbia abbastanza soldi per comprare una certa unità, mostro le messagebox per far capire all'utente
    //perchè non succede nulla.
    AppManager::pv[utenteLoggato]->buy(tableMarketPlace->item(tableMarketPlace->currentRow(),0)->text());
    btnVendi->setEnabled(false);
    updateUserProfile();
}

void userWindow::salva() {
    AppManager AM;
    AM.save_marketPlace(AppManager::mp);
    AM.save_players(AppManager::pv);
}




