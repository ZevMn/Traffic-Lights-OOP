/* time.h - header file for the class Time */

/* Author: Zev Menachemson 
 * Last Edited: 18/11/2024
 */

#ifndef TIME_H
#define TIME_H

#include <iostream>

/*********************** Time Class ***************************/

class Time {

	public:

		/* Constructors */

		/*
		 * Default constructor. Initialises time to 00:00:00.
		 */
		Time();

		/* 
		 * Parameterised constructor. Initialises time to given values
		 * for hours, minutes and seconds.
		 *
		 * @param hours Integer value for hours (0-23).
		 * @param mins Integer value for minutes (0-59).
		 * @param secs Integer value for seconds (0-59).
		 */
		Time(int hours, int mins, int secs);


		/* Functions */

		/* 
		 * Increments the time by adding another time to this instance. Adds seconds to seconds, minutes to minutes and
		   hours to hours, using modulo arithmatic to take into account that
		   a day has 24 hours, an hour has 60 minutes
		   and a minute has 60 seconds.
		 *
		 * @param anotherTime A reference to the Time object to be added.
		 */
		void add(Time& anotherTime);

		/*
		 * Overloads the << operator for Time.
		 *
		 * @param outstream A reference to the output stream.
		 * @param time A reference to the Time object to display.
		 * 
		 * @return A reference to the output stream.
		*/
		friend std::ostream& operator << (std::ostream& outstream, Time& time);

	private:

		/* Attributes */

		/* The three attributes store the hour, minute and second components of Time respectively.
		 * They should only be adjusted through "add" method. */
		int theHour;
		int theMins;
		int theSecs;

};

#endif

