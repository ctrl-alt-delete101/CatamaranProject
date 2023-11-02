#ifndef UTILITY_HPP
#define UTILITY_HPP

//https://math.stackexchange.com/questions/914823/shift-numbers-into-a-different-range
double linear_map(double state, double input_upper_bound, double input_lower_bound, double output_upper_bound, double output_lower_bound){
    double output = output_lower_bound + ( (output_upper_bound - output_lower_bound) / (input_upper_bound - (input_lower_bound))) * (state - (input_lower_bound));
    if(output <= 0.002 && output >= -0.002){
        return 0.0;
    }
    return output;
}

double clamp(double state, double a, double b){
    return state;
    //....
}


#endif