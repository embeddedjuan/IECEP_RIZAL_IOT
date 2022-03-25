// Example 4.1 LED_Button1_8266.ino
// ESP8266 Pins to be used
int pin_LED0 = D0;                       // LED in pin D0
int pin_Button3 = D3;                    // Push Button in D3
 
void setup() 
{
    
    pinMode(pin_LED0, OUTPUT);          // Initialize pin D0 to output
    digitalWrite(pin_LED0,LOW);         // Initialize pin D0 LOW during start
    pinMode(pin_Button3, INPUT);        // Initialize pin D3 as digital input 
}
 
void loop()
{
    if ( digitalRead(pin_Button3) == LOW)// If push button was pressed
    {
       digitalWrite(pin_LED0, HIGH);     // LED pin D0 ON
    }
    else
    {
       digitalWrite(pin_LED0, LOW);      // If not pressed, pin D0 OFF
    }  
}
