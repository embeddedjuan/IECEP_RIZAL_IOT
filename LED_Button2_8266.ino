//  Example 4.2 - LED_Button2_8266.ino
//  Turning an LED in pin 8 on and off using a button switch in pin 2

// Arduino pins being used
int pin_LED0 = D0;
int pin_Button3 = D3;
 
// Variables new and old button states
boolean oldButton3State = HIGH;
boolean newButton3State = HIGH;
 
void setup() 
{
    pinMode(pin_LED0, OUTPUT);  
    digitalWrite(pin_LED0,LOW); 
    pinMode(pin_Button3, INPUT); 
}
 
void loop()
{
    newButton3State = digitalRead(pin_Button3);
 
    if ( newButton3State != oldButton3State ) 
    {
       if ( newButton3State == LOW ) 
       {
        digitalWrite(pin_LED0, HIGH); 
       }
       else             
       { 
        digitalWrite(pin_LED0, LOW);  
       }
 
       oldButton3State = newButton3State;
    }   
}
