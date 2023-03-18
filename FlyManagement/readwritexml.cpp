#include "readwritexml.h"

ReadWriteXML::ReadWriteXML(){
    root = document.createElement("Viaggi");
    document.appendChild(root);

}

ReadWriteXML::~ReadWriteXML(){

}
void ReadWriteXML::Save(const vector<const Viaggio*>& v)
{
    clearDocument();
    if(file.fileName() == ""){
        file.setFileName(QFileDialog::getSaveFileName(nullptr, QString("Salva File"), QDir::homePath(), QString("XML (*.xml)")));
    }

    if(!file.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(nullptr,QString("Salvataggio"), QString("File non salvato"));
    }else{
        AirPartner* air;
        Ryanair* rya;
        for(vector<const Viaggio*>::const_iterator cit = v.begin(); cit != v.end(); ++cit){
            Viaggio* vi = const_cast<Viaggio*>(*cit);
            if(dynamic_cast<Ryanair*>(vi)){
                rya = static_cast<Ryanair*>(vi);
                QDomElement node = document.createElement("Ryanair");
                node.setAttribute("Cod", QString::fromStdString(rya->getCod()));
                node.setAttribute("Km", rya->getKM());
                node.setAttribute("Equipaggio", rya->getEquipaggio());
                node.setAttribute("Passeggeri", rya->getPasseggeri());
                node.setAttribute("Partenza", QString::fromStdString(rya->getPartenza()));
                node.setAttribute("Destinazione", QString::fromStdString(rya->getDestinazione()));
                node.setAttribute("Data", rya->getData().toString());
                root.appendChild(node);

            }
        }

        for(vector<const Viaggio*>::const_iterator cit = v.begin(); cit != v.end(); ++cit){
            Viaggio* vi = const_cast<Viaggio*>(*cit);
            if(dynamic_cast<AirPartner*>(vi)){
                air = static_cast<AirPartner*>(vi);
                QDomElement node = document.createElement("AirPartner");
                node.setAttribute("Cod", QString::fromStdString(air->getCod()));
                node.setAttribute("Km", air->getKM());
                node.setAttribute("Passeggeri", air->getPasseggeri());
                node.setAttribute("Partenza", QString::fromStdString(air->getPartenza()));
                node.setAttribute("Destinazione", QString::fromStdString(air->getDestinazione()));
                node.setAttribute("Data", air->getData().toString());
                node.setAttribute("Tappe", air->getTappe());
                root.appendChild(node);

                for(unsigned int i=0; i<air->Locazioni.size(); ++i){
                    QDomElement loca = document.createElement("Locazione");
                    QString n = QString::fromStdString(air->Locazioni.at(i)->getNome());
                    QString indi = QString::fromStdString(air->Locazioni.at(i)->getIndirizzo());
                    loca.setAttribute("Nome", n);
                    loca.setAttribute("Indirizzo", indi);
                    node.appendChild(loca);
                }
            }
        }

        QTextStream stream(&file);
        stream << document.toString();

    }
    file.close();
}

void ReadWriteXML::clearDocument(){
    document.clear();
    root = document.createElement("Viaggi");
    document.appendChild(root);
}

Vettore* ReadWriteXML::read(const QString& f){
    vR = new Vettore();
    if(file.fileName() != f){
        file.close();
        file.setFileName(f);
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){

    }else{

        if(!document.setContent(&file)){
            QMessageBox::warning(nullptr,QString("Caricamento Dati"), QString("Non è stato possibile carica i dati"));
        }
            file.close();
    }
    QDomElement root = document.firstChildElement();
    ListOfElement(root,vR);

    return vR;

}


void ReadWriteXML::ListOfElement(QDomElement root, Vettore* vR){
    QDomNodeList rya  = root.elementsByTagName("Ryanair");
    QDomNodeList air  = root.elementsByTagName("AirPartner");
    for(int i = 0; i<= rya.count(); ++i){
        QDomNode nodeRya = rya.at(i);
        if(nodeRya.isElement()){

            QDomElement elemRya = nodeRya.toElement();
            string cod = elemRya.attribute("Cod").toStdString();
            double km = elemRya.attribute("Km").toDouble();
            int equi = elemRya.attribute("Equipaggio").toInt();
            int pass = elemRya.attribute("Passeggeri").toInt();
            string part = elemRya.attribute("Partenza").toStdString();
            string dest = elemRya.attribute("Destinazione").toStdString();
            QDate data = QDate().fromString(elemRya.attribute("Data"));
            vR->AggiungiNewViaggio(creator.createRyanair(cod,km,pass,part,dest,data,equi));
        }
    }

    for(int i = 0; i<=air.count(); ++i){
        QDomNode nodeAir = air.at(i);
        if(nodeAir.isElement()){
            QDomElement elemAir = nodeAir.toElement();
            string cod = elemAir.attribute("Cod").toStdString();
            double km = elemAir.attribute("Km").toDouble();
            int pass = elemAir.attribute("Passeggeri").toInt();
            string part = elemAir.attribute("Partenza").toStdString();
            string dest = elemAir.attribute("Destinazione").toStdString();
            QDate data = QDate().fromString(elemAir.attribute("Data"));
            int tappe = elemAir.attribute("Tappe").toInt();
            vR->AggiungiNewViaggio(creator.createAirPartner(cod,km,pass,part,dest,data,tappe));
            QDomNodeList loc = elemAir.elementsByTagName("Locazione");
            for(int l = 0; l<= loc.count(); ++l){
                QDomNode nodeLoc = loc.at(l);
                if(nodeLoc.isElement()){
                    QDomElement elemLoc = nodeLoc.toElement();
                    string nome = elemLoc.attribute("Nome").toStdString();
                    string indirizzo = elemLoc.attribute("Indirizzo").toStdString();
                    vR->AggiungiAirLoc(cod,creator.createLocazione(nome,indirizzo));
                }
            }
        }
    }
}

void ReadWriteXML::resetFileName(){
    file.setFileName("");
}

bool ReadWriteXML::SaveWithName(){
    QFile copia;
    if(file.fileName() == ""){
        return false;
    }else{
        copia.setFileName(QFileDialog::getSaveFileName(0, QString("Salva File con Nome"), QDir::homePath(), QString("XML (*.xml)")));
        file.copy(copia.fileName());
    }
    return true;
}
