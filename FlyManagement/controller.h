#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <rowviaggio.h>
#include <string>
#include <QDate>
#include <readwritexml.h>
#include <iostream>
#include <QMessageBox>
#include <model.h>
using std::cout;
using std::string;

class MainWindow;
class Model;
class Controller : public QObject
{
    Q_OBJECT
    MainWindow* view;
    Model*m;
    ReadWriteXML* IO;
public:
    explicit Controller(QObject * = nullptr);
    void setView(MainWindow*);
    void setModel(Model*);
    void showView();

    void newFile(const vector<rowViaggio *>& v);
    void saveName(const vector<rowViaggio *>&);
    ~Controller();
signals:

public slots:
    void salva(const vector<rowViaggio *>&);
    void carica(const QString&);


};

#endif // CONTROLLER_H
