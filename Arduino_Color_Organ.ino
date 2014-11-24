#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 86

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);


void setup(){
  //Initialize the serial connection, 9.6k bps
  Serial.begin(9600);
  strip.begin();

}

void loop(){
  int blueValue = analogRead(A5);
  //Blue wire gives the low freq value. Read from analog pin zero. There is a base value of 400 subtracted.
  int greenValue = analogRead(A2);
  //Green wire gives the mid freq value. Read from analog pin two. There is a base value of 400 subtracted.
  int yellowValue = analogRead(A0);
  //Yellow wire gives the high freq value. Read from analog pin four. There is a base value of 400 subtracted.
/*Serial.print("Low/blue: ");
  Serial.print(blueValue);
  Serial.print(" Mid/green: ");
  Serial.print(greenValue);
  Serial.print(" High/yellow: ");
  Serial.println(yellowValue);
  delay(100);
*/
  /* 
  The low values
  */
  blueValue = blueValue/random(4, 10);
  greenValue = greenValue/random(4, 12);
  yellowValue = yellowValue/random(4, 14);

  for (int i = 0; i < 28; i++)
  {
    strip.setPixelColor(i, blueValue, random(200, 255), blueValue);
    strip.show();
  }
  
  for (int j = 29; j < 59; j++)
  {
    strip.setPixelColor(j, greenValue, random(200,255), greenValue);
    strip.show();
  }
  
  for (int k = 60; k < 86; k++)
  {
    strip.setPixelColor(k, yellowValue, random(200,255), yellowValue);
    strip.show();
  }
  
  
}

  
  
  
  
  

