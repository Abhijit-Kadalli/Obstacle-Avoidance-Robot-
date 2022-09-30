const int trigPin= 12;
const int echoPin=10;

long duration; 
int distance;

void setup(){
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
}

void loop(){ 
  
    
  //Forward
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
    	
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
      	
  //automatic avoidance of obstacle if it is closer than 30cm
  digitalWrite(trigPin, LOW); 
  delay(2); 
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin,LOW); 
  
  duration= pulseIn(echoPin, HIGH); 
  
  distance=duration*0.034/2; 
  
  Serial.print("Distance: "); 
  Serial.println(distance);
  
  if (distance <= 50){
    
    //Stop
    digitalWrite(6,LOW);
  	digitalWrite(7,LOW);
    	
    digitalWrite(4,LOW);
  	digitalWrite(5,LOW);
    
    delay(1000);
    
    //Backward
    digitalWrite(6,HIGH);
  	digitalWrite(7,LOW);
    	
    digitalWrite(4,HIGH);
  	digitalWrite(5,LOW);
    
    delay(1000);
    
    //Right
    digitalWrite(7,HIGH);
  	digitalWrite(6,LOW);
      
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    
    delay(2000);
    
    //Stop
    digitalWrite(6,LOW);
  	digitalWrite(7,LOW);
    	
    digitalWrite(4,LOW);
  	digitalWrite(5,LOW);
    
  } 

  delay(500);
  
 
  //manual control using serial monitor
  if(Serial.available())
  {
    String val = Serial.readString();
  	
    if(val == "F")
    {
      	digitalWrite(7,HIGH);
  	  	digitalWrite(6,LOW);
    	
      	digitalWrite(5,HIGH);
  	  	digitalWrite(4,LOW);
      	
    }
     
    else if(val == "B")
    {
    	digitalWrite(6,HIGH);
  	  	digitalWrite(7,LOW);
    	
      	digitalWrite(4,HIGH);
  	  	digitalWrite(5,LOW);
      
    }
     
    else if(val == "S")
    {
    	digitalWrite(6,LOW);
  	  	digitalWrite(7,LOW);
    	
      	digitalWrite(4,LOW);
  	  	digitalWrite(5,LOW);
      
    }
     
    else if(val == "L")
    {
      	digitalWrite(6,LOW);
  	  	digitalWrite(7,LOW);
    	
      	digitalWrite(5,HIGH);
  	  	digitalWrite(4,LOW);
      
    }
     
    else if(val == "R")
    {
    	digitalWrite(7,HIGH);
  	  	digitalWrite(6,LOW);
      
      	digitalWrite(4,LOW);
  	  	digitalWrite(5,LOW);
      
    } 
   }
}  