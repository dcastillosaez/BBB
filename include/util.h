#ifndef UTIL_H_
#define UTIL_H_
#include <string>
using std::string;


namespace BBB {

//!@brief Escribe el valor de un GPIO (0,1) en un GPIO
int write(string path, string filename, string value);

int write(string path, string filename, int value);

//!@brief Lee el valor actual de un GPIO
string read(string path, string filename);

//Time management
long toMicroseconds(struct timespec *ts);
void sleep_until(struct timespec *ts, int delay);
void sleep_lapse(int delay);
unsigned long  getCurrentMicroseconds();


} /* namespace BBB */

#endif /* UTIL_H_ */
