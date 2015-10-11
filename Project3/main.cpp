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
#include "Output.h"

int main(int argc, const char * argv[]) {
    Output *base = new StreamOutput(std::cout);
    //variable for file location
    std::string fileName = "/Users/Jeff/Downloads/decorator.dat";
    //stream variable
    std::ifstream inFile;;
    std::string lineData;

    
    //prompt for a file to read.
    std::cout << "Where is the file you would like format?\n";
       //store valie in variable
//    std::cin >> fileName;
    
    //open the file
    inFile.open(fileName.c_str());
    
    // Check for successful opening
    if (!inFile.is_open() ) {
        // The file could not be opened
        std::cerr << "Error Opening File" << std::endl;
        return(1);
    }
    int type;
    bool moreDecorators = true;
    //menu of the desired decorations to apply.
    while (moreDecorators) {
        std::cout << "What kind of formatting do you want?\n \t0 - Exit Selection\n\t1 - Newline\n \t2 - Line Numbered\n \t3 - Tee\n \t4 - Filtered\n: ";
        std::cin >> type;
        switch (type)
        {
            case 0:
            {
                moreDecorators = false;
            }
                break;
            case 1:
            {
                base = new LineOutput(base);
            }
                break;
            case 2:
            {
                base = new NumberedOutput(base);
            }
                break;
            case 3:
            {
                std::string teeFile;
                std::cout << "What do you want to name your file?\n\t:";
                std::cin >> teeFile;
                base = new TeeOutput(base, teeFile);//split into 2 stream
            }
                break;
            case 4:
            {
                int filterChoice = 0;
                while (filterChoice != 1 && filterChoice != 2) {
                    std::cout << "What kind of filter would you like:\n";
                    std::cout << "\t1 - Line does not contain numbers\n\t2 - Line contains numbers\n\t:";
                    std::cin >> filterChoice;
                    if(filterChoice != 1 && filterChoice != 2) {
                        std::cout << "Invalid input, try again";
                    }
                }
                base = new FilterOutput(base, filterChoice);
            }
                break;
            
            default:
            {
                std::cout << "Invalid input, try again";
            }
        }
                
                
        std::cout << "\n" << std::endl;
    }
    while (std::getline(inFile, lineData)) {
        lineData.erase(std::remove(lineData.begin(), lineData.end(), '\r'), lineData.end());
        base->write(lineData);
    }
    inFile.close();
    
return 0;
}