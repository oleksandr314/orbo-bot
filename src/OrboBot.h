#ifndef ORBOBOT_H
#define ORBOBOT_H
#include <Arduino.h>
#include "TimerOne.h"

const int LEFT_MOTOR_DIR_PIN = 13;
const int RIGHT_MOTOR_DIR_PIN = 12;
const int LEFT_MOTOR_SPEED_PIN = 6;
const int RIGHT_MOTOR_SPEED_PIN = 9;

const int LEFT_ENCODER_CHANNEL_A = 2;
const int LEFT_ENCODER_CHANNEL_B = 5;
const int RIGHT_ENCODER_CHANNEL_A = 3;
const int RIGHT_ENCODER_CHANNEL_B = 7;

const int BUZZER_PIN = 4;



class Robot {
    private:
        int wheel_diameter = 55;
        int axle_track = 100;
        
        static void left_encoder_ISR();
        static void right_encoder_ISR();
        static void timer_ISR();
    public:
        Robot() = default;
        Robot(int wd, int at): wheel_diameter{wd}, axle_track{at}{}
        
        void init();
        void drive();

};

#endif
