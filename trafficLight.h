/* trafficLights.h - header file for the class TrafficLight */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"

const int MAX_STRING_LENGTH = 80;

/*********************** Class TrafficLight ***************************/

class TrafficLight {

	public:

		TrafficLight(Time,char*);
		TrafficLight(Time,char*,TrafficLight&);

		void carWantsToCross();

		static void setTheTime(Time&);

		friend std::ostream& operator << (std::ostream&, TrafficLight*);

	private:

		/* add members and operations to complete the class yourself */
		// Delay const
		Time delay;

		// Name const
		char name[MAX_STRING_LENGTH];

		// Pairing const
		TrafficLight pair;

		// Colour
		char colour; // r, o, g

};

#endif

