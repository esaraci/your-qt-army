#include <QtXml>
#include "appmanager.h"
#include <QtCore>
#include <QString>


void AppManager::sanitize_armies (Unit* u, const QVector<Player*>& pv ) {

  for (int i=0; i!=pv.size(); i++)
      pv[i]->esercito->removeAll(u);
}

MarketList* AppManager::load_marketPlace() {

   QDomDocument documento;
   QFile file("marketplace.xml");

   if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
      {
          qDebug() << "Failed to open the file for reading.";
      }
      else
      {
          if(!documento.setContent(&file))
          {
              qDebug() << "Failed to load the file for reading.";
          }
          file.close();
      }

   QDomElement root = documento.firstChildElement();
   QDomNodeList units = root.elementsByTagName("unit");

   MarketList* marketPlace = new MarketList;

   for (int i=0; i<units.count(); i++) {
        QDomNode nodo = units.at(i);
        QDomElement unita = nodo.toElement();
        if (unita.attribute("type")=="soldier")
            marketPlace->add(new Soldier(unita.attribute("name"),unita.attribute("atk").toInt(),unita.attribute("def").toInt(),
                                         unita.attribute("gold").toInt(),unita.attribute("premium").toInt()));
        if (unita.attribute("type")=="veichle")
            marketPlace->add(new Veichle(unita.attribute("name"),unita.attribute("atk").toInt(),unita.attribute("def").toInt(),
                                         unita.attribute("gold").toInt(),unita.attribute("premium").toInt()));

        //altri if in base al tipo
   }

   return marketPlace;
}

MarketList* AppManager::mp = AppManager::load_marketPlace();


Army* AppManager::load_esercito(const QDomNodeList& nodi_unita) {

    Army* esercito = new Army;

    if (nodi_unita.isEmpty())
        return new Army();

    for (int i=0; i<nodi_unita.count(); i++) {
         QDomNode nodo = nodi_unita.at(i);
         QDomElement unita = nodo.toElement();
         if (unita.attribute("type")=="soldier")
             esercito->add(new Soldier(unita.attribute("name"),unita.attribute("atk").toInt(),unita.attribute("def").toInt(),
                                       unita.attribute("gold").toInt(),unita.attribute("premium").toInt()));

         if (unita.attribute("type")=="veichle")
             esercito->add(new Veichle(unita.attribute("name"),unita.attribute("atk").toInt(),unita.attribute("def").toInt(),
                                          unita.attribute("gold").toInt(),unita.attribute("premium").toInt()));
    }

    return esercito;
}

QVector<Player*> AppManager::load_players() {

   QDomDocument documento;
   QFile file("players.xml");

   if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
      {
          qDebug() << "Failed to open the file for reading.";
      }
      else
      {
          if(!documento.setContent(&file))
          {
              qDebug() << "Failed to load the file for reading.";
          }
          file.close();
      }

   QDomElement root = documento.firstChildElement();
   QDomNodeList players = root.elementsByTagName("player");

   QVector<Player*> pc;

   for (int i=0; i<players.count(); i++) {
        QDomNode nodo = players.at(i);
        QDomElement giocatore = nodo.toElement();

        (nodo.firstChild()).childNodes();

        if (giocatore.attribute("type")=="free")
            pc.push_back(new FreePlayer(giocatore.attribute("name"),giocatore.attribute("password"),giocatore.attribute("gold").toInt(),
                                        giocatore.attribute("vinte").toInt(), giocatore.attribute("perse").toInt(),
                                        load_esercito((nodo.firstChild()).childNodes())));

        else if(giocatore.attribute("type")=="premium")
            pc.push_back(new PremiumPlayer(giocatore.attribute("name"),giocatore.attribute("password"),giocatore.attribute("gold").toInt(),
                                           giocatore.attribute("vinte").toInt(), giocatore.attribute("perse").toInt(),
                                           load_esercito((nodo.firstChild()).childNodes())));

   }

   return pc;
}

QVector<Player*> AppManager::pv = load_players();


void AppManager::save_marketPlace(MarketList * mp) const {


    QFile file("marketplace.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           qDebug() << "Failed to open the file.";
       }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument("1.0");
    writer.writeStartElement("marketplace");

    if (!(mp->isEmpty()))
    for (MarketList::Iterator it=mp->begin(); it!=mp->end(); ++it) {

        writer.writeStartElement("unit");
        if (dynamic_cast<Soldier*>((*mp)[it]->unitPtr))
            writer.writeAttribute("type","soldier");

        else if (dynamic_cast<Veichle*>((*mp)[it]->unitPtr))
             writer.writeAttribute("type","veichle");
        //else if (dynamic_cast<*>((*mp)[it]->unitPtr))
             //writer.writeAttribute("type","soldier");

             QString attacco  = QString::number((*mp)[it]->unitPtr->atk);
             QString difesa  = QString::number((*mp)[it]->unitPtr->def);
             QString prezzo  = QString::number((*mp)[it]->unitPtr->price);
             QString premium  = QString::number((*mp)[it]->unitPtr->premium);

             writer.writeAttribute("name",(*mp)[it]->unitPtr->name);
             writer.writeAttribute("atk",attacco);
             writer.writeAttribute("def",difesa);
             writer.writeAttribute("gold", prezzo);
             writer.writeAttribute("premium",premium);

       writer.writeEndElement(); //unit
    }

    writer.writeEndElement(); //marketplace
    writer.writeEndDocument();
}


void AppManager::save_players(const QVector<Player*>& pv) const {


    QFile file("players.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           qDebug() << "Failed to open the file.";
       }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument("1.0");
    writer.writeStartElement("players");

    for (int i=0; i<pv.size();i++) {

        writer.writeStartElement("player");
        if (dynamic_cast<FreePlayer*>(pv[i]))
            writer.writeAttribute("type","free");

        if (dynamic_cast<PremiumPlayer*>(pv[i]))
            writer.writeAttribute("type","premium");

        //if (dynamic_cast<FreePlayer*>(pv[i]))
        //writer.writeAttribute("type","premium");


             QString oro  = QString::number(pv[i]->gold);
             QString vinte  = QString::number(pv[i]->m_won);
             QString perse  = QString::number(pv[i]->m_lost);

             writer.writeAttribute("name",pv[i]->Username());
             writer.writeAttribute("password", pv[i]->Password());
             writer.writeAttribute("gold", oro);
             writer.writeAttribute("vinte", vinte);
             writer.writeAttribute("perse", perse);

             writer.writeStartElement("esercito");


             Army* es;

             if (pv[i]->esercito && !(pv[i]->esercito->isEmpty())) {
                 es=pv[i]->esercito;
                for (MarketList::Iterator it=es->begin(); it!=es->end(); ++it) {

                 writer.writeStartElement("unit");
                 if (dynamic_cast<Soldier*>((*es)[it]->unitPtr))
                     writer.writeAttribute("type","soldier");

                 else if (dynamic_cast<Veichle*>((*es)[it]->unitPtr))
                      writer.writeAttribute("type","veichle");

                      QString attacco  = QString::number((*es)[it]->unitPtr->atk);
                      QString difesa  = QString::number((*es)[it]->unitPtr->def);
                      QString prezzo  = QString::number((*es)[it]->unitPtr->price);
                      QString premium  = QString::number((*es)[it]->unitPtr->premium);

                      writer.writeAttribute("name",(*es)[it]->unitPtr->name);
                      writer.writeAttribute("atk",attacco);
                      writer.writeAttribute("def",difesa);
                      writer.writeAttribute("gold", prezzo);
                      writer.writeAttribute("premium",premium);

                writer.writeEndElement(); //unit
                }
             }

       writer.writeEndElement(); //esercito

       writer.writeEndElement(); //player
    }


    writer.writeEndElement(); //players

    writer.writeEndDocument();
}

int AppManager::try_login(QString user, QString pwd) {

    int i=0;
    bool trovato = false;

    while(i<pv.size() && !trovato) {
        if(pv[i]->Username()==user && pv[i]->Password()==pwd)
            trovato=true;
        i++;
    }
    if (!trovato) return -1;

    return i-1;

}

