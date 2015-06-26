/* 
 * File:   mapwidget.h
 * Author: Madison Treat <madison.treat@tamu.edu>
 *
 * Created on June 15, 2015, 2:37 PM
 */

#ifndef MAPWIDGET_
#define MAPWIDGET_

#include <QWidget>
#include "core/mapconsts.h"

#include "mapview.h"
#include "mapoverlay.h"

class MapSettings;
//class MapView;
//class MapOverlay;

class HDDSettings;


class MapWidget : public QWidget {
   Q_OBJECT;

public:
   MapWidget(HDDSettings* _hddSettings, MapSettings* _mapSettings, QWidget* _parent = 0);
   MapWidget(const MapWidget& orig) = delete;
   virtual ~MapWidget();

   MapView*    getMapView() const { return view; }
   MapOverlay* getOverlay() const { return overlay; }

public slots:
   void setZoom(int level);
   void panToLocation(float lat, float lon);
   void setOrientation(MapOrientation mo);
   

private:
   HDDSettings* hddSettings;
   MapSettings* mapSettings;
   MapView* view;
   MapOverlay* overlay;

};

#endif	/* MAPWIDGET_ */
