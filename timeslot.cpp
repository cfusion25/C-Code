/*
 * Timeslot.cpp
 */

#include "timeslot.h"


 // Initialize the static variable
string Timeslot::weekday_string[] = { "Mon", "Tue", "Wed", "Thu", "Fri" };

// Constructor
Timeslot::Timeslot(weekday d1, weekday d2, int stime, int etime)
        : day1(d1), day2(d2), start(stime), end(etime) { }

// Accessors
bool Timeslot::match(weekday day) const
{
    return (day == day1 || day == day2);
}


bool Timeslot::match(int stime, int etime) const
{
    return (start == stime && end == etime);
}



/* TODO
 * Convert the day in enum type to a printable string
 * using the static string weekday_string[5].
 */
string Timeslot::convert(weekday day) const
{
	//write your codes here
	string x;
	switch (day) {
	case 0: x = "Mon";
	break;
	case 1: x =  "Tue";
	break;
	case 2: x =  "Wed";
	break;
	case 3: x =  "Thu";
	break;
	case 4: x =  "Fri";
	break;
	}
	return x;
}

/* TODO
 * Please refer to the sample output for output format
 */
ostream& operator<<(ostream& os, const Timeslot& time)
{
	//write your codes here
	os << time.convert(time.day1) << "|" << time.convert(time.day2) << "\t";
	os << "[";
	if (time.start < 10) {
		os << "0" << time.start << ":00--";
	}
	else {
		os << time.start << ":00--";
	}
	if (time.end < 10) {
		os << "0" << time.end << ":00]";
	}
	else {
		os << time.end << ":00]";
	}
	return os;
}


