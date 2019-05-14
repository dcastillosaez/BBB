#ifndef UTILITY_RASPY_H_
#define UTILITY_RASPY_H_
#include <string>
using std::string;


namespace Raspy {

//!@brief Write current value of GPIO(0,1)
int write(string path, string filename, string value);

int write(string path, string filename, int value);

//!@brief Read current value of GPIO
string read(string path, string filename);

//time management
long toMicroseconds(struct timespec *ts);
void sleep_until(struct timespec *ts, int delay);
void sleep_lapse(int delay);
unsigned long  getCurrentMicroseconds();

}

#endif // UTILITY_RASPY_H_
