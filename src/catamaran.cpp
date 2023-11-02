#include <iostream>
#include <sstream>

using std::cerr; // unbuffered so it sends error immediately to screen instead of it being delayed
// cerr --> standard error stream


int main(){
    double leftThrust, rightThrust;
    std::string command;

    std::string line; //String because strings are not part of c++ its part of standard library
    // will keep receiving messages until error or EOF
    while(std::getline(std::cin, line) ){//Read a line from stream into a string.

        // cin takes input from standard input device (laptop) (this will be our input stream)
        // we store the input into the line variable...

        std::istringstream iss(line); // creates iss object treating the line string as a stream..

        iss >> command; //stores first thing before whitespace into command
        if(command == "request-thrust"){ // is that initial word the correct request?
            iss >> leftThrust >> rightThrust; // if so then pass in the other stuff (with space as seperators...)
            if (iss.fail()) { // to check if the parsing worked or not
            cerr << "error: Failed to parse thrust values.\n";
            } else {
                cerr << "received left: "   << leftThrust << ", right: " << rightThrust << '\n';
            }
        }
    }
}