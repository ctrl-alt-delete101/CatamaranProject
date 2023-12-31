#ifndef THRUSTERS_HPP
#define THRUSTERS_HPP

#define LEFT_PORT 12
#define RIGHT_PORT 13

#include <chrono>
#include <cinttypes>

using PwmChannel = unsigned int;
using PigpiodHandle = int;

class Thrusters {
public:
    Thrusters(PigpiodHandle pi);

    void step();
    void request_thrust(double left, double right);

private:
    // Returned by `pigpio_start()`.
    PigpiodHandle pi;

    double leftCurrent  = 0;
    double rightCurrent = 0;
    double leftDesired = 0;
    double rightDesired = 0;
    std::chrono::_V2::system_clock::time_point beg;
    
    

    /**
     * constexpr indicates that the value, or return value,
     * is constant and, where possible, is computed at 
     * compile time.
    */

    // 1500 microseconds means stop/zero thrust.
    static constexpr int PWM_STOP = 1500;
    // PWM_MAX_DELTA and PWM_WAIT together describe the rate limit.
    
    // the maximum change in magnitude of PWM per unit of time
    static constexpr int PWM_MAX_DELTA = 5; // PWM

    //The unit of time. How long to wait between PWM changes,
    // where each PWM change 
    static constexpr int PWM_WAIT = 100; // milliseconds


    static constexpr int PWM_MIN = 1400;
    static constexpr int PWM_MAX = 1600;
};


#endif