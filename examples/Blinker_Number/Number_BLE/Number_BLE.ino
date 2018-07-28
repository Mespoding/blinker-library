#define BLINKER_PRINT Serial
#define BLINKER_BLE

#include <Blinker.h>

#define NUM_1 "NUMKey"

BlinkerNUM NUM1(NUM_1);

void setup()
{
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Blinker.begin();
}

void loop()
{
    Blinker.run();

    if (Blinker.available()) {
        BLINKER_LOG2("Blinker.readString(): ", Blinker.readString());

        Blinker.vibrate();
        
        uint32_t BlinkerTime = millis();
        Blinker.print(BlinkerTime);
        Blinker.print("millis", BlinkerTime);

        NUM1.icon("icon_1");
        NUM1.color("#FFFFFF");
        NUM1.unit("ms");
        NUM1.print(BlinkerTime);
    }
}