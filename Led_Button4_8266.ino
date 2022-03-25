//  Example 4.4 - Led_Button4_8266.ino
//  Using a button switch as a toggle switch to turn an LED on or off
//  with a simple debounce
 
// Define the pins being used
int pin_LED0 = D0;
int pin_Button3 = D3;
 
// new and old switch states
boolean oldButton3State = HIGH;
boolean newButton3State1 = HIGH;
boolean newButton3State2 = HIGH;
boolean newButton3State3 = HIGH;

// LED0 state
boolean LED0state = LOW;
 
void setup() 
{
    pinMode(pin_LED0, OUTPUT);  
    digitalWrite(pin_LED0,LOW); 
    pinMode(pin_Button3, INPUT); 
}
 
void loop()
{
    newButton3State1 = digitalRead(pin_Button3);
    delay(1);
    newButton3State2 = digitalRead(pin_Button3);
    delay(1);
    newButton3State3 = digitalRead(pin_Button3);
 
    // if all 3 values are the same we can continue
    if (  (newButton3State1==newButton3State2) && (newButton3State1==newButton3State3) )
    {
 
        if ( newButton3State1 != oldButton3State ) 
        {
 
           // has the button switch been closed?
           if ( newButton3State1 == LOW )
           {
               if ( LED0state == LOW ) 
               {  
                  digitalWrite(pin_LED0, HIGH);  
                  LED0state = HIGH; 
               }
               else                    
               { 
                  digitalWrite(pin_LED0, LOW);   
                  LED0state = LOW;  
               }
           }
           oldButton3State = newButton3State1;
        }  
    }
}
