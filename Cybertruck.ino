char t;
int light = 0;
int trigPin = 3;      // trig pin of HC-SR04
int echoPin = 5;     // Echo pin of HC-SR04
long duration, distance;
 
void setup() {
pinMode(13,OUTPUT);   //right motors forward
pinMode(12,OUTPUT);   //right motors reverse
pinMode(11,OUTPUT);   //left motors forward
pinMode(10,OUTPUT);   //left motors reverse
pinMode(trigPin, OUTPUT);         // set trig pin as output
pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
pinMode(9,OUTPUT);   //Led backward
pinMode(8,OUTPUT);   //Led Left
pinMode(7,OUTPUT);   //Led Right
Serial.begin(9600);
 
}
 
void loop() {
  
  if(Serial.available()){
    t = Serial.read();
    Serial.println(t);

        if(light == 1)
    {
        digitalWrite(9,HIGH);
    
     }
     else
     {
        digitalWrite(9,LOW);
      }
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);   
    digitalWrite(trigPin, HIGH);     // send waves for 10 us
    delayMicroseconds(10);
    
    
    duration = pulseIn(echoPin, HIGH); // receive reflected waves
    distance = duration / 58.2;   // convert to distance

    if(distance >= 19){
    if(t == 'F'){            //move forward(all motors rotate in forward direction)
      digitalWrite(13,HIGH);
      digitalWrite(11,HIGH);
    }
     
    else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
      digitalWrite(12,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(9,HIGH);
    }
     
    else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
      digitalWrite(13,HIGH);
       digitalWrite(10,HIGH);
       digitalWrite(8,HIGH);
    }
     
    else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
      digitalWrite(11,HIGH);
       digitalWrite(12,HIGH);
        digitalWrite(7,HIGH);
    }
    
    else if(t == 'W'){    //turn led on or off
      digitalWrite(9,HIGH);
      light = 1;
    }
    else if(t == 'w'){
      digitalWrite(9,LOW);
        light = 0;
    }
     
    else {      //STOP (all motors stop)
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
    }
    
      }
      
    else{
      
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);  // Stop
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(7,HIGH);
      delay(500);
      
      digitalWrite(12,HIGH);
      digitalWrite(10,HIGH);// Move Backward
    
      delay(500);
      
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);  // Stop 
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
      digitalWrite(8,LOW);
      digitalWrite(7,LOW);
      
      }
  
    Serial.println(distance);
    
  }
  else
  {
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
      digitalWrite(8,LOW);
      digitalWrite(7,LOW);
    }


  
  
}
