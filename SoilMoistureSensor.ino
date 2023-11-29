/*
  ESP32 Soil Moisture Sensor
  http:://www.electronicwings.com
*/

int humtierra,sensor_analog;
const int sensor_pin = 00;  /* Soil moisture sensor O/P pin */

void setup(void){
  Serial.begin(115200);     /* Set the baudrate to 115200*/
  pinMode(12,OUTPUT);
}

void loop(void){
  sensor_analog = analogRead(sensor_pin);
  humtierra = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  Serial.print("Humedad = ");
  Serial.print(humtierra);  /* Print Temperature on the serial window */
  if(humtierra>=25)
  digitalWrite(12,HIGH);
  else
  digitalWrite(12,LOW);
  Serial.println("%");
  delay(1000);              /* Wait for 1000mS */
}
