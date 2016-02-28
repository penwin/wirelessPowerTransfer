// LED vars 
const int ledPin = 11; // RED led, toggles on and off with toggleComplete
const int pwmPin = 3; // Yellow Led, dims, controlled by slider 'pwmComplete'

// LED read vars
String inputString = "";         // a string to hold incoming data
boolean toggleComplete = false;  // whether the string is complete
boolean pwmComplete = false;  

// Potmeter vars
const int analogInPin = A5; //antenna
int sensorValue = 0;        // value read from the antenna
int prevValue = 0;          // previous value from the antenna

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // init LEDS
  pinMode(ledPin,OUTPUT); //RED LED
  pinMode(pwmPin,OUTPUT); //Dimmed LED
  digitalWrite(ledPin,0); //RED LED 
  analogWrite(pwmPin,0);  //Dimmed LED
}

void loop() {
   // Recieve data from Node and write it to a String, until command goes through with 'E' or 'P'
   while (Serial.available() && toggleComplete == false && pwmComplete == false) {
    char inChar = (char)Serial.read();
    if(inChar == 'E'){ // end character for RED LED
     toggleComplete = true;
    }
    if(inChar == 'P'){ // end character for Dimmed LED
      pwmComplete = true;
    }
    else{
      inputString += inChar; 
    }
  }
  // When command is 'E', Toggle LED 5
  if(!Serial.available() && toggleComplete == true)
  {
    // convert String to int. 
    int recievedVal = stringToInt();
    
    if(recievedVal == 0)
    {
      digitalWrite(ledPin,recievedVal);
    }
    else if(recievedVal == 1)
    {
      digitalWrite(ledPin,recievedVal);
    }    
    toggleComplete = false;
  }
  // When command is 'P' , Dim LED 3
  if(!Serial.available() && pwmComplete == true)
  {
    // convert String to int. 
    int recievedVal = stringToInt();
    
    analogWrite(pwmPin,recievedVal);
    
    pwmComplete = false;
  }
    // Antenna
     sensorValue = analogRead(analogInPin);   
    // read the analog in value:
    if(prevValue != sensorValue){
      Serial.print("B"); // begin character 
      Serial.print(sensorValue);  
      Serial.print("E"); // end character
      prevValue = sensorValue;
    }  
  delay(50); // give the Arduino some breathing room.
}

int stringToInt()
{
    char charHolder[inputString.length()+1];
    inputString.toCharArray(charHolder,inputString.length()+1);
    inputString = "";
    int _recievedVal = atoi(charHolder);
    return _recievedVal;
}
