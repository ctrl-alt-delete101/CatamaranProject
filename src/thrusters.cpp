#include <chrono>
#include <cinttypes>
#include <iostream>
#include <sstream>
#include <pigpiod_if2.h>
#include "thrusters.hpp"
#include "utility.hpp"

using namespace std::chrono;
using namespace std;


Thrusters::Thrusters(PigpiodHandle pi)
{
    this->pi = pi;
    // (*this).pi = pi;
    // https://pi4j.com/1.2/pins/model-zerow-rev1.html
    
    pigpio_start(NULL, NULL);
    set_mode(this->pi, LEFT_PORT,PI_OUTPUT);
    set_mode(this->pi, RIGHT_PORT,PI_OUTPUT);
    beg = high_resolution_clock::now();
}
    
void Thrusters::step()
{
    
    // x pwms per y ms
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - beg);

    
    if(duration >= (std::chrono::microseconds) PWM_WAIT){
        double left = clamp(leftDesired,PWM_MIN,PWM_MAX);
        double right = clamp(rightDesired,PWM_MIN,PWM_MAX);
        set_servo_pulsewidth(this->pi, LEFT_PORT, left);
        set_servo_pulsewidth(this->pi, RIGHT_PORT, right);
        cerr << "setting left: "   << left<< ", right: " << right << '\n';
        beg = high_resolution_clock::now();
    }

}

void Thrusters::request_thrust(double left, double right)
{
    // leftDesired = (this->pi, 26, linear_map(left, -100, 100, PWM_MIN, PWM_MAX));
    // rightDesired = (this->pi, 26, linear_map(right, -100, 100, PWM_MIN, PWM_MAX));

    leftDesired = linear_map(left, -100, 100, PWM_MIN, PWM_MAX);
    rightDesired = linear_map(right, -100, 100, PWM_MIN, PWM_MAX);
    
}