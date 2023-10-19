//connect SDA TO SDA of OLED & SCL TO SCL of OLED
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup()   {  
  Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)// Check your I2C address and enter it here, in Our case address is 0x3C
  display.clearDisplay();
  display.display(); // this command will display all the data which is in buffer
}
void loop() { 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.println("SSG EMBEDED SOLUTIONS");
  display.display();
  delay(3000);
// drawing diagonal lines
  display.clearDisplay();
  display.drawLine(0,0,display.width() - 1, display.height() - 1, WHITE);
  display.drawLine(display.width() - 1,0,0, display.height() - 1, WHITE);
  display.display();
  delay(5000);
//drawing rectangles
  display.clearDisplay();
  display.drawRect(100, 10, 20, 20, WHITE);
  display.fillRect(10, 10, 45, 15, WHITE);
  display.drawRoundRect(60, 20, 35, 35, 8, WHITE);
  display.display();
  delay(5000);
//drawing circles
  display.clearDisplay();
  display.drawCircle(30, 15, 15, WHITE);
  display.fillCircle(25, 10, 2, WHITE);
  display.fillCircle(35, 10, 2, WHITE);
  display.display();
  delay(5000);
//drawing points
  display.clearDisplay();
  display.drawPixel(20, 35, WHITE);
  display.drawPixel(45, 12, WHITE);
  display.drawPixel(120, 59, WHITE);
  display.drawPixel(97, 20, WHITE);
  display.drawPixel(35, 36, WHITE);
  display.drawPixel(72, 19, WHITE);
  display.drawPixel(90, 7, WHITE);
  display.drawPixel(11, 29, WHITE);
  display.drawPixel(57, 42, WHITE);
  display.drawPixel(69, 34,  WHITE);
  display.drawPixel(108, 12, WHITE);
  display.display();
  delay(5000);
}
