// Example 3.8 - LEDEffectsButton_32.ino
int LED_12 = 14;
int LED_11 = 13;
int LED_10 = 12;
int LED_9 = 5;
int LED_8 = 4;
int LED_7 = 2;
int LED_6 = 0;  

int buttonPin_5 = 16;  //the number of the pushbutton pin

int delay_time = 100;  // time delay

int p = 0;             // variable for pattern

bool buttonState = 1;  // variable for reading the pushbutton status

void setup() 
{
  pinMode(LED_12, OUTPUT);
  pinMode(LED_11, OUTPUT);
  pinMode(LED_10, OUTPUT);
  pinMode(LED_9, OUTPUT);
  pinMode(LED_8, OUTPUT);
  pinMode(LED_7, OUTPUT);
  pinMode(LED_6, OUTPUT);
  
  pinMode(buttonPin_5, INPUT);
}

void loop() 
{
  
 buttonState = digitalRead(buttonPin_5);

 if (buttonState == LOW)
 
    {
      p++;
      delay(50);
    } 

  if(p==1)
  {
 digitalWrite(LED_12,1); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //1
 delay(delay_time);  
  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,1); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //2
 delay(delay_time); 
digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,1); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //3
 delay(delay_time); 
  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,1); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //4
 delay(delay_time); 
  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,1); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //5
 delay(delay_time); 
  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,1); 
 digitalWrite(LED_6,0);  //6
 delay(delay_time); 
digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,1);  //7
 delay(delay_time); 
  }
  if(p==2)
  {
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,1);  //7
 delay(delay_time); 
  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,1); 
 digitalWrite(LED_6,0);  //6
 delay(delay_time);
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,1); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //5
 delay(delay_time); 
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,1); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //4
 delay(delay_time);  
 
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,1); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //3
 delay(delay_time);  
 
 
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,1); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //2
 delay(delay_time); 
  
 digitalWrite(LED_12,1); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //1
 delay(delay_time);  
  
  }
    if(p==3)
  {
 digitalWrite(LED_12,1); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //1
 delay(delay_time);  
  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,1); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //2
 delay(delay_time); 
  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,1); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //3
 delay(delay_time); 
 
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,1); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //4
 delay(delay_time); 
  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,1); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //5
 delay(delay_time); 

 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,1); 
 digitalWrite(LED_6,0);  //6
 delay(delay_time);

 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,1);  //6
 delay(delay_time);

 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,1); 
 digitalWrite(LED_6,0);  //6
 delay(delay_time);
 
 
 
  digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,1); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //5
 delay(delay_time); 
  
  digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,1); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //4
 delay(delay_time);  
 
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,1); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //3
 delay(delay_time);  

 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,1); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //2
 delay(delay_time); 

 
 digitalWrite(LED_12,1); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //1
 delay(delay_time);  
 
}
    if(p==4)
  {
 digitalWrite(LED_12,1); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,1);  //1,7
 delay(delay_time);  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,1); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,1); 
 digitalWrite(LED_6,0);  //2,6
 delay(delay_time); 
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,1); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,1); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //3,5
 delay(delay_time);  
digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,1); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //4
 delay(delay_time); 
 
  }
  
      if(p==5)
  {
 
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,1); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //4
 delay(delay_time); 
  
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,1); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,1); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //3,5
 delay(delay_time);  
digitalWrite(LED_12,0); 
 digitalWrite(LED_11,1); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,1); 
 digitalWrite(LED_6,0);  //2,6
 delay(delay_time); 
    
 digitalWrite(LED_12,1); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,1);  //1,7
 delay(delay_time);  
  }
 
if(p==6)
{
 digitalWrite(LED_12,1); 
 delay(delay_time); 
 digitalWrite(LED_11,1); 
 delay(delay_time); 
 digitalWrite(LED_10,1);
 delay(delay_time);  
 digitalWrite(LED_9,1);
 delay(delay_time);  
 digitalWrite(LED_8,1);
 delay(delay_time);  
 digitalWrite(LED_7,1);
 delay(delay_time);  
 digitalWrite(LED_6,1);  //1,7
 delay(delay_time); 
 digitalWrite(LED_6,0);  //1,7
 delay(delay_time); 
 digitalWrite(LED_7,0);
 delay(delay_time); 
 digitalWrite(LED_8,0);
 delay(delay_time); 
 digitalWrite(LED_9,0);
 delay(delay_time); 
 digitalWrite(LED_10,0);
 delay(delay_time); 
 digitalWrite(LED_11,0);
 delay(delay_time); 
 digitalWrite(LED_12,0);
 delay(delay_time); 
 
}  
 
 if(p==7)
{
 digitalWrite(LED_12,0); 
 digitalWrite(LED_11,0); 
 digitalWrite(LED_10,0); 
 digitalWrite(LED_9,0); 
 digitalWrite(LED_8,0); 
 digitalWrite(LED_7,0); 
 digitalWrite(LED_6,0);  //1,7
 delay(delay_time);
  p=0;

}

buttonState = 1;
}
 
