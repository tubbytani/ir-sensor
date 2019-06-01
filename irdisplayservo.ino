#include <Wire.h> 
#include <Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include<SPI.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup(){
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  pinMode(7,INPUT);
  Serial.begin(9600);
}
void loop()
{display.clearDisplay();
 display.setTextColor(WHITE);
display.setCursor(0,0);
 display.print("IR Sensor reading ");

delay(1000);

 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
   // in steps of 1 degree
   myservo.write(pos); 
   if(digitalRead(7)!=0)
   display.print("1");
   display.display();
    delay(15);   
      // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      // tell servo to go to position in variable 'pos'
   myservo.write(pos);
    if(digitalRead(7)!=0)
   display.print("1");
   display.display();
   
    delay(15);                       // waits 15ms for the servo to reach the position
  }

}
