#include "OrboBot.h"



void Robot::init(){
    pinMode(LEFT_MOTOR_DIR_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_DIR_PIN, OUTPUT);
    pinMode(LEFT_MOTOR_SPEED_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_SPEED_PIN, OUTPUT);

    attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_CHANNEL_A), left_encoder_ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_CHANNEL_A), right_encoder_ISR, RISING);
    
    Timer1.initialize(100000);         // initialize timer1, and set a 0.1 second period
    Timer1.attachInterrupt(timer_ISR);  // attaches timer_ISR() as a timer overflow interrupt
   
}  

void Robot::drive(){
  
   
     
}

void Robot::left_encoder_ISR(){
  
  }

void Robot::right_encoder_ISR(){
  
  }  


// calculate PD control by spped 
void Robot::timer_ISR(){
  
  
}  
