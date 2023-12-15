#include <TheThingsNetwork.h>
#include <SoftwareSerial.h>

#define loraSerial mySerial
#define debugSerial Serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868


const byte txPin = 11;
const byte rxPin = 10;
const int gasSensorPin = 0;

SoftwareSerial mySerial (rxPin,txPin);
TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);


const char *appEui = "ab560545bf675cfe";
const char *appKey = "c297f2fa59f017e02a22853d5371f8e8";
int val = 0;

void setup()
{
  loraSerial.begin(57600);
  debugSerial.begin(9600);
  ttn.join(appEui,appKey);
}

void loop()
{
//  debugSerial.println("Device Information");
//  debugSerial.println();
//  ttn.showStatus();
//  debugSerial.println();
//  debugSerial.println("Use the EUI to register the device for OTAA");
//  debugSerial.println("-------------------------------------------");
//  debugSerial.println();
//  byte data[2];
//  data[0] = 0x11;
//  data[1] = 0x10;
//  ttn.sendBytes(data,sizeof(data));
//  debugSerial.println("Byte envoyé");
  val = analogRead(gasSensorPin);
  debugSerial.println(val);
  byte payload[2];
  payload[0] = val & 0xFF;
  payload[1] = (val >> 8) & 0xFF;
  ttn.sendBytes(payload, sizeof(payload));
  delay(10000);
}
