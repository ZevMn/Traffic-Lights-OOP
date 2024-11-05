/* time.cpp - Implementation file for the class Time */

/* Author: Zev Menachemson 
 * Last Edited: 05/11/2024
 */

#include <iostream>
#include "time.h"

using namespace std;


/* CONSTRUCTOR DEFINITIONS */
Time::Time() : theHour(0), theMins(0), theSecs(0) {}
Time::Time(int hours, int mins, int secs) : theHour(hours), theMins(mins), theSecs(secs) {}

/* MEMBER FUNCTION 1: INCREMENT THE TIME */
void Time::add(Time& anotherTime) {
	/* adds seconds to seconds, minutes to minutes and
	hours to hours, taking into account that
	a day has 24 hours, an hour has 60 minutes
	and a minute has 60 seconds */

    int s1 = theSecs, m1 = theMins, h1 = theHour;
    int s2 = anotherTime.theSecs, m2 = anotherTime.theMins, h2 = anotherTime.theHour;

    theSecs = (s1+s2)%60;
    theMins = (m1+m2+((s1+s2)/60))%60;
    theHour = (h1+h2+(m1+m2+(s1+s2)/60)/60)%24;
}
/* END OF MEMBER FUNCTION 1 */

/* MEMBER FUNCTION 2: OVERLOAD << OPERATOR TO OUTPUT TIME IN CORRECT FORMAT */
std::ostream& operator << (std::ostream& outstream, Time& time) {
	outstream << time.theHour << ":"
		 << time.theMins << ":"
		 << time.theSecs;

	return outstream;
}
/* END OF MEMBER FUNCTION 2 */