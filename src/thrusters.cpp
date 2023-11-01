#include <chrono>
#include <cinttypes>
#include <pigpiod_if2.h>
#include "thrusters.hpp"

Thrusters::Thrusters(PigpiodHandle pi)
{
    this->pi = pi;
    // https://pi4j.com/1.2/pins/model-zerow-rev1.html
    set_mode(this->pi, 26,1);

    // (*this).pi = pi; dereference pointer and get that field and then assign it to pi
}
 
void Thrusters::step()
{
    
    // x pwms per y ms
    double cycles = PWM_MAX_DELTA / PWM_MAX_DELTA;
    set_servo_pulsewidth(this->pi, 26, 0);
    
}

void Thrusters::request_thrust(double left, double right)
{

}

/**
 * Thruster t = new Thruster()
*/