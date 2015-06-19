#include <QMainWindow>

#include "mapcontroller.h"

class QToolBar;
class QPushButton;
class QHBoxLayout;

class HDDSettings;
class MapView;
class mapOverlay;

//class MapController;
class PFDController;
class ALTController;
class ASIController;
class HSIController;

class HDDWindow : public QMainWindow {
   Q_OBJECT

public:
   HDDWindow(HDDSettings* _hddSettings, QObject* _parent=0);
   ~HDDWindow();

   MapController* getMapC() const { return mapC; }
   PFDController* getPFDC() const { return pfdC; }
   ALTController* getALTC() const { return altC; }
   ASIController* getASIC() const { return asiC; }
   HSIController* getHSIC() const { return hsiC; }
   
   MapView*    getMapView() const { return mapC->getMapView(); }
   MapOverlay* getOverlay() const { return mapC->getOverlay(); }

public slots:
   void orientationButtonClicked(bool checked);
   
   void latLonUpdate(float lat, float lon, int ac=0);

private:
   HDDSettings* hddSettings;
   
   MapController* mapC;
   PFDController* pfdC;
   ALTController* altC;
   ASIController* asiC;
   HSIController* hsiC;
   
   // Main layout for central widget
   QHBoxLayout*   layout;
   QWidget*       centralWidget;
   
   // The toolbar and buttons
   QToolBar*      toolbar;
   QPushButton*   pfdButton;
   QPushButton*   weatherButton;
   QPushButton*   trafficButton;
   QPushButton*   terrainButton;
   QPushButton*   orientationButton; // map orientation, checked = NORTH_UP
   QPushButton*   zoomInButton;
   QPushButton*   zoomOutButton;
//   QPushButton*    homeButton;

   void setupToolbar();
};
