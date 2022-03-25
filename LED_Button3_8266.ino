//  Example 4.3 - LED_Button3_8266.ino
//  Button switch as a toggle switch to turn an LED on or off

 
// Define the pins being used
int pin_LED0 = D0;
int pin_Button3 = D3;
 
// Variables of new and old button states
boolean oldButton3State = HIGH;
boolean newButton3State = HIGH;
 
boolean LED0state = LOW;
 
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
       // if pin_Button3 pressed
       if ( newButton3State == LOW )
       {
           if ( LED0state == LOW ) 
           { digitalWrite(pin_LED0, HIGH);  
           LED0state = HIGH; 
           }
           else                    
           { digitalWrite(pin_LED0, LOW);   
           LED0state = LOW;  
           }
       }
       oldButton3State = newButton3State;
    }   
}
