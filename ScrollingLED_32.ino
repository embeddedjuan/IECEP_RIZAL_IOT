// Example 3.2 - ScrollingLED_32.ino
byte LED_Pins[] = {0, 2, 4, 5, 12, 13, 14, 16};      // LED pins array
int LED_Delay(200);                                      // Delay between LED changes
int LED_direction = 1;                                  // Direction flag
int current_LED = 0;                                    // Initialize LED direction
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
    if ((millis() - elapsed_Time) > LED_Delay) 
    {                                                   // LED_Delay ms since last change
      change_LED();
      elapsed_Time = millis();
    }
}

void change_LED() {
    for (int x=0; x<8; x++) {                          // Turn OFF all LED's
       digitalWrite(LED_Pins[x], LOW);
    }
    digitalWrite(LED_Pins[current_LED], HIGH);           // Turn ON the current LED
    current_LED += LED_direction;                       // Increment by the direction value
                                                        // Change direction if we reach the end
    if (current_LED == 7) {LED_direction = -1;}
    if (current_LED == 0) {LED_direction = 1;}
}
