#include <iostream>
#include <thread>
#include <chrono>
#include <SDL.h>
#define MAX_INPUT 32767
#define MIN_INPUT -32768


using std::cout;
using std::cerr;

double scalarMultiplier = 1.0 / ((32767.0 + 32768.0) / (200.0));

struct JoyState{
    bool running;
    struct state_joy {
        int16_t leftX, leftY, rightX, rightY; 
    } joy;
};

enum PS4Axis {left_x = 0, left_y = 1, right_x = 3, right_y = 4};

//references the entire controller
SDL_Joystick *gamepad = NULL; 

//starting up the project
bool init(){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0){
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << '\n';
        return false;
    }

    if(SDL_NumJoysticks() < 1){
        cout << "Warning: No joysticks connected!\n";
    } else {
        //loading the first joystick(zero-indexed)
        gamepad = SDL_JoystickOpen(0);
        if(gamepad == NULL){
            cout << "Warning: Unable to open game controller: SDL Error: " << SDL_GetError() << '\n';
        }
    }

    return true;
}

// closing the SDL
void close(){
    SDL_JoystickClose(gamepad);
    gamepad = NULL;

    SDL_Quit();
}

void handleEvents(JoyState& state)
{
    SDL_Event e;

    // Handle events in queue.
    while (SDL_PollEvent(&e)) {

        switch (e.type) {
            case SDL_QUIT:
                state.running = false;
                break;
            case SDL_JOYAXISMOTION:
                // Motion on controller 0.
                if (e.jaxis.which == 0) {
                    switch (e.jaxis.axis) {
                        case PS4Axis::left_x:
                            state.joy.leftX = e.jaxis.value;
                            break;
                        case PS4Axis::left_y:
                            state.joy.leftY = e.jaxis.value;
                            break;
                        case PS4Axis::right_x:
                            state.joy.rightX = e.jaxis.value;
                            break;
                        case PS4Axis::right_y:
                            state.joy.rightY = e.jaxis.value;
                            break;
                        }
                }
                break;
        }
    }
}

double linear_map(double state, double upper_bound, double lower_bound){
    double output = lower_bound + ( (upper_bound - lower_bound) / (MAX_INPUT - (MIN_INPUT))) * (state - (MIN_INPUT));
    if(output <= 0.002 && output >= -0.002){
        return 0.0;
    }
    return output;
}

int main()
{
    if (not init()) {
        cerr << "failed to initialize SDL" << '\n';
        std::exit(EXIT_FAILURE);
    }

    struct JoyState state_;
    struct JoyState& state = state_;
    state.running = true;
    state.joy.leftX = 0;
    state.joy.leftY = 0;
    state.joy.rightX = 0;
    state.joy.rightY = 0;



    while (state.running) {
        handleEvents(state);
        cout
             << "request-thrust " << linear_map(state.joy.leftY, -100.0, 100.0)
             << " " << linear_map(state.joy.rightY, -100.0, 100.0)
             << std::endl;             

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    return EXIT_SUCCESS;
}