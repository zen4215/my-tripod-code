#include <Arduino.h>
#include <IcsHardSerialClass.h>
#include <PS4Controller.h>

// set constant
namespace ics{
    const byte EN_PIN   {2};
    const long BAUDRATE {115200};
    const int  TIMEOUT  {10};
    
    IcsHardSerialClass krs(&Serial, EN_PIN, BAUDRATE, TIMEOUT);
}

const int   SERIAL_BAUDRATE {115200};
const char* PS4_BLE_ADDLESS {"08:B6:1F:ED:4B:E2"};

// setup function
void setup() {
    Serial.begin(SERIAL_BAUDRATE);
    PS4.begin(PS4_BLE_ADDLESS);
    ics::krs.begin();
}

void loop() {
}
