#include <GyverMAX6675.h>

#define CLK_PIN   2  // Пін SCK
#define DATA_PIN  4  // Пін SO
#define CS_PIN    3  // Пін CS

GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;

void setup() {
  Serial.begin(9600);
}

void loop()
{
  Serial.println(sens.getTemp());
  delay(1000);
}
