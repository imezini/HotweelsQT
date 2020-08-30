#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), view(new MainWindow()), m(new Model()) {


    connect(m, SIGNAL(veicoloInLista()), this, SLOT(updateVeicoliTable()));

    connect(view->vistaAdd, SIGNAL(inviaStringaVeicoli(const QStringList)), this, SLOT(addVeicoloCont(const QStringList)));
    connect(view, SIGNAL(filtroTutti()), this, SLOT(filtraTuttiVeicolo()));
    connect(view,SIGNAL(filtroAutomobile()),this, SLOT(filtraTuttiAutomobile()));
    connect(view, SIGNAL(filtroAutotreno()),this, SLOT(filtraTuttiAutotreno()));
    connect(view,SIGNAL(filtroAutocarro()),this,SLOT(filtraTuttiAutocarro()));
    connect(view, SIGNAL(filtroMinAssi()),this, SLOT(filtraTuttiVeicoloMinAssi()));
    connect(view,SIGNAL(filtroMaxAssi()),this, SLOT(filtraTuttiVeicoloMaxAssi()));
    connect(view, SIGNAL(filtroEsonero()),this, SLOT(filtraTuttiVeicoloEsonero()));

    //connect(view, SIGNAL(signEsportaPDFClienti()), this, SLOT(esportaPDFClienti()));
    connect(m, SIGNAL(resetColoreFiltro()), this, SLOT(resetTuttiColoreFiltro()));
//    updateVeicoliTable();
    view->show();
}

Controller::~Controller() {
    delete m;
}

void Controller::addVeicoloCont(const QStringList v) {
        m->addInList(v);
//        updateVeicoliTable();
}

//void Controller::updateVeicoliTable() {
//    QString parolaNelCampoCerca = view->getParolaCercata();
//    view->mostraVeicoli(m->getListaVeicoli());
//    view->mostraVeicoli(m->getListaVeicoliFiltrata(parolaNelCampoCerca, indexTranslate));

//}

void Controller::updateVeicoliTable() {
    view->mostraVeicoli(m->getListaVeicoli());
}

void Controller::filtraTuttiVeicolo()
{
    m->resetFiltro();
    updateVeicoliTable();
}

void Controller::filtraTuttiAutomobile()
{
   // m->fltrAutomobile();
    updateVeicoliTable();
}

void Controller::filtraTuttiAutocarro()
{
    //m->fltrAutocarro();
    updateVeicoliTable();
}

void Controller::filtraTuttiAutotreno()
{
    //m->fltrAutotreno();
    updateVeicoliTable();
}

void Controller::filtraTuttiVeicoloMaxAssi()
{
    //m->fltrMaxAssi();
    updateVeicoliTable();
}

void Controller::filtraTuttiVeicoloMinAssi()
{
    //m->fltrMinAssi();
    updateVeicoliTable();
}

void Controller::filtraTuttiVeicoloEsonero()
{
    //m->fltrEsonero();
    updateVeicoliTable();
}

void Controller::resetTuttiColoreFiltro() const
{
    view->colorInizio();
}

//void Controller::esportaPDFClienti() const
//{
//    QString nomeFile = QFileDialog::getSaveFileName(view,"Stampa Autoveicolo","../Hotparte6/AutoveicoliTotaliPdf","ListaAutoveicoliTOTALE_pdf(*.pdf)");
//    QPdfWriter writer(nomeFile);
//    QPainter painter(&writer);
//    painter.setPen(Qt::black);

//    int l=900, a1=1000;
//    QStringList clienti = m->getListaClientiPDF();
//    for(auto it = clienti.begin();it!=clienti.end();++it)
//    {
//        painter.drawText(l,a1,*it);
//        a1+=400;
//    }
//    painter.end();
//}

