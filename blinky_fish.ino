/*Combines code from "Getting Started with Arduino" by Massimo Banzi
http://shop.oreilly.com/product/9780596155520.do */


int button = 12; //button on pin 12
int pullup = 13; // use pullup on pin 13

int button_state = 0; // see if button has been pressed
int val = 0; // used to store the state of the input pin
int old_val = 0; // previous value of "val"
int delay_time = 109; // how fast or slow the leds blink

void setup(){
  // set up leds as output
  for (int i = 11; i > 8; i--){
    pinMode(i, OUTPUT);
  }
  pinMode(button, INPUT); //set up button as input
  digitalWrite(pullup, HIGH); // set up the pullup to be on
}

void loop(){
 {
 val = digitalRead(button); //read if the button is pressed
 
 //check to see if there is a change
  if ((val == HIGH) && (old_val == LOW)) {
    button_state = 1 - button_state;
    delay(10);
  }
  old_val = val;
  if (button_state == 1){
    for (int i = 11; i > 8; i--){
    digitalWrite(i, LOW); // if the leds are on and the button is pressed, turn them off
  }
  }
  else {
    blinky_fish(); // if the leds are off and the button is pressed, turn them on
  }
  }
}

void blinky_fish(){
  //blink the leds on and off in sequence like KITT in Knight Rider (aka Larsen Scanner)
  
  for (int i = 11; i > 8; i--){
    digitalWrite(i, HIGH);
    delay(delay_time);
    digitalWrite(i, LOW);
  }
  for (int i = 9; i < 11; i++){
    digitalWrite(i, HIGH);
    delay(delay_time);
    digitalWrite(i, LOW);
  }
}
 
  
