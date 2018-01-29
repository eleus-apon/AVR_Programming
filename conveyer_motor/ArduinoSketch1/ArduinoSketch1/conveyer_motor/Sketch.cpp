/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio


int EN1=12;
int EN2=13;


void setup() {
	  // put your setup code here, to run once:
	  pinMode(EN1,OUTPUT);
	  pinMode(EN2,OUTPUT);

	  pinMode(5,OUTPUT);
	  pinMode(6,OUTPUT);
	  pinMode(9,OUTPUT);
	  pinMode(10,OUTPUT);
	  
	  forward();
	  }


void loop() {
	  // put your main code here, to run repeatedly:
	  digitalWrite(EN1,HIGH);
	  digitalWrite(EN2,HIGH);
	  }



void forward()
{
	analogWrite(5,100); // The speed value of the left motor//
	analogWrite(6,0);

	analogWrite(5,100); //The speed value of the right motor//
	analogWrite(10,0);
	}﻿