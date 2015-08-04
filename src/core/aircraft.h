/* 
 * File:   aircraft.h
 * Author: Madison Treat <madison.treat@tamu.edu>
 *
 * Created on June 26, 2015, 4:16 PM
 * 
 * This aicraft class represents any aircraft that is NOT the one being flown in
 * this cockpit.
 */

#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <QObject>
#include <QMap>


enum AircraftType {
   BOMBER = 0,
   CIVIL,
   FIGHTER,
   GENERAL_AVIATION,
   GLIDER,
   HELO,
   TRANSPORT,
   UAS,
   NUM_AIRCRAFT_TYPES
};


enum AircraftEngineType {
   AC_ENG_PROP = 0,
   AC_ENG_JET,
   AC_ENG_TURBOJET
};


class Aircraft : public QObject {
   Q_OBJECT;

public:
   Aircraft(int _id, QObject* _parent = 0);
   Aircraft(const Aircraft& orig) = delete;
   virtual ~Aircraft();
   
   int   getID()  const { return id; }
   
   float getSpd() const { return spd; }
   float getLat() const { return lat; }
   float getLon() const { return lon; }
   float getAlt() const { return alt; }
   float getHdg() const { return hdg; }
   float getRng() const { return rng; }
   float getBer() const { return ber; }
   
   bool hasBeenDisplayed() const { return displayed; }
   void setHasBeenDisplayed() { displayed = true; }

public slots:
   void setLat(float _lat);
   void setLon(float _lon);
   void setAlt(float _alt);
   void setLatLonAlt(float _lat, float _lon, float _alt);
   
   void setRngBer(double _rng, double _ber);

signals:
   void acUpdated(int id);
   void rngBerUpdated(int id);

private:
   AircraftType type;
   AircraftEngineType engType;
   int   id;  // aircraft id
   bool  displayed; // has this aircraft been displayed on the map yet?
   
   float lat; // latitude
   float lon; // longitude
   float alt; // MSL altitude
   
   float spd; // speed
   float hdg; // aircraft's heading
   
   // These values are from a reference point of the current cockpit's position
   float rng; // aircraft's range from this position
   float ber; // aircraft's bearing from this position
   
   bool latUpdated;
   bool lonUpdated;
   bool altUpdated;
   
   void tryEmitUpdate();
};

// map of ID to Aircraft
typedef QMap<int, Aircraft*> ACMap;

#endif	/* AIRCRAFT_H */

