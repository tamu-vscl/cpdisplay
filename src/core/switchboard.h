/*
   This class is like an old telegram switchboard, redirecting core data from
   X-Plane and other data sources (Google Maps?) to wherever it needs to go
   (the individual widgets for displaying).
 */

#include <QObject>
#include <QMap>

#include "xplanedata.h"
#include "xplanedref.h"


class QUdpSocket;
class HDDSettings;
class XPOutputData;

class SwitchBoard : public QObject {
   Q_OBJECT

   static const int XPDR_OFFSET = 1000;

   // Typdef a generic signal function pointer
   typedef void (SwitchBoard::*func_pointer)(float);
   // Define the value struct for the Dataref Map drmap
   struct DRefValue {
      int            xpIndex; // XPDataIndex + XPDR_OFFSET;
      const char*    str;     // The string representation of the dataref
      func_pointer   signal;  // The SwitchBoard signal to be emitted
      int            freq;    // Frequency of response

      DRefValue(int _index, const char* _str, func_pointer _fn, int _freq) {
         xpIndex = _index;
         str = _str;
         signal = _fn;
         freq = _freq;
      }
      DRefValue(const DRefValue& rhs) {
         xpIndex = rhs.xpIndex;
         str = rhs.str;
         signal = rhs.signal;
         freq = rhs.freq;
      }
   };

public:
   SwitchBoard(HDDSettings* _settings, QObject* _parent=0);
   SwitchBoard(const SwitchBoard& orig) = delete;
   ~SwitchBoard();
   
public slots:
   void readPendingData();
   
signals:
   void notConnected(); // not connected to XPlane

   // XPlane 10.40+ versions:
   void acTailNumUpdate(float tail);
   void acNumEnginesUpdate(float num);

   void radioCom1FreqUpdate(float freq);
   void radioCom1StdbyUpdate(float freq);
   void radioCom2FreqUpdate(float freq);
   void radioCom2StdbyUpdate(float freq);
   void radioNav1FreqUpdate(float freq);
   void radioNav1StdbyUpdate(float freq);
   void radioNav2FreqUpdate(float freq);
   void radioNav2StdbyUpdate(float freq);


   // XPlane < 10.40 versions:
   void timeUpdate(float zulu, float local);
   void speedUpdate(float speed);
   
   void machNumUpdate(float mach);
   void vertVelUpdate(float vertvel);

   void pressureUpdate(float pressure);

   void angVelUpdate(float q, float p, float r);

   void pitchUpdate(float pitch);
   void rollUpdate(float roll);
   void headingTrueUpdate(float heading);
   void headingMagUpdate(float heading);

   void aoaSideSlipUpdate(float aoa, float sideslip);
   void hPathUpdate(float hpath);
   void vPathUpdate(float vpath);
   void slipSkidUpdate(float ss);

   void compassUpdate(float heading);
   void latLonUpdate(float lat, float lon); // in GPS coords/deg
   void altMSLUpdate(float alt); // in feet
   void altAGLUpdate(float alt); // in feet
   
   void acLatUpdate(float lat, int ac);
   void acLonUpdate(float lon, int ac);
   void acAltUpdate(float alt, int ac);
   
   void throttleCommandUpdate(float throttle, int engNum);
   void throttleActualUpdate(float throttle, int engNum);
   
   void engPowerUpdate(float power, int engNum);
   void engThrustUpdate(float thrust, int engNum);
   void engTorqueUpdate(float torque, int engNum);
   void engRPMUpdate(float rpm, int engNum);
   
   void com1Update(float freq, float standby);
   void com2Update(float freq, float standby);
   void comTransmitUpdate(float freq);
   
   void nav1Update(float freq, float standby);
   void nav2Update(float freq, float standby);

private:
   HDDSettings* settings;
   QUdpSocket* xplane;

   QMap<XPDataIndex, DRefValue*> drmap;
   
   void initSocket();
   void requestDatarefsFromXPlane();
   void processDatagram(QByteArray& data);
   void notifyAll(xp_dref_out* data);
   void notifyAll(XPOutputData* data);
};
