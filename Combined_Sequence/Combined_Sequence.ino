#include <FastLED.h>
// Create 4 array's of LED's with 81 LEDs each
#define NUM_STRIPS 4
#define NUM_LEDS_PER_STRIP 24
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];
CRGB redStrip[NUM_LEDS_PER_STRIP];

// Define active state of pins vs inactive pins
// Sometimes inputs can be flipped, so this saves time changing the values of input and output in the loop
#define PIN_ACTIVE  1
#define PIN_INACTIVE 0

// Intialize random numbers for random LED pattern
long randNumber1;
long randNumber2;
long randNumber3;

// Setup the different strips of LEDs 
void setup() {
  // Set the brightness of the LED Strips in order to avoid overloading the board
  FastLED.setBrightness(50);
  // tell FastLED library what pin the LED strips are on
  FastLED.addLeds<NEOPIXEL, 12>(leds[0], NUM_LEDS_PER_STRIP);
  // Define which input pins to pull the DIO value of the RIO From
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    pinMode(4,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
}
// Define Different LED patterns
void CLEAR(){
  // Create Clear LED pattern, setting all LEDs in the strip to no value
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++){
      FastLED.clear();
    }
}
void REDALLIANCE()
  // Set all LEDs in the Strip to the color Red 
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(255,0,0);
            FastLED.show();
        }
  }
void CONEREQUEST()
// Move up the array of LEDs, wait 500 milliseconds (half a second), and clear the array and repeat
{
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(230,100,1);
            FastLED.show();
            
            
  }
        FastLED.delay(500);
        CLEAR();
}
void CONEAQUIRED()
// Set all the LEDs in the Array to Yellow
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(230,100,1);
            FastLED.show();
        }
  }
void CUBEREQUEST()
// Set all the LEDs in the Array to Purple, wait half a second, and then clear all the LEDs and Repeat
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(20,0,25);
            FastLED.show();
        }
        FastLED.delay(500);
        CLEAR();
  }
void CUBEAQUIRED()
// Set all the LEDs in the Array to Purple
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(20,0,25);
            FastLED.show();
        }
  }
void DISABLED()
// Set all the LEDs in the Array to Orange (Disalbed)
// TODO: Check if the Color is the same as the disabled color on the robot, or at least close to it
  {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            leds[0][i] = CRGB(255,0,0);
            FastLED.show();
        }
  }
void BLUEALLIANCE()
// Set all the LEDs in the array to Blue
  {
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++)
  {
          leds[0][i] = CRGB(0,0,255);
          FastLED.show();
      }
  }
// void TEAMCOLORS()
// {
//   for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
//             leds[0][i] = CRGB(0,0,255);
//             delay(25);
//             FastLED.show();
//         }
//   FastLED.delay(250);
//   for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
//             leds[0][i] = CRGB(255,255,255);
//             delay(25);
//             FastLED.show();
//         }
//   FastLED.delay(250);
//   for(int i = 81; i >= 0; i--) {
//             leds[0][i] = CRGB(0,0,255);
//             delay(25);
//             FastLED.show();
//         }
//   FastLED.delay(250);
//   for(int i = 81; i >= 0; i--) {
//             leds[0][i] = CRGB(255,255,255);
//             delay(25);
//             FastLED.show();
//         }
//   FastLED.delay(250);
// }

void RANDOMLIGHTS(){
  // Pick a random number from 0 to 255 and set each of the rgb values to one of the random valuesd
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
            
            randNumber1 = random(0, 255);
            randNumber2 = random(0,225);
            randNumber3 = random(0,225);
            leds[0][i] = CRGB(randNumber1,randNumber2,randNumber3);
            
            FastLED.show();
        }
}
void AUTOBALANCE(){
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
               
}
}
void loop(){
 
  // Initialize digital Read pins
  int pin2 = digitalRead(2);
  int pin3 = digitalRead(3);
  int pin4 = digitalRead(4);
  int pin5 = digitalRead(5);
  
   
    
    // If statements determining which pattern is being sent from the RIO w/ DIO
    // Look at variable declaration of PIN_INACTIVE/PIN_ACTIVE for information
    if(pin2 == PIN_INACTIVE && pin3 == PIN_INACTIVE && pin4 == PIN_INACTIVE && pin5 == PIN_INACTIVE){
      DISABLED();
    }
    // else if(pin2 == PIN_ACTIVE && pin3 == PIN_ACTIVE && pin4 == PIN_ACTIVE && pin5 == PIN_ACTIVE){
    //   TEAMCOLORS();
    // }
    else if(pin2 == PIN_ACTIVE && pin3 == PIN_ACTIVE && pin4 == PIN_INACTIVE && pin5 == PIN_INACTIVE){
      BLUEALLIANCE();
    }
    else if(pin2 == PIN_ACTIVE && pin3 == PIN_ACTIVE && pin4 == PIN_ACTIVE && pin5 == PIN_INACTIVE){
      REDALLIANCE();
    }
    else if(pin2 == PIN_ACTIVE && pin3 == PIN_INACTIVE && pin4 == PIN_INACTIVE && pin5 == PIN_INACTIVE){
      CONEREQUEST();
    }
    else if(pin2 == PIN_INACTIVE && pin3 == PIN_INACTIVE && pin4 == PIN_INACTIVE && pin5 == PIN_ACTIVE){
      CONEAQUIRED();
    }
    else if(pin2 == PIN_INACTIVE && pin3 == PIN_ACTIVE && pin4 == PIN_INACTIVE && pin5 == PIN_INACTIVE){
      CUBEREQUEST();
    }
    else if(pin2 == PIN_INACTIVE && pin3 == PIN_INACTIVE && pin4 == PIN_ACTIVE && pin5 == PIN_INACTIVE){
      CUBEAQUIRED();
    }
    else if(pin2 == PIN_INACTIVE && pin3 == PIN_INACTIVE && pin4 == PIN_ACTIVE && pin5 == PIN_ACTIVE){
      RANDOMLIGHTS();      
    }
    else if(pin2 == 1 && pin3 == 0 && pin4 == 1 && pin5 == 0){
      AUTOBALANCE();
    }
    else{
      DISABLED();
    }
    

}

