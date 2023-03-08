//general
#include <SPI.h>

//for SD Card
#include <SD.h>

//for BMP280
#include <Wire.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (4)

//for MMA8451
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

void setup() 
{
  Serial.begin(9600);
  data = SD.open("lloydSensorCode", FILE_WRITE);

  data.println(); //BMP280
  data.println(); //MMA8451

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
