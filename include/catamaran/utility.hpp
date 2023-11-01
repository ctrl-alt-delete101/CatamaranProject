#ifndef UTILITY_HPP
#define UTILITY_HPP


double linear_map(double state, double input_upper_bound, double input_lower_bound, double output_upper_bound, double output_lower_bound){
    double output = output_lower_bound + ( (output_upper_bound - output_lower_bound) / (input_upper_bound - (input_lower_bound))) * (state - (input_lower_bound));
    if(output <= 0.002 && output >= -0.002){
        return 0.0;
    }
    return output;
}

double clamp(){

    //....
}


#endif