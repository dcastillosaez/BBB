#ifndef GPIORASPY_H
#define GPIORASPY_H
#include<string>
#include<fstream>
#include <map>
using std::string;
using std::ofstream;

#define GPIO_PATH "/sys/class/gpio/"

namespace Raspy{

class GPIORaspy
{
public:
    
    enum DIRECTION
    {
        INPUT,
        OUTPUT
    };

    enum VALUE
    {
        LOW=0,
        HIGH=1
    };
    enum EDGE
    {
        NONE,
        RISING,
        FALLING,
        BOTH
    };
    enum pinGPIO
    {
        P_3,	//GPIO_
        P_5,	//GPIO_
        P_7,	//GPIO_
        P_8,	//GPIO_
        P_10,	//GPIO_
        P_11,	//GPIO_
        P_12,	//GPIO_
        P_13,	//GPIO_
        P_15,	//GPIO_
        P_16,	//GPIO_
        P_18,	//GPIO_
        P_19,	//GPIO_
        P_21,	//GPIO_
        P_22,	//GPIO_
        P_23,	//GPIO_
        P_24,	//GPIO_
        P_26,	//GPIO_
        P_29,	//GPIO_
        P_31,	//GPIO_
        P_32,	//GPIO_
        P_33,	//GPIO_
        P_35,	//GPIO_
        P_36,	//GPIO_
        P_37,	//GPIO_
        P_38,	//GPIO_
        P_40,	//GPIO_
    };

    const std::map<pinGPIO,string> pinGPIOName =
    {
        //Pin    Name
        {P_3,	"P.3"},
        {P_5,	"P.5"},
        {P_7,	"P.7"},
        {P_8,	"P.8"},
        {P_10,	"P.10"},
        {P_11,	"P.11"},
        {P_12,	"P.12"},
        {P_13,	"P.13"},
        {P_15,	"P.15"},
        {P_16,	"P.16"},
        {P_18,	"P.18"},
        {P_19,	"P.19"},
        {P_21,	"P.21"},
        {P_22,	"P.22"},
        {P_23,	"P.23"},
        {P_24,	"P.24"},
        {P_26,	"P.26"},
        {P_29,	"P.29"},
        {P_31,	"P.31"},
        {P_32,	"P.32"},
        {P_33,	"P.33"},
        {P_35,	"P.35"},
        {P_36,	"P.36"},
        {P_37,	"P.37"},
        {P_38,	"P38"},
        {P_40,	"P.40"},

    };

    const std::map<pinGPIO,int>pinGPIONumber=
    {
        //Pin	Number
         {P_3,	2},
         {P_5,	3},
         {P_7,	4},
         {P_8,	14},
         {P_10, 15},
         {P_11, 17},
         {P_12, 18},
         {P_13, 27},
         {P_15, 22},
         {P_16, 23},
         {P_18, 24},
         {P_21, 9},
         {P_22, 25},
         {P_23, 11},
         {P_24, 8},
         {P_26, 7},
         {P_29, 5},
         {P_31, 6},
         {P_32, 12},
         {P_33, 13},
         {P_35, 19},
         {P_36, 16},
         {P_37, 26},
         {P_38, 20},
         {P_40, 21},

    };

private:
    int number;			// The GPIO number of the object
    int debounceTime;   //  The debounce time in milliseconds
    string name;		//  The name of the GPIO e.g. gpio50
    string pinName;     //  The name of Pin e.g. P9_14
    string path;  		//  The full path to the GPIO e.g. /sys/class/gpio/gpio50/


public:
    GPIORaspy(pinGPIO pinName_p);
    virtual int getNumber()
    {
        return number;// Returns the GPIO number as an int.
    }

    // General Input and Output Settings
    virtual int setDirection(GPIORaspy::DIRECTION);
    virtual GPIORaspy::DIRECTION getDirection();
    virtual int setValue(GPIO::VALUE);
    virtual int toggleOutput();
    virtual GPIORaspy::VALUE getValue();
    virtual int setActiveLow(bool isLow=true);  //low=1, high=0
    virtual int setActiveHigh(); //default
    //software debounce input (ms) - default 0
    virtual void setDebounceTime(int time) { this->debounceTime = time; }

    // Advanced OUTPUT: Faster write by keeping the stream alive (~20X)
    virtual int streamOpen();
    //Write the value of current gpio (HIGH/LOW)
    virtual int streamWrite(GPIORaspy::VALUE);
    virtual int streamClose();

    virtual int toggleOutput(int time); //threaded invert output every X ms.
    virtual int toggleOutput(int numberOfTimes, int time);
    virtual void changeToggleTime(int time) { this->togglePeriod = time; }
    virtual void toggleCancel() { this->threadRunning = false; }

    // Advanced INPUT: Detect input edges; threaded and non-threaded
    virtual int setEdgeType(GPIORaspy::EDGE);
    virtual GPIORaspy::EDGE getEdgeType();
    virtual int waitForEdge(); // waits until button is pressed
    virtual int waitForEdge(CallbackType callback); // threaded with callback
    virtual void waitForEdgeCancel() { this->threadRunning = false; }

    virtual ~GPIORaspy();  //destructor will unexport the pin

private:
    //!@brief Export the current GPIO
    int exportGPIO();
    //!@brief UnExport the current GPIO
    int unexportGPIO();
    ofstream stream;
    pthread_t thread;
    CallbackType callbackFunction;
    long lastEventTime;
    bool threadRunning;
    int togglePeriod;  //default 100ms
    int toggleNumber;  //default -1 (infinite)
    friend void* threadedPoll(void *value);
    friend void* threadedToggle(void *value);
};

void* threadedPoll(void *value);
void* threadedToggle(void *value);
}
#endif // GPIORASPY_H
