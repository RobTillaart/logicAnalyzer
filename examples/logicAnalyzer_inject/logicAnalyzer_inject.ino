//
//    FILE: logicAnalyzer_inject.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test basic behaviour and performance
//     URL: https://github.com/RobTillaart/logicAnalyzer


#include "logicAnalyzer.h"


logicAnalyzer LA;

uint32_t rawData = 0;

void setup()
{
  Serial.begin(1000000);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("LOGICANALYZER_LIB_VERSION: ");
  Serial.println(LOGICANALYZER_LIB_VERSION);
  Serial.println();

  LA.setChannels(32);
}


void loop()
{
  //  10 second of raw data
  int x = random(32);
  rawData ^= (1UL << x);
  
  LA.inject(rawData);
  LA.plot();
  if (millis() >= 10000)
  {
    Serial.println(LA.getCount());
    while (1);
  }
}


//  -- END OF FILE --
