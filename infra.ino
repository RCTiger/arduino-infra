#include <IRremote.h>

/**
 * Infra bemeneti port
 */
int irPin = 2;

/**
 * Led beállítások
 * ledPin - led vezérlő pin
 * ledBrightness - A led alap fényereje
 * brightnessChange - A led fényeréjének változásának mértéke
 */
int ledPin = 5;
int ledBrightness = 0;
int brightnessChange = 20;

IRrecv irrecv(irPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
  
    switch (results.value) {
  
      case 16753245: // Ki/be kapcsolás
        if (ledBrightness == 0) {
          ledBrightness = 255;
        } else {
          ledBrightness = 0;
        }
      break;
      
      case 16748655: // Plus
        ledBrightness = ledBrightness + brightnessChange;
        if (ledBrightness > 255) {
          ledBrightness = 255;
        }
      break;
  
      case 16754775: // Minus
        ledBrightness = ledBrightness - brightnessChange;
        if (ledBrightness < 0) {
          ledBrightness = 0;
        }
      break;
  
      case 16750695: // Random
        ledBrightness = random(0,255);
      break;
  
      case 16738455: // 0
        ledBrightness = 0;
      break;
  
      case 16724175: // 1
        ledBrightness = (int)(255 / 9 * 1);
      break;
  
      case 16718055: // 2
        ledBrightness = (int)(255 / 9 * 2);
      break;
  
      case 16743045: // 3
        ledBrightness = (int)(255 / 9 * 3);
      break;
  
      case 16716015: // 4
        ledBrightness = (int)(255 / 9 * 4);
      break;
  
      case 16726215: // 5
        ledBrightness = (int)(255 / 9 * 5);
      break;
  
      case 16734885: // 6
        ledBrightness = (int)(255 / 9 * 6);
      break;
  
      case 16728765: // 7
        ledBrightness = (int)(255 / 9 * 7);
      break;
  
      case 16730805: // 8
        ledBrightness = (int)(255 / 9 * 8);
      break;
  
      case 16732845: // 9
        ledBrightness = 255;
      break;
    }
    
    analogWrite(ledPin, ledBrightness);
    irrecv.resume();

  }
}
