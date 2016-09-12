  
  //Initialize Data Structures
  char alphabet[] = {' ','a', 'b', 'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char text[50] = {'-', '-', '>'};
  
  //Initialize Counters
  int alphabetCounter = 0;
  int textCounter = 3;

  //Initialize Sensor Values
  int sensorValueX;
  int sensorValueY;
  int sensorValueZ;

  // WHY DO I HAVE TO SPECIFY THE SIZE OF TEXT[50]]

void setup() {

// initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.print(text);
  Serial.println(alphabet[alphabetCounter]);
}

void loop() {
  sensorValueX = analogRead(A0);
  sensorValueY = analogRead(A1);
  sensorValueZ = analogRead(A2);
    
  if (sensorValueX > 750 || sensorValueX < 150 || 
      sensorValueY > 750 || sensorValueY < 150 || 
      sensorValueZ <10){   
        
//// X-Axis Incriment and Decriment
//    if (sensorValueX > 750){
//      alphabetCounter++;
//      delay(500);
//    }
//    if (sensorValueX < 150){
//      alphabetCounter--;
//      delay(500);
//    }

// Y-Axis Incriment and Decriment
    if (sensorValueY > 750){
      alphabetCounter++;
      delay(500);
    }
    if (sensorValueY < 150){
      alphabetCounter--;
      delay(500);
    }
    
// Z-Axis Select Character
    if (sensorValueZ < 10){
      text[textCounter] = alphabet[alphabetCounter];
      textCounter++;
      delay(500);
    }
    
    Serial.print(text);
    Serial.println(alphabet[alphabetCounter]);
//    Serial.println(alphabetCounter);
//    Serial.println(textCounter);
  } 
}
