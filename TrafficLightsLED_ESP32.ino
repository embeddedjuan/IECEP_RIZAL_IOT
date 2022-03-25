// Example 3.1 - TrafficLightsLED_ESP32.ino

int LED_DELAY = 10000;       //Traffic Lights Delay
int RED_LED = 5;            //Set RED_LED to pin 5
int YELLOW_LED = 4;         //Set RED_LED to pin 4
int GREEN_LED = 0;          //Set RED_LED to pin 3

void setup() 
{
  
pinMode(RED_LED, OUTPUT);            //Initilalize RED_LED to output
pinMode(YELLOW_LED, OUTPUT);         //Initialize YELLOW_LED to output
pinMode(GREEN_LED, OUTPUT);          //Initialize GREEN_LED to output

}

void loop() 
{
  
digitalWrite(RED_LED, HIGH);          // RED_LED ON
delay(LED_DELAY);                     // 10 seconds delay
digitalWrite(YELLOW_LED, HIGH);       // YELLOW_LED ON
delay(2000);                          // 2 seconds delay
digitalWrite(GREEN_LED, HIGH);        // GREEN_LED ON
digitalWrite(RED_LED, LOW);           // RED_LED OFF
digitalWrite(YELLOW_LED, LOW);        // YELLOW_LED OFF
delay(LED_DELAY);                     // 10 seconds delay
digitalWrite(YELLOW_LED, HIGH);       // YELLOW_LED ON
digitalWrite(GREEN_LED, LOW);         // GREEN_LED OFF
delay(2000);                          // 2 seconds delay
digitalWrite(YELLOW_LED, LOW);        // YELLOW_LED OFF
                                      // loop forever
}
