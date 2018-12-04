int SER_Pin = 2;      //Input for next pin to be shifted in
int RCLK_Pin = 3;     //Needs to be pulled HIGH to set the output to the new shift register values, This must be pulled HIGH directly after SRCLK has gone LOW again.
int SRCLK_Pin = 4;    //When this pin is pulled HIGH, it will shift the register.
int SRCLR_Pin = 5;    //Will empty the whole Shift Register if pulled LOW, must be pulled HIGH to enable.
int button_Pin = 6;   //Button input for shifting the register

boolean started = false;

void setup() {
  //Start Serial
  Serial.begin(9600);

  //Set all pins to outputs
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  pinMode(SRCLR_Pin, OUTPUT);

  //Clear Register, Set Serial Pin to HIGH
  digitalWrite(SRCLR_Pin, LOW);
  digitalWrite(SRCLR_Pin, HIGH);
  digitalWrite(SER_Pin, HIGH);
}

void loop() {
  //Read Button press
  int val = digitalRead(button_Pin);

  //Check if Button is pressed
  if(val == HIGH){
    //If there have been shifts, then shift everything over by inputting LOW
    if(started){
      digitalWrite(RCLK_Pin, LOW);
      digitalWrite(SRCLK_Pin, LOW);
      digitalWrite(SRCLK_Pin, HIGH);
      digitalWrite(RCLK_Pin, HIGH);
      Serial.println("started");
      delay(1200);
      digitalWrite(RCLK_Pin, LOW);
      digitalWrite(SRCLK_Pin, LOW);
      digitalWrite(SRCLK_Pin, HIGH);
      digitalWrite(RCLK_Pin, HIGH);
    }
    //Makes first input to shift register HIGH if there has not been any shifts yet
    else{
      started = true;
      digitalWrite(RCLK_Pin, LOW);    //Set LOW Before setting new Register Values
      digitalWrite(SRCLK_Pin, LOW);   //Set LOW before shifting register
      digitalWrite(SRCLK_Pin, HIGH);  //Shift Register
      digitalWrite(RCLK_Pin, HIGH);   //Set New Register Values
      digitalWrite(SER_Pin, LOW);     //Sets future pin inputs to LOW
      Serial.println("not started");
      delay(1200);                    //Shift Register after [t] time, where t is burn wire on time
      digitalWrite(RCLK_Pin, LOW);
      digitalWrite(SRCLK_Pin, LOW);
      digitalWrite(SRCLK_Pin, HIGH);
      digitalWrite(RCLK_Pin, HIGH);
    }
  }
}
