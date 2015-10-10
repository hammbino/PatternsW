//
//  Output.h
//  Project3
//
//  Created by Jeffrey on 10/8/15.
//  Copyright (c) 2015 Jeffrey Hammond. All rights reserved.
//

#ifndef Project3_Output_h
#define Project3_Output_h

#include <string>
#include <iostream>
//Output
class Output {
public:
    virtual ~Output(){}
    virtual void write(std::string&) = 0;
};


// StreamOutput
class StreamOutput : public Output {
    std::ostream& sink;
public:
    explicit StreamOutput(std::ostream& stream) : sink(stream) {}
    void write(std::string& s) {
        sink << s;
    }
};

//LineOutput
class LineOutput : public Output {
protected:
    Output *stream;
public:
    LineOutput  (Output *o) : stream(o) {}
    void write(std::string& os) { stream->write( os += "\n"); }
};

//NumberedOutput
class NumberedOutput : public Output {
    
};

//TeeOutput
class TeeOutput : public Output {
    
};

//FilterOutput
class FilterOutput : public Output {
    
};
#endif // OUTPUT_H