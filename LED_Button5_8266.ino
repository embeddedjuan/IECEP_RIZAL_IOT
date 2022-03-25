//  Example 4.5 - LED_Button5_8266.ino
//
//  Example of using a single button switch to set multiple states or conditions
//
//  D0-red LED
//  D1-green LED
//  D2-yellow LED
//  D3-push button 
//  
//  state holds the current status.
//  0 = all off.
//  1 = green LED
//  2 = yellow LED
//  3 = red LED
 
// Define the pins being used
int pin_LED1green =   D1;
int pin_LED2yellow =  D2;
int pin_LED0red =     D0;
 
int pin_Button3 = D3;
 
// new and old switch states
boolean oldButtonState = HIGH;
boolean newButtonState1 = HIGH;
boolean newButtonState2 = HIGH;
boolean newButtonState3 = HIGH;
 
byte state = 0;
 
void setup() 
{
    
    pinMode(pin_LED1green, OUTPUT);    digitalWrite(pin_LED1green,LOW); 
    pinMode(pin_LED2yellow, OUTPUT);   digitalWrite(pin_LED2yellow,LOW); 
    pinMode(pin_LED0red, OUTPUT);      digitalWrite(pin_LED0red,LOW); 
    pinMode(pin_Button3, INPUT); 
}
 
void loop()
{
    newButtonState1 = digitalRead(pin_Button3);
    delay(1);
    newButtonState2 = digitalRead(pin_Button3);
    delay(1);
    newButtonState3 = digitalRead(pin_Button3);
 
    // if all 3 values are the same we can continue
    if (  (newButtonState1==newButtonState2) && (newButtonState1==newButtonState3) )
    {
 
        if ( newButtonState1 != oldButtonState ) 
        {
 
           // has the button switch been closed?
           if ( newButtonState1 == LOW )
           {
                // increase the value of state
                state++;
                if (state > 3) { state = 0; }
 
// turn all LEDs off. Doing it this way means we do not need to care about the individual LEDs
                // simply turn them all off and then turn on the correct one. 
                digitalWrite(pin_LED1green, LOW);
                digitalWrite(pin_LED2yellow, LOW);
                digitalWrite(pin_LED0red, LOW);
 
                // Turn on the next LED
                // Because the value of state does not change while we are testing it we don't need to use else if
                if (state==1) { digitalWrite(pin_LED1green, HIGH);  }
                if (state==2) { digitalWrite(pin_LED2yellow, HIGH);  }
                if (state==3) { digitalWrite(pin_LED0red, HIGH);  }
 
           }
           oldButtonState = newButtonState1;
        }  
    }
}


 
