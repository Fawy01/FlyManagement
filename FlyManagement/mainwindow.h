#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMenuBar>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QToolBar>
#include "controller.h"
#include <QDialog>
#include <QDesktopWidget>
#include <QApplication>
#include <QFileDialog>
#include <QLCDNumber>

class TabPrincipale;

class MainWindow: public QWidget{
    Q_OBJECT

    Controller*control;

    TabPrincipale*tab;
    QPushButton* NFile;
    QPushButton* Import;
    QPushButton* save;
    QPushButton* Linea;
    QPushButton* Pie;
    QPushButton* Bar;
    QPushButton*Add;
    QPushButton* ryanair;
    QPushButton* air;
    QPushButton* addLoc;
    QPushButton* ok;
    QDialog*scegli;
    QDialog* inputLoc;
    QLabel* Nome;
    QLabel* Indirizzo;
    QLineEdit* n;
    QLineEdit* i;
    QLabel*Riga;
    QLineEdit*r;
    QLineEdit*rE;
    QPushButton*del;
    QDialog* eliminaR;
    QPushButton*eli;
    QPushButton*Update;
    QDesktopWidget *desktop;
    QTimer* timer;
    QLCDNumber* oro;
    static int WIDTH;
    static int HEIGHT;

    int screenWidth;
    int screenHeight;

    int x, y;

public:
    explicit MainWindow(QWidget*parent = nullptr);
    ~MainWindow();
    void addMenu(QVBoxLayout* );
    void addOpzioni(QVBoxLayout*);
    void addTab(QVBoxLayout*);
    void setController(Controller*);
    void setDialog();
    void AggiornaTable(const vector<const Viaggio *> v) const;

signals:
    void add();
public slots:
    void newFile() const;
    void salva() const;
    void open();
    void saveName() const;
    void showScelta() const;
    void addA();
    void addR();
    void addL();
    void showL() const;
    void showE() const;
    void Elimina();
    void showBar() const;
    void showLine() const;
    void showPie() const;
    void UpGrafici() const;
    void Orologio();
};

#endif // MAINWINDOW_H
