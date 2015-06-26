#include "window.h"

#include <QToolBar>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

#include "core/hddsettings.h"

#include "map/mapcontroller.h"
#include "instruments/adicontroller.h"
#include "instruments/altcontroller.h"
#include "instruments/asicontroller.h"
#include "instruments/hsicontroller.h"
#include "instruments/pfdcontroller.h"
#include "instruments/tcdcontroller.h"
#include "instruments/vsicontroller.h"

#include "comms/commscontroller.h"
#include "engine/enginecontroller.h"
#include "traffic/trafficcontroller.h"


HDDWindow::HDDWindow(HDDSettings* _hddSettings, QObject* _parent) 
: QMainWindow(),
  hddSettings(_hddSettings)
{
   mapC = new MapController(hddSettings, this);
   adiC = new ADIController(this);
   altC = new ALTController(this);
   asiC = new ASIController(this);
   hsiC = new HSIController(this);
   pfdC = new PFDController(this);
   tcdC = new TCDController(this);
   vsiC = new VSIController(this);
   
   comC = new CommsController(hddSettings, this);
   engC = new EngineController(hddSettings, this);
   tfcC = new TrafficController(hddSettings, this);
   
   layout = new QGridLayout();
   
   centralWidget = new QWidget();
   centralWidget->setLayout(layout);
   layout->addWidget((QWidget*) comC->getWidget(), 3, 1, 1, 3);
   layout->addWidget((QWidget*) pfdC->getWidget(), 0, 1, 3, 3);
   layout->addWidget((QWidget*) mapC->getWidget(), 0, 4, 3, 3);
   layout->addWidget((QWidget*) tfcC->getWidget(), 3, 4, 1, 3);
   setCentralWidget(centralWidget);
   
   setupToolbar();
   
   setMinimumSize(QSize(950, 400));
//   showWindow();
}

HDDWindow::~HDDWindow() {
}

void HDDWindow::setupToolbar()
{
   toolbar = new QToolBar(this);
   toolbar->setOrientation(Qt::Vertical);// | Qt::Horizontal);
   
   pfdButton = new QPushButton("PFD");
   pfdButton->setEnabled(true);
   pfdButton->setMinimumHeight(80);
   pfdButton->setCheckable(true);
   pfdButton->setChecked(true);
   pfdButton->setContentsMargins(0, 0, 0, 0);
   connect(pfdButton, SIGNAL(toggled(bool)), this, SLOT(pfdButtonClicked(bool)));
   toolbar->addWidget(pfdButton);
   
   weatherButton = new QPushButton("WX");
   weatherButton->setEnabled(false);
   weatherButton->setMinimumHeight(80);
   weatherButton->setContentsMargins(0, 0, 0, 0);
   toolbar->addWidget(weatherButton);
   
   trafficButton = new QPushButton("TFC");
   trafficButton->setEnabled(false);
   trafficButton->setMinimumHeight(80);
   trafficButton->setContentsMargins(0, 0, 0, 0);
   toolbar->addWidget(trafficButton);
   
   terrainButton = new QPushButton("TER");
   terrainButton->setEnabled(false);
   terrainButton->setMinimumHeight(80);
   pfdButton->setContentsMargins(0, 0, 0, 0);
   toolbar->addWidget(terrainButton);
   
   orientationButton = new QPushButton("North Up");
   orientationButton->setEnabled(true);
   orientationButton->setMinimumHeight(80);
   orientationButton->setCheckable(true);
   orientationButton->setChecked(true);
   if (hddSettings->mapOrientation() == TRACK_UP) {
      orientationButton->setChecked(false);
   }
   orientationButton->setContentsMargins(0, 0, 0, 0);
   connect(orientationButton, SIGNAL(toggled(bool)), this, SLOT(orientationButtonClicked(bool)));
   toolbar->addWidget(orientationButton);
   
   zoomInButton = new QPushButton("Zoom In");
   zoomInButton->setEnabled(true);
   zoomInButton->setMinimumHeight(80);
   zoomInButton->setContentsMargins(0, 0, 0, 0);
   connect(zoomInButton, SIGNAL(clicked()), mapC, SLOT(increaseZoom()));
   // If you are at the max zoom (very close shot of ground), disable zoom in button
   connect(mapC, SIGNAL(zoomMaxReached(bool)), zoomInButton, SLOT(setDisabled(bool)));
   connect(mapC, SIGNAL(zoomEither(bool)),     zoomInButton, SLOT(setEnabled(bool)));
   toolbar->addWidget(zoomInButton);
   
   zoomOutButton = new QPushButton("Zoom Out");
   zoomOutButton->setEnabled(true);
   zoomOutButton->setMinimumHeight(80);
   zoomOutButton->setContentsMargins(0, 0, 0, 0);
   connect(zoomOutButton, SIGNAL(clicked()), mapC, SLOT(decreaseZoom()));
   // If you are at the minimum zoom (whole earth), disable zoom out button
   connect(mapC, SIGNAL(zoomMinReached(bool)), zoomOutButton, SLOT(setDisabled(bool)));
   connect(mapC, SIGNAL(zoomEither(bool)),     zoomOutButton, SLOT(setEnabled(bool)));
   toolbar->addWidget(zoomOutButton);
   
   this->addToolBar(Qt::RightToolBarArea, toolbar);
}

void HDDWindow::pfdButtonClicked(bool checked)
{
   QWidget* mapW = (QWidget*) mapC->getWidget();
   QWidget* adiW = (QWidget*) adiC->getWidget();
   QWidget* altW = (QWidget*) altC->getWidget();
   QWidget* asiW = (QWidget*) asiC->getWidget();
   QWidget* hsiW = (QWidget*) hsiC->getWidget();
   QWidget* pfdW = (QWidget*) pfdC->getWidget();
   QWidget* tcdW = (QWidget*) tcdC->getWidget();
   QWidget* vsiW = (QWidget*) vsiC->getWidget();
   
   // Display PFD if checked
   if (checked) {
      layout->removeWidget(adiW);
      layout->removeWidget(altW);
      layout->removeWidget(asiW);
      layout->removeWidget(hsiW);
      layout->removeWidget(tcdW);
      layout->removeWidget(vsiW);
      adiW->hide();
      altW->hide();
      asiW->hide();
      hsiW->hide();
      tcdW->hide();
      vsiW->hide();

      layout->addWidget(pfdW, 0, 1, 3, 3);
      pfdW->show();
   }
   // Disply other instruments if unchecked
   else {
      layout->removeWidget(pfdW);
      pfdW->hide();
      
      layout->addWidget(asiW, 0, 1);
      layout->addWidget(adiW, 0, 2);
      layout->addWidget(altW, 0, 3);
      layout->addWidget(tcdW, 1, 1);
      layout->addWidget(hsiW, 1, 2);
      layout->addWidget(vsiW, 1, 3);
      adiW->show();
      altW->show();
      asiW->show();
      hsiW->show();
      tcdW->show();
      vsiW->show();
   }
}

void HDDWindow::orientationButtonClicked(bool checked)
{
   mapC->setOrientation(checked ? NORTH_UP : TRACK_UP);
}

void HDDWindow::latLonUpdate(float lat, float lon, int ac)
{
   mapC->panToLocation(lat, lon, ac);
}
