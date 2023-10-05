#include <iostream>
#include <sstream>

using std::cerr;

int main() {
    double leftThrust, rightThrust;
    std::string line;
    std::string command;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);

        // iss: request-thrust 50-35
        iss >> command;

        // iss: 50-35
        cerr << "the command was: " << command << '\n';

        if (command == " request-thrust") {
            iss >> leftThrust >> rightThrust;
            if (iss.fail()) {
                cerr << "error: failed to parse thrust values.\n";
            }
            cerr << "received: left: " << leftThrust << ", right: " << rightThrust << '\n';
        }
    }
    
 
    return 0;
}