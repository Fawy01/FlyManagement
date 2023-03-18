#include "mainwindow.h"

#include "tabprincipale.h"

int MainWindow::WIDTH = 1390;
int MainWindow::HEIGHT = 920;

MainWindow::MainWindow(QWidget*parent): QWidget(parent){
    setStyleSheet("background-color: white");
    QVBoxLayout* mainLayout = new QVBoxLayout;

    QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    timer = new QTimer(this);
    timer->start(1000);
    oro = new QLCDNumber();
    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;
    setGeometry(x,y,WIDTH, HEIGHT);
    setMinimumSize(WIDTH, HEIGHT);
    setMaximumSize(WIDTH, HEIGHT);
    setWindowTitle(tr("Fly Management"));
    addMenu(mainLayout);
    addOpzioni(mainLayout);
    addTab(mainLayout);
    setDialog();
    connect(NFile, SIGNAL(pressed()), this, SLOT(newFile()));
    connect(Import, SIGNAL(pressed()), this, SLOT(open()));
    connect(save, SIGNAL(pressed()), this, SLOT(salva()));
    connect(ryanair, SIGNAL(clicked()),this, SLOT(addR()));
    connect(air,SIGNAL(clicked()),this,SLOT(addA()));
    connect(Add, SIGNAL(pressed()),this, SLOT(showScelta()));
    connect(addLoc, SIGNAL(pressed()), this, SLOT(showL()));
    connect(ok, SIGNAL(clicked()), this, SLOT(addL()));
    connect(del, SIGNAL(pressed()), this, SLOT(showE()));
    connect(eli, SIGNAL(pressed()), this, SLOT(Elimina()));
    connect(Bar, SIGNAL(clicked()),this, SLOT(showBar()));
    connect(Linea, SIGNAL(pressed()), this, SLOT(showLine()));
    connect(Pie, SIGNAL(pressed()), this, SLOT(showPie()));
    connect(Update, SIGNAL(pressed()), this, SLOT(UpGrafici()));
    connect(timer, SIGNAL(timeout()), this, SLOT(Orologio()));
}

MainWindow::~MainWindow(){
    delete tab;
}

void MainWindow::setDialog(){
    ryanair = new QPushButton("RYANAIR");
    ryanair->setStyleSheet("padding: 10px;""border-radius: 5px;""font : bold 12px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    air = new QPushButton("AIR PARTNER");
    air->setStyleSheet("padding: 10px;""border-radius: 5px;""font : bold 12px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    QHBoxLayout* scelta = new QHBoxLayout();
    scegli = new QDialog();
    scegli->setWindowTitle("Nuovo Viaggio");
    scegli->setStyleSheet("background-color: QColor(54, 77%, 90%);");
    scegli->setMinimumSize(270,70);
    scegli->setMaximumSize(270,70);
    scelta->addWidget(ryanair);
    scelta->addWidget(air);
    scegli->setLayout(scelta);
    inputLoc = new QDialog();
    inputLoc->setWindowTitle("Aggiungi Locazione");
    inputLoc->setMinimumSize(300,250);
    inputLoc->setMaximumSize(300,250);
    QVBoxLayout* l = new QVBoxLayout();
    Nome = new QLabel("Nome");
    Indirizzo = new QLabel("Indirizzo");
    Riga = new QLabel("n° Riga");
    n = new QLineEdit("");
    i = new QLineEdit("");
    r = new QLineEdit("");
    l->addWidget(Riga);
    l->addWidget(r);
    l->addWidget(Nome);
    l->addWidget(n);
    l->addWidget(Indirizzo);
    l->addWidget(i);
    l->addWidget(ok, Qt::AlignBottom);
    inputLoc->setLayout(l);

    QHBoxLayout* e = new QHBoxLayout();
    eliminaR = new QDialog();
    QLabel*RigaE = new QLabel("Inserisci riga da eliminare");
    rE= new QLineEdit("");
    e->addWidget(RigaE);
    e->addWidget(rE);
    e->addWidget(eli, Qt::AlignBottom);
    eliminaR->setLayout(e);
}

void MainWindow::showScelta() const
{
    scegli->setModal(true);
    scegli->show();
}
void MainWindow::addMenu(QVBoxLayout* mainLayout)
{
    QMenuBar* menuBar = new QMenuBar(this);
    menuBar->setStyleSheet("background-color: lightgray");
    QMenu* file = new QMenu("File", menuBar);
    menuBar->setContentsMargins(5,10,5,10);
    file->addAction(new QAction("Nuovo progetto", file));
    file->addAction(new QAction("Importa progetto", file));
    file->addAction(new QAction("Salva", this));
    file->addAction(new QAction("Salva con Nome", file));
    file->addAction(new QAction("Chiudi", file));
    menuBar->addMenu(file);
    mainLayout->addWidget(menuBar);
    connect(file->actions()[0], SIGNAL(triggered()), this, SLOT(newFile()));
    connect(file->actions()[1], SIGNAL(triggered()), this, SLOT(open()));
    connect(file->actions()[2], SIGNAL(triggered()), this, SLOT(salva()));
    connect(file->actions()[3], SIGNAL(triggered()), this, SLOT(saveName()));
    connect(file->actions()[4], SIGNAL(triggered()), this, SLOT(close()));
    setLayout(mainLayout);
}
void MainWindow::addTab(QVBoxLayout* mainLayout){
    tab = new TabPrincipale(this);
    mainLayout->addWidget(tab);
    setLayout(mainLayout);
}

void MainWindow::setController(Controller * c)
{
    control = c;

}
void MainWindow::addOpzioni(QVBoxLayout *mainLayout){
    QHBoxLayout* oriz = new QHBoxLayout();
    QVBoxLayout* vert = new QVBoxLayout();
    QToolBar* op = new QToolBar(this);
    QToolBar* gr = new QToolBar(this);
    gr->setStyleSheet("border-radius: 5px;""border :1px solid black;""spacing : 10px;""background-color: QColor(54, 77%, 90%);");
    gr->setMaximumHeight(54);
    gr->setMaximumWidth(890);
    op->setStyleSheet("border-radius: 5px;""border :1px solid black;""spacing : 10px;""background-color: QColor(54, 77%, 90%);");
    op->setMaximumHeight(54);
    op->setMaximumWidth(490);
    ok = new QPushButton("Inserisci");
    ok->setStyleSheet("padding: 10px;""border-radius: 5px;""font : bold 12px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    eli = new QPushButton("Elimina");
    eli->setStyleSheet("padding: 10px;""border-radius: 5px;""font : bold 12px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    NFile = new QPushButton(QIcon(":/images/newFile.jfif"),tr("Nuovo Progetto"),this);
    Import = new QPushButton(QIcon(":/images/Import.jfif"),tr("Importa Progetto"),this);
    save = new QPushButton(QIcon(":/images/save.jfif"), tr("Salva"), this);
    Linea = new QPushButton(QIcon(":/images/linea.jfif"), tr(""), this);
    Bar = new QPushButton(QIcon(":/images/bar.jfif"), tr(""), this);
    Pie = new QPushButton(QIcon(":/images/pie.jfif"), tr(""), this);
    Add = new QPushButton(QIcon(":/images/viaggio.jfif"), tr("Aggiungi"), this);
    addLoc = new QPushButton(QIcon(":/images/truck.jfif"), tr("Aggiungi Locazione"), this);
    Update = new QPushButton(QIcon(":/images/reload.jfif"), tr("Aggiorna Dati"),this);
    del = new QPushButton(QIcon(":/images/delete.jfif"), tr("Elimina Viaggio"), this);
    NFile->setMinimumSize(178,50);
    NFile->setMaximumSize(178,50);
    NFile->setIconSize(QSize(40,38));
    NFile->setStyleSheet("margin-left : 10px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 5px;""font :  bold 14px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    Import->setMinimumSize(190,50);
    Import->setMaximumSize(190,50);
    Import->setIconSize(QSize(40,38));
    Import->setStyleSheet("margin-left : 10px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 5px;""font : bold 14px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    save->setMinimumSize(100,50);
    save->setMaximumSize(100,50);
    save->setIconSize(QSize(40,40));
    save->setStyleSheet("margin-left : 10px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 5px;""font : bold 14px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    Add->setMinimumSize(160,50);
    Add->setMaximumSize(160,50);
    Add->setIconSize(QSize(40,40));
    Add->setStyleSheet("margin-left : 10px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 5px;""font : bold 14px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    addLoc->setMinimumSize(200,50);
    addLoc->setMaximumSize(200,50);
    addLoc->setIconSize(QSize(40,40));
    addLoc->setStyleSheet("margin-left : 10px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 5px;""font : bold 14px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    del->setMinimumSize(165,50);
    del->setMaximumSize(165,50);
    del->setIconSize(QSize(35,35));
    del->setStyleSheet("margin-left : 10px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 5px;""font : bold 14px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    Linea->setMinimumSize(50,50);
    Linea->setMaximumSize(50,50);
    Linea->setIconSize(QSize(40,40));
    Linea->setStyleSheet("margin-left : 3px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 3px;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    Bar->setMinimumSize(50,50);
    Bar->setMaximumSize(50,50);
    Bar->setIconSize(QSize(40,40));
    Bar->setStyleSheet("margin-left : 3px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 3px;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    Pie->setMinimumSize(50,50);
    Pie->setMaximumSize(50,50);
    Pie->setIconSize(QSize(40,40));
    Pie->setStyleSheet("margin-left : 3px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 3px;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");
    Update->setMinimumSize(160,50);
    Update->setMaximumSize(160,50);
    Update->setIconSize(QSize(40,40));
    Update->setStyleSheet("margin-left : 10px;""margin-right : 3px;""margin-top : 4px;""margin-bottom : 4px;""border-radius: 5px;""font : bold 12px;""background-color: white;""border :1px solid;""border-top-color : black;""border-left-color : black;""border-right-color : black;""border-bottom-color : black;");

    oro->setStyleSheet("background-color: QColor(200, 100%, 95%);""padding: 20px;""margin-left : 60px;""margin-right : 30px;""border :4px dot-dot-dash white;");


    op->setContentsMargins(5,10,5,10);
    op->addWidget(NFile);
    op->addWidget(Import);
    op->addWidget(save);
    gr->addWidget(Add);
    gr->addWidget(addLoc);
    gr->addWidget(del);
    gr->addWidget(Update);
    gr->addWidget(Linea);
    gr->addWidget(Bar);
    gr->addWidget(Pie);
    vert->addWidget(op);
    vert->addWidget(gr);
    oriz->addLayout(vert);
    oriz->addWidget(oro, Qt::AlignRight);
    mainLayout->addLayout(oriz);
    setLayout(mainLayout);

}

void MainWindow::addA(){
    tab->addA();
    scegli->close();
    scegli->setModal(false);
}

void MainWindow::addR(){
    tab->addR();
    scegli->close();
    scegli->setModal(false);
}

void MainWindow::showL() const
{
    inputLoc->setModal(true);
    inputLoc->show();
    r->clear();
    n->clear();
    i->clear();
}

void MainWindow::addL(){
    tab->addL(n->text(), i->text(), r->text().toInt());
    r->clear();
    n->clear();
    i->clear();
    inputLoc->close();
    inputLoc->setModal(false);
}

void MainWindow::showE() const{
    eliminaR->setModal(true);
    eliminaR->show();
}
void MainWindow::Elimina(){
    tab->deleteR(rE->text().toInt());
    rE->clear();
    eliminaR->close();
    eliminaR->setModal(false);
}

void MainWindow::showBar() const
{
    tab->showBar();
}

void MainWindow::showLine() const
{
    tab->showLine();
}

void MainWindow::showPie() const
{
    tab->showPie();
}

void MainWindow::UpGrafici() const{
    tab->Update();
}

void MainWindow::salva() const
{
    control->salva(tab->getV());
}

void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Seleziona file"), QDir::homePath(), tr("XML (*.*)"));
    if(filename == ""){
        QMessageBox::warning(this,tr("Attenzione!"), tr("Impossibile aggiungere file"));
    }else{
        control->carica(filename);
    }
}
void MainWindow::newFile() const{
    control->newFile(tab->getV());
    tab->resetTab();
}
void MainWindow::AggiornaTable(const vector<const Viaggio*> v) const{
    tab->AggiornaTable(v);
}

void MainWindow::saveName() const{
    control->saveName(tab->getV());
}

void MainWindow::Orologio()
{
    QTime time = QTime::currentTime();
    QString time_text  = time.toString("hh:mm");
    oro->display(time_text);
}


