  // Com2Arduino
  // Created by Andrew Burke
  // Help can be found by emailing rubyartificial@gmail.com
  
  String iBytes;


  void setup() 
{
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, OUTPUT);
}



void loop() {

  if (Serial.available() > 0 ) 
{
  iBytes = Serial.readStringUntil(10);
  Serial.println(iBytes); 

// Ensures user errors case errors are ignored
  iBytes.toUpperCase();
  String intBytes ;

// Below are the commands you can issue from PC. Adding more commands here, automatically allows those commands to be called from Com2Arduino.

// Entering a number in com2arduino will blink an led (connected to arduino pin A0 and ground, and also builtin) that number of times.
  int n;
  for(n = 0; n < iBytes.toInt(); ++n)
{
}
  for(int i = 0; i < n; ++i)
{
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(A0, HIGH); 
  delay(10);
  digitalWrite(A0, LOW);  
  digitalWrite(LED_BUILTIN, LOW); 
  Serial.println("System Enabled"); 
}

// Turns Built in LED/A0 on. Be sure if you use this, you connect to a resistor to prevent that LED from burning out as its sending 5v  across your LED.
  if (iBytes == "HEYBABE")
{
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(A0, HIGH);   
  Serial.println("System Enabled"); 
}

// Turns Built in LED/A0 off
  if (iBytes == "OFF")
{
  digitalWrite(LED_BUILTIN, LOW); 
  digitalWrite(A0, LOW); 
  Serial.println("System Disabled"); 
}

}
}
