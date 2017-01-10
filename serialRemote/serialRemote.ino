void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("Howdy, partner!");
  Serial.println("Send 'On' to turn on the LED.");
  Serial.println("Send 'Half' to set the light to half brightness.");
  Serial.println("Send 'Off' to turn off the LED.");
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  String lightValue;
  if (Serial.available() > 0) {
    lightValue = Serial.readString();
    if (lightValue == "On") {
      Serial.println("OK, turning the light on...");
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 255);
    }
    else if (lightValue == "Off") {
      Serial.println("OK, turning the light off...");
      analogWrite(9, 0);
      analogWrite(10, 0);
      analogWrite(11, 0);
    }
    else if (lightValue == "Half") {
      Serial.println("OK, setting the light to half brightness...");
      analogWrite(9, 130);
      analogWrite(10, 130);
      analogWrite(11, 130);      
    }
    else {
      Serial.println("I'm sorry, I didn't understand that.");
      Serial.println("Please type 'On', 'Half', or 'Off' before sending.");
    }
    
  }
}
