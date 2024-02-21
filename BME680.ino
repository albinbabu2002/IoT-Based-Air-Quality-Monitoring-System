#define BLYNK_TEMPLATE_ID "***********************"
#define BLYNK_TEMPLATE_NAME "****************"         You should get the detail's in the Blynk App
#define BLYNK_AUTH_TOKEN "***************"
 
#include "bsec.h"
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "***********************";    // You should get Auth Token in the Blynk App.
char ssid[] = "***********************";                           // Your WiFi credentials.
char pass[] = "***********************";

// Helper functions declarations
void checkIaqSensorStatus(void);
void errLeds(void);
 
// Create an object of the class Bsec
Bsec iaqSensor;
 
String output;
 
// Entry point for the example
void setup(void)
{
  Serial.begin(115200);
  Wire.begin(0, 2);
  Blynk.begin(auth, ssid, pass);
  iaqSensor.begin(BME68X_I2C_ADDR_LOW, Wire);
  output = "\nBSEC library version " + String(iaqSensor.version.major) + "." + String(iaqSensor.version.minor) + "." + String(iaqSensor.version.major_bugfix) + "." + String(iaqSensor.version.minor_bugfix);
  Serial.println(output);
  checkIaqSensorStatus();
 
  bsec_virtual_sensor_t sensorList[10] =
  {
    BSEC_OUTPUT_RAW_TEMPERATURE,
    BSEC_OUTPUT_RAW_PRESSURE,
    BSEC_OUTPUT_RAW_HUMIDITY,
    BSEC_OUTPUT_RAW_GAS,
    BSEC_OUTPUT_IAQ,
    BSEC_OUTPUT_STATIC_IAQ,
    BSEC_OUTPUT_CO2_EQUIVALENT,
    BSEC_OUTPUT_BREATH_VOC_EQUIVALENT,
    BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE,
    BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY,
  };
 
  iaqSensor.updateSubscription(sensorList, 10, BSEC_SAMPLE_RATE_LP);
  checkIaqSensorStatus();
 
  // Print the header
  output = "Timestamp [ms], raw temperature [°C], pressure [hPa], raw relative humidity [%], gas [Ohm], IAQ, IAQ accuracy, temperature [°C], relative humidity [%], Static IAQ, CO2 equivalent, breath VOC equivalent";
  Serial.println(output);
}
 
// Function that is looped forever
void loop(void)
{
  unsigned long time_trigger = millis();
  if (iaqSensor.run()) // If new data is available
  {
    output = String(time_trigger);
    output += ", " + String(iaqSensor.rawTemperature);
    output += ", " + String(iaqSensor.pressure);
    output += ", " + String(iaqSensor.rawHumidity);
    output += ", " + String(iaqSensor.gasResistance);
    output += ", " + String(iaqSensor.iaq);
    output += ", " + String(iaqSensor.iaqAccuracy);
    output += ", " + String(iaqSensor.temperature);
    output += ", " + String(iaqSensor.humidity);
    output += ", " + String(iaqSensor.staticIaq);
    output += ", " + String(iaqSensor.co2Equivalent);
    output += ", " + String(iaqSensor.breathVocEquivalent);
    Serial.println(output);
 
    Serial.print("Pressure: ");
    Serial.print((iaqSensor.pressure)/1000);
    Serial.println(" hPa");
 
    Serial.print("Temperature: ");
    Serial.print(iaqSensor.temperature);
    Serial.println(" *C");
 
    Serial.print("Humidity: ");
    Serial.print(iaqSensor.humidity);
    Serial.println(" %");
 
    Serial.print("IAQ: ");
    Serial.print(iaqSensor.iaq);
    Serial.println(" PPM");
 
    Serial.print("CO2 Equivalent: ");
    Serial.print(iaqSensor.co2Equivalent);
    Serial.println(" PPM");
 
    Serial.print("Breath VOC Equivalent: ");
    Serial.print(iaqSensor.breathVocEquivalent);
    Serial.println(" PPM");
    Serial.println();
 
    Blynk.run(); // Initiates Blynk
    Blynk.virtualWrite(V0, (iaqSensor.pressure)/1000);        // For Pressure
    Blynk.virtualWrite(V1, iaqSensor.temperature);            // For Temperature
    Blynk.virtualWrite(V2, iaqSensor.iaq);                    //For Index of Air Quality
    Blynk.virtualWrite(V3, iaqSensor.co2Equivalent);          // For CO2
    Blynk.virtualWrite(V4, iaqSensor.breathVocEquivalent);    // For Breath VoC
    Blynk.virtualWrite(V5, iaqSensor.humidity);               // For Humidity
 
  }
  else
  {
    checkIaqSensorStatus();
  }
}
 
// Helper function definitions
void checkIaqSensorStatus(void)
{
  if (iaqSensor.bsecStatus != BSEC_OK) {
    if (iaqSensor.bsecStatus < BSEC_OK) {
      output = "BSEC error code : " + String(iaqSensor.bsecStatus);
      Serial.println(output);
      for (;;)
        errLeds(); /* Halt in case of failure */
    } else {
      output = "BSEC warning code : " + String(iaqSensor.bsecStatus);
      Serial.println(output);
    }
  }
  if (iaqSensor.bme68xStatus != BME68X_OK) {
    if (iaqSensor.bme68xStatus < BME68X_OK) {
      output = "BME68X error code : " + String(iaqSensor.bme68xStatus);
      Serial.println(output);
      for (;;)
        errLeds(); /* Halt in case of failure */
    } else {
      output = "BME68X warning code : " + String(iaqSensor.bme68xStatus);
      Serial.println(output);
    }
  }
}

void errLeds(void)
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
