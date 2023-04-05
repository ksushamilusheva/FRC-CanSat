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

File data;

Adafruit_BMP280 bmp;
Adafruit_MMA8451 mma = Adafruit_MMA8451();
int counter = 0;

void setup() 
{
  Serial.begin(9600);

//BMP280
unsigned status;
status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  data.println(); //MMA8451

  
}

void loop() 
{
  float temp = bmp.readTemperature(); //in Celcius
  float pressure = bmp.readPressure(); //in Pascals
  float altitude = bmp.readAltitude(1013.25); //in meters
  mma.read();
  sensors_event_t event;
  mma.getEvent(&event);
  float accel = event.acceleration.z; //in meters/second^2


  Serial.println(temp);
  Serial.println(pressure);
  Serial.println(altitude);
  Serial.println(accel);
  
  //data = SD.open("SensorCode", FILE_WRITE);
delay(2000);

}
