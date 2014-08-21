/*
Automatic Double Doors system.
 Designed for Arduino Uno R3
 Created by Sergio García Prado & Juan Carlos García.
 
 The Circuit:
 
 1 x Arduino Uno R3
 7 x Relay 5v / AC 250V/10A
 2 x Phase AC Motors to move de doors
 1 x Electric Lock
 1 x Station and wireless controllers
 3 x Buttons
 1 x Motion Sensor
 4 x Limit Buttons
 Cables and board to connect everything
 	
 */

//*********************************************************************

//Declare all Arduino I/O that we will use.
//*********************************************************************

//Imputs:
//*********************************************************************

int buttonOpenClose = 6;
int buttonEmergency = 5;
int remoteOpenClose = 4;
int securitySensor = 3;

//To convert analog inputs as digital inputs use  14 to 19 inputs.

int limitOpen1 = 14; //A0 Input
int limitClose1 = 15; //A1 Input
int limitOpen2 = 16; //A2 Input
int limitClose2 = 17; //A3 Input

//Outputs:
//*********************************************************************

int relayOpen1 = 13;
int relayClose1 = 12;
int relayOpen2 = 11;
int relayClose2 = 10;
int relayLock = 9;
int relaySignaling = 8;
int relaySignaling1 = 7;

//Variables
//*********************************************************************

int timeUnlock = 3000;  
int timeOpenLock = 5000;
int delayDoor = 5000;

boolean moving = false;


//*********************************************************************

// the setup routine runs once when you press reset:
void setup() {

  //It´s necessary to indicate the inputs and outputs 

  pinMode(relayOpen1, OUTPUT);
  pinMode(relayClose1, OUTPUT);
  pinMode(relayOpen2, OUTPUT);
  pinMode(relayClose2, OUTPUT);
  pinMode(relayLock, OUTPUT);
  pinMode(relaySignaling, OUTPUT);
  pinMode(relaySignaling1, OUTPUT);

  pinMode(buttonOpenClose, INPUT);
  pinMode(buttonEmergency, INPUT);
  pinMode(remoteOpenClose, INPUT);  
  pinMode(securitySensor, INPUT);
  pinMode(limitOpen1, INPUT);
  pinMode(limitClose1, INPUT);
  pinMode(limitOpen2, INPUT);
  pinMode(limitClose2, INPUT);

}


//Methods:
//*********************************************************************

boolean checkOpenClose(int limit1, int limit2){
 
  if ( (digitalRead(limit1) == LOW) && (digitalRead(limit2) == LOW)){
 
    return true;
 
  }
 
  else{
 
    return false;
 
  }
    
}


boolean pressButton(int button, int remote){

  if ( (digitalRead(button) == HIGH) || (digitalRead(remote) == HIGH)){

    return true;

  }

  else{

    return false;

  }
    
}


boolean checkMoving(){
  
  //**********************************************************
  //*                 UNCOMPLETE METHOD                      *
  //**********************************************************

}


boolean checkEmergency(){
  
  //**********************************************************
  //*                 UNCOMPLETE METHOD                      *
  //**********************************************************

}


void openLock (){

  //**********************************************************
  //*                 UNCOMPLETE METHOD                      *
  //**********************************************************

  //To open the door it's necessary unlock the lock
  digitalWrite(relayClose1, HIGH);
  
  digitalWrite(relayClose2, HIGH);
  
  delay();
  
  digitalWrite(relayLock, HIGH);
  
  delay();
  
  digitalWrite(relayClose1, LOW);
  
  digitalWrite(relayClose2, LOW);
  
  digitalWrite(relayLock, LOW);

}


void openDoors(){

  moving = true;
      
  openLock();
  
  digitalWrite(relayOpen1, HIGH);

  delay(delayDoor);
  
  digitalWrite(relayOpen2, HIGH);

  do{

    if (digitalRead(limitOpen1) == HIGH){
    
      digitalWrite(relayOpen1, LOW);
    
    }

    if (digitalRead(limitOpen2) == HIGH){
    
      digitalWrite(relayOpen1, LOW);
    }   
  }
  while(checkOpenClose(limitOpen1,limitOpen2) == false);

  digitalWrite(relayOpen1, LOW);

  digitalWrite(relayOpen2, LOW);

  moving = false;

}


void closeDoors(){

  //**********************************************************
  //*                 UNCOMPLETE METHOD                      *
  //**********************************************************

  do{

      moving = true;

    }

    while(checkOpenClose(limitClose1,limitClose2) == false);

}


//Main:
//*********************************************************************

// the loop routine runs over and over again forever:
void loop() {

  if (checkOpenClose(limitClose1,limitClose2) && pressButton(buttonOpenClose, remoteOpenClose)){
   
    openDoors();
 
  }

  if(checkOpenClose(limitOpen1,limitOpen2) && pressButton(buttonOpenClose, remoteOpenClose)){
   
    closeDoors();
  
  }

}