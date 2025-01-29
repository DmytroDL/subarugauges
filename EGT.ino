 #include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <GyverMAX6675.h>

#define CLK_PIN   2  // Пин SCK
#define DATA_PIN  4  // Пин SO
#define CS_PIN    3  // Пин CS

U8G2_SSD1306_64X32_1F_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;

void setup() {
  Serial.begin(9600);
  u8g2.begin();
  u8g2.clearDisplay();
}

void loop()
{
  String inc;
  inc = sens.getTemp();
  u8g2.clearDisplay();
  u8g2.setFont(u8g2_font_t0_22_tf);  // choose a suitable font
  u8g2.setCursor(8, 22);
  u8g2.print(inc);
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(1000);
}