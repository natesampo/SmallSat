int SER_Pin = 2;
int RCLK_Pin = 3;
int SRCLK_Pin = 4;
int SRCLR_Pin = 5;
int button_Pin = 6;

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
      digitalWrite(SRCLK_Pin, HIGH);
      delay(300);
      digitalWrite(SRCLK_Pin, LOW);
      digitalWrite(RCLK_Pin, HIGH);
      delay(300);
      digitalWrite(RCLK_Pin, LOW);
      Serial.println("started");
    }
    //Makes first input to shift register HIGH if there has not been any shifts yet
    else{
      started = true;
      digitalWrite(RCLK_Pin, LOW);
      digitalWrite(SRCLK_Pin, LOW);
      delay(300);
      digitalWrite(SRCLK_Pin, HIGH);
      digitalWrite(RCLK_Pin, HIGH);
      digitalWrite(SER_Pin, LOW);
      Serial.println("not started");
    }
  }
}
