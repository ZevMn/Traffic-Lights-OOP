/* time.h - header file for the class Time */

#ifndef TIME_H
#define TIME_H

#include <iostream>

/*********************** Time Class ***************************/

class Time {

	public:

		Time();

		// Constructor
		Time(int hours, int mins, int secs);

		void add(Time& anotherTime);
			/* adds seconds to seconds, minutes to minutes and
			hours to hours, taking into account that
			a day has 24 hours, an hour has 60 minutes
			and a minute has 60 seconds */

		void display() const;
			/* outputs the current time to the screen 
			in the format theHour:theMins:theSecs */

		friend std::ostream& operator << (std::ostream&, Time&);


	private:

		int theHour;
		int theMins;
		int theSecs;

};

#endif

