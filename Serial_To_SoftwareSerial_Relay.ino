/***************************************************************
   Sending AT commands through serial monitor
   Hardware Serial to SoftwareSerial Relay - Arduino will patch a
   serial link between the computer and the device running on UART
   - Computer is connected to Hardware UART
   - Serial device is connected to the Software UART

   Wiring for ESP8266 Wifi Module
   ESP8266   -----   Uno
   ------------------------
   Tx               pin 2
   Rx               pin 3
   CHPD             3V
   3V               3V
   GND              GND
 * **In Serial Monitor, select "Both CL & CR"
 * **Default baudrate 115200

***************************************************************/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

void setup()
{
  mySerial.begin(115200);
  Serial.begin(115200);
}

void loop()
{
  // relay everything received from mySerial to Serial
  if (mySerial.available())
    Serial.write(mySerial.read());

  // relay everything received from Serial to mySerial
  if (Serial.available())
    mySerial.write(Serial.read());

}
