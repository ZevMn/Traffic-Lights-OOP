/* time.h - header file for the class Time */

/* Author: Zev Menachemson 
 * Last Edited: 05/11/2024
 */

#ifndef TIME_H
#define TIME_H

#include <iostream>

/*********************** Time Class ***************************/

class Time {

	public:

		/* Constructors */
		Time();
		Time(int hours, int mins, int secs);

		/* Function to increment the time */
		void add(Time& anotherTime);
			/* adds seconds to seconds, minutes to minutes and
			hours to hours, taking into account that
			a day has 24 hours, an hour has 60 minutes
			and a minute has 60 seconds */

		/* Function to overload << operator */
		friend std::ostream& operator << (std::ostream&, Time&);

	private:

		/* Attributes */
		int theHour;
		int theMins;
		int theSecs;

};

#endif

