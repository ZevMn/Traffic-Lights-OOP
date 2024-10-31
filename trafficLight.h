/* trafficLights.h - header file for the class TrafficLight */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"
#include <string>

/*********************** Class TrafficLight ***************************/

class TrafficLight {

	public:

		// Constructors
		TrafficLight(Time, string);
		TrafficLight(Time, string, TrafficLight&);

		void carWantsToCross();

		static void setTheTime(Time&);

		friend std::ostream& operator << (std::ostream&, TrafficLight*);

	private:

		// Delay
		Time delay;

		// Name
		string name;

		// Pairing
		TrafficLight* pair;

		// Colour
		string colour = "red"
};

#endif

