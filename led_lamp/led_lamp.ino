/*
  LED Lamp with Button Control
  ----------------------------
  This code cycles an LED through four brightness levels (OFF, DIM, MEDIUM, FULL)
  each time a push button is pressed. After FULL BRIGHTNESS, it resets to OFF.
  
  Written by: Shaan
*/

#define LED 9       // Adding macro for LED for pin ~9
#define button 13   // Adding macro for button for pin 13

int stage = 0;      // Defining an integer variable named stage to indicate the level
int prev_state = 1; // Integer for previous state of the button
int b_state = 0;    // Integer for storing current state of the button

void setup() {

  pinMode(LED, OUTPUT);           // Initializing LED as an OUTPUT sourse
  pinMode(button, INPUT_PULLUP);  // Initializing button as the internal input pullup

}

void loop() {

  b_state = digitalRead(button);        // Live updating the button state variable to current button state

  if(b_state == 0 && prev_state == 1){  // Detects a new button press
    stage = (stage + 1) % 4;            // Increases the stage variable by one
    delay(250);                         // Delay by 250 ms so debounce doesn't happen
  }

  prev_state = b_state;       // Sets the previous state to the currnet state of the button

  if(stage == 0){             // Sets the PWM value to 0 (OFF)
    analogWrite(LED, 0);
  }
  if(stage == 1){             // Sets the PWM value to 50 (DIM)
    analogWrite(LED, 50);
  }
  if(stage == 2){             // Sets the PWM value to 130 (MEDIUM)
    analogWrite(LED, 130);
  }
  if(stage == 3){             // Sets the PWM value to 255 (FULL BRIGHTNESS)
    analogWrite(LED, 255);
  }
}
