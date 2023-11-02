#include <chrono>
#include <cinttypes>
#include <pigpiod_if2.h>
#include "thrusters.hpp"
#include "utility.hpp"

using namespace std::chrono;

Thrusters::Thrusters(PigpiodHandle pi)
{
    this->pi = pi;
    // (*this).pi = pi;
    // https://pi4j.com/1.2/pins/model-zerow-rev1.html
    /**
     * 
    */
    pigpio_start("no idea", "no idea");
    set_mode(this->pi, 26,1);
    
    // (*this).pi = pi; dereference pointer and get that field and then assign it to pi
}
 
void Thrusters::step()
{
    
    // x pwms per y ms
    double rate = PWM_MAX_DELTA / PWM_WAIT;
    
    // set_servo_pulsewidth

}

void Thrusters::request_thrust(double left, double right)
{
    leftDesired = (this->pi, 26, linear_map(left, -100, 100, PWM_MIN, PWM_MAX));
    rightDesired = (this->pi, 26, linear_map(right, -100, 100, PWM_MIN, PWM_MAX));

}

/**
 * Thruster t = new Thruster()
*/