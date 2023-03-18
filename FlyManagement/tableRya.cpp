#include "tableRya.h"

TableRya::~TableRya(){
    for(auto sl : v)delete sl;
}

TableRya::TableRya(QWidget *parent):QTableWidget(parent)
{
    setColumnCount(10);
    QStringList header;
    header<<"CODICE"<<"KM"<<"PASSEGGERI"<<"EQUIPAGGIO"<<"PARTENZA"<<"DESTINAZIONE"<<"DATA"<<"TAPPE"<<"NOME TAPPA"<<"INDIRIZZO TAPPA";
    setStyleSheet("font : 0 medium 12px");
    setHorizontalHeaderLabels(header);
    horizontalHeader()->setStyleSheet("font : 0 bold 14px;");
    horizontalHeader()->setMinimumSectionSize(120);
    horizontalHeader()->setMaximumSectionSize(150);
    for(int i=0; i<=9; ++i){
    }

    addLoc = new QPushButton();
    addLoc->setText("Aggiungi Locazione");
    setShowGrid(true);
    setColumnWidth(7, 150);
    setColumnWidth(8, 150);
    setColumnWidth(9, 150);
    setShowGrid(true);

}

void TableRya::addRow(bool s){
    setRowCount(rowCount()+1);
    rowViaggio*r = new rowViaggio(s,this);
    v.push_back(r);
    setCellWidget(rowCount()-1,0, r->getCod());
    setCellWidget(rowCount()-1,1, r->getKm());
    setCellWidget(rowCount()-1,2, r->getPass());
    setCellWidget(rowCount()-1,3, r->getEqui());
    setCellWidget(rowCount()-1,4, r->getPartenza());
    setCellWidget(rowCount()-1,5, r->getDestinazione());
    setCellWidget(rowCount()-1,6, r->getData());
    setCellWidget(rowCount()-1,7, r->getnumLoc());
    setCellWidget(rowCount()-1,8, r->getNameLoca());
    setCellWidget(rowCount()-1,9, r->getIndLoca());
    r->getnumLoc()->setEnabled(false);
    r->getNameLoca()->setEditable(false);
    r->getIndLoca()->setEditable(false);
    if(!s){
        r->getNameLoca()->setEditable(false);
        r->getIndLoca()->setEditable(false);
        r->getEqui()->setEnabled(false);
        setCellWidget(rowCount()-1,7, r->getnumLoc());
        setCellWidget(rowCount()-1,8, r->getNameLoca());
        setCellWidget(rowCount()-1,9, r->getIndLoca());
    }
}

void TableRya::deleteRow(int i){
    if(i<=rowCount()){
        removeRow(i-1);
        v.erase(v.begin()+i-1);
    }

}
void TableRya::addLocazione(const QString& nome, const QString& indirizzo, int i){
    QSpinBox*num = static_cast<QSpinBox*>(cellWidget(i-1,7));
    if(num->value()<5){
        if(i>0 && i<=getSizeTable() && !v[i-1]->getTipo()){
            QComboBox* n = static_cast<QComboBox*>(cellWidget(i-1,8));
            QComboBox* ind = static_cast<QComboBox*>(cellWidget(i-1,9));
            n->addItem(nome);
            ind->addItem(indirizzo);
            num->setValue(num->value()+1);

        }else{
            QMessageBox::warning(this,tr("Attenzione!"), tr("Impossibile aggiungere locazione"));
        }
    }else{
        QMessageBox::information(this,tr("Informazione"), tr("Limite locazioni raggiunto"));
    }
}
int TableRya::getSizeTable() const{
    return rowCount();
}

vector<rowViaggio *> TableRya::getV() const
{
    return v;
}

void TableRya::caricaTable(const vector<const Viaggio*>& vM){
    setRowCount(0);
    v.clear();
    bool s = 0;
    for(vector<const Viaggio*>::const_iterator cit = vM.begin(); cit!= vM.end(); ++cit){
        setRowCount(rowCount()+1);
        Viaggio* vg = const_cast<Viaggio*>(*cit);
        if(dynamic_cast<Ryanair*> (vg)){
            s = 1;
            Ryanair* rya= static_cast<Ryanair*>(vg);
            rowViaggio*r = new rowViaggio(s,this);
            v.push_back(r);
            setCellWidget(rowCount()-1,0, r->setCod(QString::fromStdString(rya->getCod())));
            setCellWidget(rowCount()-1,1, r->setKm(QString::number(rya->getKM())));
            setCellWidget(rowCount()-1,2, r->setPass(QString::number(rya->getPasseggeri())));
            setCellWidget(rowCount()-1,3, r->setEqui(QString::number(rya->getEquipaggio())));
            setCellWidget(rowCount()-1,4, r->setPartenza(QString::fromStdString(rya->getPartenza())));
            setCellWidget(rowCount()-1,5, r->setDestinazione(QString::fromStdString(rya->getDestinazione())));
            setCellWidget(rowCount()-1,6, r->setData(rya->getData()));
            setCellWidget(rowCount()-1,7, r->setnumLoc(0));
            setCellWidget(rowCount()-1,8, r->getNameLoca());
            setCellWidget(rowCount()-1,9, r->getIndLoca());
            r->getnumLoc()->setEnabled(false);
            r->getNameLoca()->setEditable(false);
            r->getIndLoca()->setEditable(false);
        }else{
            s = 0;
            AirPartner* a= static_cast<AirPartner*>(vg);
            rowViaggio*r = new rowViaggio(s,this);
            v.push_back(r);
            r->getEqui()->setEnabled(false);
            r->getnumLoc()->setEnabled(false);
            r->getNameLoca()->setEditable(false);
            r->getIndLoca()->setEditable(false);
            setCellWidget(rowCount()-1,0, r->setCod(QString::fromStdString(a->getCod())));
            setCellWidget(rowCount()-1,1, r->setKm(QString::number(a->getKM())));
            setCellWidget(rowCount()-1,2, r->setPass(QString::number(a->getPostiOcc())));
            setCellWidget(rowCount()-1,3, r->setEqui(""));
            setCellWidget(rowCount()-1,4, r->setPartenza(QString::fromStdString(a->getPartenza())));
            setCellWidget(rowCount()-1,5, r->setDestinazione(QString::fromStdString(a->getDestinazione())));
            setCellWidget(rowCount()-1,6, r->setData(a->getData()));
            setCellWidget(rowCount()-1,7, r->setnumLoc(a->getTappe()));
            setCellWidget(rowCount()-1,8, r->getNameLoca());
            setCellWidget(rowCount()-1,9, r->getIndLoca());
            for(vector<const Locazione*>::const_iterator loc = a->Locazioni.begin(); loc != a->Locazioni.end(); ++loc){
                r->getNameLoca()->addItem((QString::fromStdString((*loc)->getNome())));
                r->getIndLoca()->addItem((QString::fromStdString((*loc)->getIndirizzo())));
            }
        }
    }
}

void TableRya::resetTable(){
    v.clear();
    setRowCount(0);
}
