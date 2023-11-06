// #include <Adafruit_NeoPixel.h>
// #include <Adafruit_CircuitPlayground.h>

// float value;

// #define LED_PIN           6  // Define the pin to which the LED strip is connected
// #define NUM_LEDS          30 // Define the number of LEDs in your LED strip

// Adafruit_NeoPixel strip (NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// void setup() {
//   CircuitPlayground.begin();
//   strip.begin();
//   strip.show(); // Initialize all pixels to 'off'
//   Serial.begin(9600);
// }

// void loop() {
//   // Take 10 milliseconds of sound data to calculate
//   value = CircuitPlayground.mic.soundPressureLevel(50);

//   // Print sound sensor value to the Serial Monitor
//   Serial.print("Sound Sensor SPL: ");
//   Serial.println(value);

//   // Map the sound sensor value to the LED strip color intensity
//   int mappedValue = map(value, 50, 120, 0, 255); // Adjust the range as needed

//   // Visualize sound on the LED strip
//   for (int i = 0; i < strip.numPixels(); i++) {
//     // Set color based on the mapped sound sensor value
//     strip.setPixelColor(i, strip.Color(255, 0, 0)); // Red color
//     strip.setBrightness(mappedValue);
//   }
//   strip.show();

//   delay(90); // Adjust delay as needed
// }

#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

float value;

#define LED_PIN           6  // Define the pin to which the LED strip is connected
#define NUM_LEDS          30 // Define the number of LEDs in your LED strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  CircuitPlayground.begin();
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void loop() {
  // Take 10 milliseconds of sound data to calculate
  value = CircuitPlayground.mic.soundPressureLevel(10);

  // Print sound sensor value to the Serial Monitor
  Serial.print("Sound Sensor SPL: ");
  Serial.println(value);

  // Map the sound sensor value to the number of LEDs to light up
  int numLEDsToLight = map(value, 40, 80, 0, NUM_LEDS);
  
  // Turn off all LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0)); // Turn off all LEDs
  }

  // Light up the corresponding number of LEDs
  for (int i = 0; i < numLEDsToLight; i++) {
    int red = random(256);   
    int green = random(256); 
    int blue = random(256);
    strip.setPixelColor(i, strip.Color(red, green, blue)); // Red color
  }
  strip.show();

  delay(100); // Adjust delay as needed
}





