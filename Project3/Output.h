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
#include <iomanip>
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
    void write(std::string& o) { stream->write( o += "\n"); }
};

//NumberedOutput
class NumberedOutput : public Output {
protected:
    Output *stream;
    int lineNumber = 0;
public:
    NumberedOutput (Output *o) : stream (o) {}
    void write(std::string& o) { std::cout << std::right << std::setw(5) << ++lineNumber << ": "; stream->write( o += "\n"); }
};

//TeeOutput
class TeeOutput : public Output {
protected:
    Output *stream;
public:
    TeeOutput (Output *o, std::string tFile) : stream (o) {}
    void write(std::string& o) { stream->write(o); }
};

//FilterOutput
class FilterOutput : public Output {
protected:
    Output *stream;
public:
    FilterOutput (Output *o, std::string predChoice) : stream (o) {}
    void write(std::string& o) { stream->write(o); }
};
#endif // OUTPUT_H