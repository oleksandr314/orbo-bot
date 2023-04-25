#include "OrboBot.h"

int Robot::right_encoder_val = 0;
int Robot::left_encoder_val = 0;
int Robot::prev_right_encoder_val = 0;
int Robot::prev_left_encoder_val = 0;
		
int Robot::current_right_motor_speed = 0;
int Robot::current_left_motor_speed = 0;
		
int Robot::target_right_motor_speed = 0;
int Robot::target_left_motor_speed = 0;
		
int Robot::speed_error_right_motor = 0;
int Robot::speed_integral_error_right_motor = 0;
int Robot::right_motor_PWM = 0;
		
int Robot::speed_error_left_motor = 0;
int Robot::speed_integral_error_left_motor = 0;
int Robot::left_motor_PWM = 0;

void Robot::init(){
    pinMode(LEFT_MOTOR_DIR_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_DIR_PIN, OUTPUT);
    pinMode(LEFT_MOTOR_SPEED_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_SPEED_PIN, OUTPUT);

    attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_CHANNEL_A), Robot::left_encoder_ISR, RISING);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_CHANNEL_A), Robot::right_encoder_ISR, RISING);
    
    Timer1.initialize(100000);         // initialize timer1, and set a 0.1 second period
    Timer1.attachInterrupt(Robot::timer_ISR);  // attaches timer_ISR() as a timer overflow interrupt
   
}  

void Robot::drive(){
  
   
     
}

int Robot::get_right_encoder_val(){return right_encoder_val;}
int Robot::get_left_encoder_val(){return left_encoder_val;}

static void Robot::right_encoder_ISR(){
	  if(digitalRead(RIGHT_ENCODER_CHANNEL_B) == HIGH){right_encoder_val++;}
    else if(digitalRead(RIGHT_ENCODER_CHANNEL_B) == LOW){right_encoder_val--;}
}  

static void Robot::left_encoder_ISR(){
    if(digitalRead(LEFT_ENCODER_CHANNEL_B) == HIGH){left_encoder_val--;}
    else if(digitalRead(LEFT_ENCODER_CHANNEL_B) == LOW){left_encoder_val++;}
}




void Robot::timer_ISR(){
	
    current_right_motor_speed = right_encoder_val - prev_right_encoder_val;
    prev_right_encoder_val = right_encoder_val;
    speed_error_right_motor = target_right_motor_speed - current_right_motor_speed;


    speed_integral_error_right_motor += speed_error_right_motor;
    speed_integral_error_right_motor = constrain(speed_integral_error_right_motor, -255, 255);
    right_motor_PWM  =  (int)(Kp * speed_error_right_motor  + Ki * speed_integral_error_right_motor);
    right_motor_PWM = constrain(right_motor_PWM,-255,255);
  
    analogWrite(RIGHT_MOTOR_SPEED_PIN, abs(right_motor_PWM));
  
    if(right_motor_PWM <= 0)
    {
        digitalWrite(RIGHT_MOTOR_DIR_PIN, LOW); 
    }
    if(right_motor_PWM > 0)
    {
        digitalWrite(RIGHT_MOTOR_DIR_PIN, HIGH);
    }
	
	  current_left_motor_speed = left_encoder_val - prev_left_encoder_val;
    prev_left_encoder_val = left_encoder_val;
    speed_error_left_motor = target_left_motor_speed - current_left_motor_speed;


    speed_integral_error_left_motor += speed_error_left_motor;
    speed_integral_error_left_motor = constrain(speed_integral_error_left_motor, -255, 255);
    left_motor_PWM  =  (int)(Kp * speed_error_left_motor  + Ki * speed_integral_error_left_motor);
    left_motor_PWM = constrain(left_motor_PWM,-255,255);
  
    analogWrite(LEFT_MOTOR_SPEED_PIN, abs(left_motor_PWM));
  
    if(left_motor_PWM <= 0)
    {
        digitalWrite(LEFT_MOTOR_DIR_PIN, LOW); 
    }
    if(right_motor_PWM > 0)
    {
        digitalWrite(LEFT_MOTOR_DIR_PIN, HIGH);
    }
	
}  
