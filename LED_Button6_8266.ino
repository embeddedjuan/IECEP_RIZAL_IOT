//  Example 4.6 - LED_Button6_8266.ino
//  Example of using a single button switch to set multiple states or conditions
//
//  Pins
//  D1-green LED
//  D2-yellow LED
//  D0-red LED
//  D3-push button 
//  
//  state holds the current status.
//  0 = all off.
//  1 = green LED
//  2 = yellow LED
//  3 = red LED
 
// Define the pins being used fro the LEDs green/yellow/red
char LED_Pins_array[] = { 5, 4, 16};
 
// Array to hold the LED sequence. green, yellow, red, green.
// position 0 is not used (considered not good practice but keeps the code easy to understand)
char LED_Sequence_array[] = { 5, 4, 16, 5};
byte sequenceLength = 4;
 
int pin_Button3 = 0;
 
// variables to hold the new and old switch states
boolean oldSwitchState = HIGH;
boolean newSwitchState1 = HIGH;
boolean newSwitchState2 = HIGH;
boolean newSwitchState3 = HIGH;
 
byte state = -1;
 
void setup() 
{
    
    for (byte i=0; i< 3; i++)
    {    
         pinMode(LED_Pins_array[i], OUTPUT);    
         digitalWrite(LED_Pins_array[i],LOW); 
    }
         pinMode(pin_Button3, INPUT); 
}
 
void loop()
{
    newSwitchState1 = digitalRead(pin_Button3);
    delay(1);
    newSwitchState2 = digitalRead(pin_Button3);
    delay(1);
    newSwitchState3 = digitalRead(pin_Button3);
 
    // if all 3 values are the same we can continue
    if (  (newSwitchState1==newSwitchState2) && (newSwitchState1==newSwitchState3) )
    {
        if ( newSwitchState1 != oldSwitchState ) 
        {
 
           // has the button switch been closed?
           if ( newSwitchState1 == LOW )
           {
                state++;
                if (state > (sequenceLength -1) ) { state = 0; }
 
                // turn all LEDs off. Doing it this way means we do not need to care about the individual LEDs
                // simply turn them all off and then turn on the correct one. 
                for (byte i=0; i< 3; i++)
                {
                     digitalWrite(LED_Pins_array[i],LOW); 
                }
 
                // Turn on the next LED
                digitalWrite(LED_Sequence_array[state],HIGH); 
           }
           oldSwitchState = newSwitchState1;
        }  
    }
}
