#include "Arduino.h"
#include "Tuyav.h"
#include "global.h"


//User can choose SoftwareSerial
//you can choose your own pins
//SoftwareSerial mySerial(2,3);

//User can choose HardwareSerial: Serial1/Serial2/Serial3
// Serial1 is pin 18/19 on a Arduino Mega
Tuyav tuyav(&Serial1);

//Initialize Time for updating Arbitrary Values
const unsigned long eventTime = 2000;
unsigned long previousTime = 0;
bool isLampOn = false;

void setup() {

  /*
  *If user does not use a pin: set the pin as PIN_UNUSED
  *PIN 18 is A5
  */

  tuyav.setDigitalInputs(8, 12, 18);        //Set DigitalInputs: needs 5 pins
  tuyav.setAnalogInputs(A0, A1, A2);        //Set AnalogInputs
  tuyav.setDigitalOutputs(13, 4, 5, 6, 7);  //SetDigitalOutputs
  tuyav.setAnalogOutputs(9, 10, 11);               //Set AnalogOutputs

  //UNCOMMENT NEXT LINE TO PAIR THE MODULE, COMMENT THE LINE AFTER PAIRING AND REFLASH THE ARDUINO
  //Next line should only be executed once
  //tuyav.setWifiMode(SMART_CONFIG_STATE);

  tuyav.initialize();

}

void loop() {
  //Should be called continuously 
  tuyav.tuyaUpdate();

  //example: user can access the inputs values and states
  int D_IN_1 = tuyav.DIGITAL_IN[0];     // "tuyav.DIGITAL_IN[0]" returns the state of the first digital input
  int A_IN_1 = tuyav.ANALOG_IN[0];      // "tuyav.ANALOG_IN[0]" returns the value of the first analog input

  //example: user can access the outputs values and states
  int D_OUT_1 = tuyav.DIGITAL_OUT[0];    // "tuyav.DIGITAL_OUT[0]" returns the state of the first digital output
  int A_OUT_1 = tuyav.ANALOG_OUT[0];     // "tuyav.ANALOG_OUT[0]" returns the value of the first analog output

  //User can send an Arbitrary value to the cloud calling "tuyav.sendUserStringValue(USER_VALUE_1/USER_VALUE_2/USER_VALUE_3, "UserStringValue")" and "tuyav.sendUserValue(USER_VALUE_4/, UserValue)"

  int sensorValue1 = 10; //User define a value for USER_VALUE_4
  int sensorValue2 = 200; //User can define a value for USER_VALUE_5
  float gravity = 9.81f;
  
  
    tuyav.setUserValue(AV1, "Test Application"); //User send string value "Kitchen" to the cloud
    tuyav.setAV2("V1.1"); //User send string value "Living Room" to the cloud
    String bedroomLamp = "Bedroom Lamp: ";
    bedroomLamp += isLampOn ? "ON" : "OFF";
    isLampOn = !isLampOn;
    tuyav.setUserValue(AV3, bedroomLamp); //User send string value "Bedroom" to the cloud*/
    tuyav.setUserValue(AV4, "Temp: 22°C"); //User send string value "Bedroom" to the cloud*/
    tuyav.setUserValue(AV5, "ON"); //User send string value "Bedroom" to the cloud*/
    tuyav.setUserValue(AV6, String(sensorValue2)); //User send string value "Bedroom" to the cloud*/
    tuyav.setUserValue(AV7, String(gravity)); //User send string value "Bedroom" to the cloud*/
    String message;
    message = "Humidity :";
    message += String(sensorValue1);
    tuyav.setUserValue(AV8, "Elepsed Time: "); //User send string value "Bedroom" to the cloud*/
    tuyav.setUserValue(AV9, String(millis())); //User send string value "Bedroom" to the cloud*/
  
}