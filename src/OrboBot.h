#ifndef ORBOBOT_H
#define ORBOBOT_H
#include <Arduino.h>
#include "TimerOne.h"

const int RIGHT_MOTOR_DIR_PIN = 12;
const int RIGHT_MOTOR_SPEED_PIN = 6;

const int LEFT_MOTOR_DIR_PIN = 13;
const int LEFT_MOTOR_SPEED_PIN = 11;


const int RIGHT_ENCODER_CHANNEL_A = 2;
const int RIGHT_ENCODER_CHANNEL_B = 5;

const int LEFT_ENCODER_CHANNEL_A = 3;
const int LEFT_ENCODER_CHANNEL_B = 7;


const int BUZZER_PIN = 4;

const float Kp = 2.55;
const float Ki = 1.0;



class Robot {
    private:
        int wheel_diameter = 55;
        int axle_track = 100;
		
		   static int right_encoder_val;
       static int left_encoder_val;
		
	      static int prev_right_encoder_val;
        static int prev_left_encoder_val;
		
		    static int current_right_motor_speed;
		    static int current_left_motor_speed;
		
		    static int target_right_motor_speed;
		    static int target_left_motor_speed;
		
		    static int speed_error_right_motor;
		    static int speed_integral_error_right_motor;
		    static int right_motor_PWM;
		
	      static int speed_error_left_motor;
		    static int speed_integral_error_left_motor;
		    static int left_motor_PWM;
		
        static void left_encoder_ISR();
        static void right_encoder_ISR();
        static void timer_ISR();
    public:
        Robot() = default;
        Robot(int wd, int at): wheel_diameter{wd}, axle_track{at}{}
        
        void init();
        void drive();
        int get_right_encoder_val();
        int get_left_encoder_val();

};



#endif
