#include <chrono>
#include <cinttypes>
#include <pigpiod_if2.h>
#include "thrusters.hpp"
#include "utility.hpp"

using namespace std::chrono;

std::chrono::_V2::system_clock::time_point beg;
Thrusters::Thrusters(PigpiodHandle pi)
{
    this->pi = pi;
    // (*this).pi = pi;
    // https://pi4j.com/1.2/pins/model-zerow-rev1.html
    
    pigpio_start(NULL, NULL);
    set_mode(this->pi, LEFT_PORT,PI_OUTPUT);
    set_mode(this->pi, RIGHT_PORT,PI_OUTPUT);
   
}
    
void Thrusters::step()
{
    
    // x pwms per y ms
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - beg);

    
    if(duration >= (std::chrono::microseconds) PWM_WAIT){
        
        set_servo_pulsewidth(this->pi,LEFT_PORT,clamp(leftDesired,-5,5));
        set_servo_pulsewidth(this->pi,RIGHT_PORT,clamp(rightDesired,-5,5));
        
    }

}

void Thrusters::request_thrust(double left, double right)
{
    leftDesired = (this->pi, 26, linear_map(left, -100, 100, PWM_MIN, PWM_MAX));
    rightDesired = (this->pi, 26, linear_map(right, -100, 100, PWM_MIN, PWM_MAX));
    beg = high_resolution_clock::now();
}