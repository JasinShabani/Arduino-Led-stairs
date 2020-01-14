// ---------------------------
// ---------------------------
int trigPin2 = 9;    // Trigger
int echoPin2 = 8;    // Echo
// ---------------------------
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
// ---------------------------
// ---------------------------
long duration, distance, UltraSensor1, UltraSensor2;
char data;
String SerialData="";

void setup() {
  Serial.begin (9600);
  //Define inputs and outputs
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
}
//write the code in the loop function
void loop() 
{
// START THE LOOP FUNCTION
SonarSensor(trigPin, echoPin);              // look bellow to find the difinition of the SonarSensor function
UltraSensor1 = distance;                      // store the distance in the first variable
SonarSensor(trigPin2,echoPin2);               // call the SonarSensor function again with the second sensor pins
UltraSensor2 = distance;                      // store the new distance in the second variable

while(Serial.available())
{
  delay(10);
  data=Serial.read();
  SerialData+=data;
}

// display the distances on the serial monitor for the first sensor
//----------------------------------------------------------------------------------------------------------------------
Serial.print("distance measured by the first sensor: ");
Serial.print(UltraSensor1);
Serial.println(" cm");
//----------------------------------------------------------------------------------------------------------------------

//display the distance on the serial monitor for the second sensor
//----------------------------------------------------------------------------------------------------------------------
Serial.print("distance measured by the second sensor: ");
Serial.print(UltraSensor2);
Serial.println(" cm");
Serial.println("---------------------------------------------------------------------------------------------------------");
//----------------------------------------------------------------------------------------------------------------------


SerialData="";
// make condition to control the LEDs
if(UltraSensor1 >20)// if distance is less than 10 Cm turn the LED ON
{
   digitalWrite(4, HIGH);
    delay(700);
    digitalWrite(2, HIGH);
    delay(700);
    digitalWrite(3, HIGH);
    delay(700);
    
    digitalWrite(3, LOW);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);
    digitalWrite(4, LOW);
    delay(3000);
}

// do the same thing for second sensor 
else if(UltraSensor2 >20)
{
    digitalWrite(3, HIGH);
    delay(700);
    digitalWrite(2, HIGH);
    delay(700);
    digitalWrite(4, HIGH);
    delay(700);
    
    digitalWrite(4, LOW);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);
    digitalWrite(3, LOW);
    delay(3000);
  }
  else{
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  
}//END LOOP FUNTION
/*void loop(){
  // START THE LOOP FUNCTION
SonarSensor(trigPin, echoPin);              // look bellow to find the difinition of the SonarSensor function
UltraSensor1 = distance;                      // store the distance in the first variable
SonarSensor(trigPin2,echoPin2);               // call the SonarSensor function again with the second sensor pins
UltraSensor2 = distance;                      // store the new distance in the second variable
  //--------------------------------------------------------------------------

  
  pinMode(echoPin, INPUT);
  pinMode(echoPin2, INPUT);
  
  duration = pulseIn(echoPin, HIGH);
  duration2 = pulseIn(echoPin2, HIGH);
 
  // Convert the time into a distance
  
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  cm2 = (duration2/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
//--------------------------------------------------------------------------
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  
  
 
  // Convert the time into a distance



  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  Serial.print(cm2);
  Serial.print("cm(2)");
  Serial.println();
  
  delay(50);
  if(cm >10){
    digitalWrite(4, HIGH);
    delay(700);
    digitalWrite(2, HIGH);
    delay(700);
    digitalWrite(3, HIGH);
    delay(700);
    
    digitalWrite(3, LOW);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);
    digitalWrite(4, LOW);
    delay(500);
  }
  else if(cm2 >10){
    digitalWrite(3, HIGH);
    delay(700);
    digitalWrite(2, HIGH);
    delay(700);
    digitalWrite(4, HIGH);
    delay(700);
    
    digitalWrite(4, LOW);
    delay(500);
    digitalWrite(2, LOW);
    delay(500);
    digitalWrite(3, LOW);
    delay(500);
  }
  else{
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  delay(2000);

}
*/


// SonarSensor function used to generate and read the ultrasonic wave
void SonarSensor(int trigPinSensor,int echoPinSensor)//it takes the trigPIN and the echoPIN 
{
  //START SonarSensor FUNCTION
  //generate the ultrasonic wave
//---------------------------------------------------------------------------------------------------------------------- 
digitalWrite(trigPinSensor, LOW);// put trigpin LOW 
delayMicroseconds(2);// wait 2 microseconds
digitalWrite(trigPinSensor, HIGH);// switch trigpin HIGH
delayMicroseconds(10); // wait 10 microseconds
digitalWrite(trigPinSensor, LOW);// turn it LOW again
//----------------------------------------------------------------------------------------------------------------------

//read the distance
//----------------------------------------------------------------------------------------------------------------------
duration = pulseIn(echoPinSensor, HIGH);//pulseIn funtion will return the time on how much the configured pin remain the level HIGH or LOW; in this case it will return how much time echoPinSensor stay HIGH
distance= (duration/2) / 29.1; // first we have to divide the duration by two  
}// END SonarSensor FUNCTION

