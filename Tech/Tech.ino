int ledPin1 = 8; // red light: call
int ledPin2 = 9; // yellow light: abort
int ledPin3 = 10; // bluetooth not connected
int ledPin4 = 11; //bluetooth connected
int inPin1 = 7;  // button 1
int inPin2 = 6; // button 2
int inPin3 = 5; // ABORT button
int val = 0; // val to be used later
int count = 10; // count down from 10 for Safelet

void setup() {
  pinMode(ledPin1, OUTPUT); // declare LED as output
  pinMode(ledPin2, OUTPUT); // declare LED as output
  pinMode(ledPin3, OUTPUT); // declare LED as output
  pinMode(ledPin4, OUTPUT); // declare LED as output
  pinMode(inPin1, INPUT);   // declare pushbutton as input
  pinMode(inPin2, INPUT); // declare pushbutton as input
  pinMode(inPin3, INPUT); // declare pushbutton as input
  Serial.begin(9600);
}

void loop(){  
  // Code for two buttons:
  val = ( digitalRead(inPin1) & digitalRead(inPin2) );  // if two buttons are PRESSED:
  if (val == LOW) {         // once the one of the two buttons are released
    digitalWrite(ledPin1, LOW); // turn LED OFF if both buttons aren't pressed
  } 
  
  else if (val == HIGH){ // while both buttons are pressed
    digitalWrite(ledPin1, HIGH);  // turn LED ON
    delay(500);
    digitalWrite(ledPin1, LOW); // turn LED OFF
    delay(500);
    Serial.println("Authorities will be notified in 10 seconds"); // print to serial 

    // Continue blinking and counting down
    while (val == HIGH){
    digitalWrite(ledPin1, HIGH);  // turn LED ON
    delay(500);
    digitalWrite(ledPin1, LOW);
    delay(500);
    Serial.println(count); // display the COUNT
    
    if (digitalRead(inPin3) == HIGH) // if the ABORT button is pressed
      {
        digitalWrite(ledPin2, HIGH); //light up the LED
        delay(1000); // delay
        Serial.println("Call has been aborted"); // display in serial
        digitalWrite(ledPin2, LOW); // turn off LED
        val = LOW; // set VAL to low to start over
        count = 11; // count set to 11 because the loop does count = count - 1 automatically
      }

    if (count==0) // once the counter gets down to 0
      {
       Serial.println("Authorities have been notified. Help is on the way."); // authorities have been notified
       val = LOW; // set VAL to low to start over
       count = 11; // count set to 11 because the loop does count = count - 1 automatically
      }
    
    count = count - 1; // counter deducted by 1 as it goes through the loop again
    
    }
    
  }
}
