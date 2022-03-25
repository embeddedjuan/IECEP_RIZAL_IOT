// Example 3.3 - ScrollingLED_POT.ino
byte LED_Pins[] = {0, 2, 4, 5, 12, 13, 14, 16};         // LED pins array
int LED_Delay;                                          // Delay between LED changes
int LED_direction = 1;                                  // Direction flag
int current_LED = 0;                                    // Initialize LED direction
int pot_Pin = 34;                                       // A1 is input pin for the potentiometer
unsigned long elapsed_Time;                             // Elapsed time value for millis

void setup() 
{
    for (int x=0; x<8; x++) 
    {                                                   // Loop to set all pins to output
        pinMode(LED_Pins[x], OUTPUT); 
    }
        elapsed_Time = millis();                        // Equate elapsedTime to millis()
}

void loop() 
{
    LED_Delay = analogRead(pot_Pin);                    // Read the value from the pot in A1

    if ((millis() - elapsed_Time) > LED_Delay) 
    {                                                   // LED_Delay ms since last change
      change_LED();
      elapsed_Time = millis();
    }
}

void change_LED() 
{


    for (int x=0; x<8; x++) {                           // Turn OFF all LED's
       digitalWrite(LED_Pins[x], LOW);
    }
    digitalWrite(LED_Pins[current_LED], HIGH);          // Turn ON the current LED
    current_LED += LED_direction;                       // Increment by the direction value
                                                        // Change direction if we reach the end
    if (current_LED == 7) {LED_direction = -1;}
    if (current_LED == 0) {LED_direction = 1;}
}
