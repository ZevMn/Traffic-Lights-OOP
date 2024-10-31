/* trafficLights.h - header file for the class TrafficLight */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"
#include <string>

/*********************** Class TrafficLight ***************************/

class TrafficLight {

	public:

		// Constructors
		TrafficLight(Time, std::string);
		TrafficLight(Time, std::string, TrafficLight&);

		void carWantsToCross();

		void requestPairChangeRed();
		void requestPairChangeGreen();

		static void setTheTime(Time&);

		void display();

		friend std::ostream& operator << (std::ostream&, TrafficLight*);

	private:
	
		// // Global time
		// static Time current_time;

		// Delay
		Time delay_time;

		// Name
		std::string name;

		// Pairing
		TrafficLight* pair;

		// Colour
		std::string colour = "red";
};

#endif

