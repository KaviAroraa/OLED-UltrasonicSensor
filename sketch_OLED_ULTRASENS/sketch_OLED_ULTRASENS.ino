#include <Wire.h> //DO THIS
#include <Adafruit_GFX.h> //We downloaded these 2 libraries and then imported them into the file
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 //Reset pin (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3c // I2C (InterIntegrated circuit) address for the display

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;
const int trigPin = 5;
const int echoPin = 18;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //initialises the type of display used
void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,10); //sets the start position on a coordinate plane
//  display.println("Hello there.");
//  display.println("How are you?");
  display.display();

  Serial.begin(115200); //Starts serial communication
  pinMode(trigPin, OUTPUT); //Sets the trigPin as an Output
  pinMode(echoPin, INPUT); //Sets the echoPin as an Input
}

void loop() {
  digitalWrite(trigPin, LOW); //Clears the trigPin
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); //Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //Reads the echoPin, returns the sound wave travel time in microseconds

  distanceCm = duration * SOUND_SPEED/2; //Calculates the distance

 // Serial.println(distanceCm);
 
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println("Hello");
  display.display();
  
  display.display();
}

