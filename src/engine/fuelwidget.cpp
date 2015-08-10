//
//  fuelwidget.cpp
//  
//
//  Created by Madison Treat on 8/10/15.
//
//

#include "fuelwidget.h"

#include <QHBoxLayout>
#include <QString>
#include <QLabel>

#include "core/cpdsettings.h"
#include "enginecontroller.h"
#include "singlefuelwidget.h"


FuelWidget::FuelWidget(CPDSettings* _cpdSettings, EngineController* _engC, int _numEngines, QFrame* _parent)
: cpdSettings(_cpdSettings),
  engC(_engC),
  numEngines(_numEngines)
{
   setupFuelGauges();

//   setMinimumSize(QSize(65, 180));
   setObjectName("border");
}

FuelWidget::~FuelWidget()
{

}

void FuelWidget::setupFuelGauges()
{
   QHBoxLayout* layout = new QHBoxLayout(this);

   for (int i = 0; i < ENGINES_MAX; i++) {
      SingleFuelWidget* fgauge = new SingleFuelWidget(cpdSettings, engC, i);
      fgauge->setVisible(i < numEngines);

      fuelGauges.append(fgauge);
      layout->addWidget(fgauge);
   }
   layout->addStretch(2);
}