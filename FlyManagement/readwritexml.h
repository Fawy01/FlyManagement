#ifndef READWRITEXML_H
#define READWRITEXML_H
#include <QtXml>
#include <ryanair.h>
#include <airpartner.h>
#include <createviaggio.h>
#include <iostream>
#include "vettore.h"

#include <QFileDialog>
#include <QMessageBox>


using std::cout;
class ReadWriteXML{

public:
    ReadWriteXML();
    QDomDocument document;
    QDomElement root;
    QFile file;
    CreateViaggio creator;
    Vettore* vR;
    void resetFileName();
    void Save(const vector<const Viaggio*>&);
    void clearDocument();
    Vettore* read(const QString &);
    void ListOfElement(QDomElement , Vettore* );
    bool SaveWithName();
    ~ReadWriteXML();
};


#endif // READWRITEXML_H
