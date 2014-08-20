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
 
//Declare all Arduino I/O that we will use.

//Imputs:

int LimitOpenLeft = A0; 

int LimitCloseLeft = A1;

int LimitOpenRight = A2;

int LimitCloseRight = A3;

int ButtonOpenClose = 6;

int ButtonEmergency = 5;

int RemoteOpenClose = 4;

int SecuritySensor = 3;

//Outputs:

int RelayOpenLeft = 13;

int RelayCloseLeft = 12;

int RelayOpenRight = 11;

int RelayCloseRight = 10;

int RelayLock = 9;

int RelaySignaling = 8;

int RelaySignaling1 = 7;



// the setup routine runs once when you press reset:
void setup() {
  
  //It´s necessary to indicate the outputs
  
  pinMode(RelayOpenLeft, OUTPUT);
  pinMode(RelayCloseLeft, OUTPUT);
  pinMode(RelayOpenRight, OUTPUT);
  pinMode(RelayCloseRight, OUTPUT);
  pinMode(RelayLock, OUTPUT);
  pinMode(RelaySignaling, OUTPUT);
  pinMode(RelaySignaling1, OUTPUT);

}


// the loop routine runs over and over again forever:
void loop() {
  
  
  
  
}


