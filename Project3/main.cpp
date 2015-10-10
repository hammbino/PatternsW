//
//  main.cpp
//  Project3
//
//  Created by Jeffrey on 10/8/15.
//  Copyright (c) 2015 Jeffrey Hammond. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    //variable for file location
    std::string fileName; // = "/Users/Jeff/Downloads/decorator.dat";
    //stream variable
    std::ifstream inFile;;
    std::string lineData;

    
    //prompt for a file to read.
    std::cout << "Where is the file you would like decorate?\n";
    std::cin >> fileName;
    
    //open the file
    inFile.open(fileName.c_str());
    
    // Check for successful opening
    if (!inFile.is_open() ) {
        // The file could not be opened
        std::cerr << "Error Opening File" << std::endl;
        return(1);
    }
    else {
        // Safely use the file stream
        while (!inFile.eof()) {
            std::getline(inFile, lineData, inFile.widen('\n'));
            std::cout << lineData << "\n";
        }
    }

    //store valie in variable
//present a menu of the desired decorations to apply.
//a. The user can select multiple decorations; they will be applied in order.
//b. If the user selects TeeOutput, prompt for a file name to direct the Tee output to.
//c. If the user selects FilterOutput, give the user a choice of at least two predicates to choose from.
//produce the decorated output.
return 0;
}
