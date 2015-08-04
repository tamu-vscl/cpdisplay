/* 
 * File:   enginecontroller.h
 * Author: Madison Treat <madison.treat@tamu.edu>
 *
 * Created on June 23, 2015, 12:33 PM
 */

#ifndef ENGINECONTROLLER_H
#define ENGINECONTROLLER_H

#include <QObject>

#include "enginewidget.h"


class HDDSettings;
class EngineWidget;

class EngineController : public QObject {
   Q_OBJECT;

public:
   EngineController(HDDSettings* _hddSettings, int _numEngines, QObject* _parent = 0);
   EngineController(const EngineController& orig) = delete;
   virtual ~EngineController();

public slots:
   void updateNumEngines(int numEng);
   void updateThrottleCommand(float throttle, int engNum);
   void updateThrottleActual(float throttle, int engNum);
   void updateEngPower(float power, int engNum);
   void updateEngThrust(float thrust, int engNum);
   void updateEngTorque(float torque, int engNum);
   void updateEngRPM(float rpm, int engNum);
   
   void updateOilTemp(float temp, int engNum);
   void updateOilPressure(float pressure, int engNum);
   
signals:
   void throttleUpdate(int value, int engNum);
   void oilTUpdate(float _value, int engNum);
   void oilPUpdate(float _value, int engNum);
   void engRPMUpdate(float _value, int engNum);

private:
   HDDSettings* hddSettings;
   int numEngines;
   
};

#endif	/* ENGINECONTROLLER_H */

