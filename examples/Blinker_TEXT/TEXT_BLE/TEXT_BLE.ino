#define BLINKER_PRINT Serial
#define BLINKER_BLE

#include <Blinker.h>

#define TEXTE_1 "TextKey"

BlinkerText Text1(TEXTE_1);

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

        Text1.title("os time");
        Text1.print(BlinkerTime);
    }
}