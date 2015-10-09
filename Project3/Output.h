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
template<typename T>
class Output {
public:
    virtual ~Output(){}
    virtual void write(const T&) = 0;
    virtual void writeString(const std::string&) = 0;
};


// StreamOutput
template<typename T>
class StreamOutput : public Output<T> {
    std::ostream& sink;
public:
    explicit StreamOutput(std::ostream& stream) : sink(stream) {}
    void write(const T& t) {
        sink << t;
    }
    void writeString(const std::string& s) {
        sink << s;
    }
};
#endif

//LineOutput
//NumberedOutput
//TeeOutput
//FilterOutput




class Beverage
{
    
public:
    Beverage ()  : is_decorated (false){}
    virtual string desc() = 0;
    virtual double cost() = 0;
    virtual string btype() { return desc(); }
    string is_black () { return !is_decorated ? ", Black" :""; }
    virtual ~Beverage() {}
    void decorate() {is_decorated = true; }
    
protected:
    bool is_decorated;
    
};

class DarkRoast : public Beverage
{
public:
    DarkRoast () { }
    string desc() { return "Dark Roast" + is_black(); }
    double cost() { return 1.25; }
    ~DarkRoast() {}
};

class Decaf : public Beverage
{
public:
    Decaf () { }
    string desc() { return "Decaf" + is_black(); }
    double cost() { return 1.01; }
    ~Decaf() {}
};

class Espresso : public Beverage
{
public:
    Espresso () { }
    string desc() { return "Espresso" + is_black();}
    double cost() { return 1.72; }
    ~Espresso () {}
};

// The Decorator base class

class BeverageDecorator : public Beverage
{
protected:
    Beverage* bptr;
public:
    BeverageDecorator (Beverage* b) : bptr(b) {bptr->decorate();}
    string btype() { return bptr->btype(); }
    virtual ~BeverageDecorator() { delete bptr; }
};

class Mocha : public BeverageDecorator
{
public:
    Mocha (Beverage* b) : BeverageDecorator (b) {}
    ~Mocha () {}
    string desc () { return bptr->desc() + ", with Mocha"; }
    double cost () { return bptr->cost() + .12; }
};

class Sugar : public BeverageDecorator
{
public:
    Sugar (Beverage* b) : BeverageDecorator (b) {}
    ~Sugar () {}
    string desc () { return bptr->desc() + ", with Sugar"; }
    double cost () { return bptr->cost() + .49; }
};

class Milk : public BeverageDecorator
{
public:
    Milk (Beverage* b) : BeverageDecorator (b) {}
    ~Milk () {}
    string desc () { return bptr->desc() + ", with Milk"; }
    double cost () { return bptr->cost() + .37; }
};


#endif // BEVERAGE_H
