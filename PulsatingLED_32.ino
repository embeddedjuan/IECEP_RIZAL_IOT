// Example 3.4 - PulsatingLED.ino
const int ledPin = 16;                        // Pin 3 PWM output  
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;    
//float sine_Val;                         // Sine values
//int LED_Val;                            // LED vales


void setup() 
{
  
    //pinMode(ledPin, OUTPUT);           // Initialize LED_Pin to output
    // configure LED PWM functionalitites
    ledcSetup(ledChannel, freq, resolution);
  
    // attach the channel to the GPIO to be controlled
    ledcAttachPin(ledPin, ledChannel);

}

void loop() 
{
    // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
}
