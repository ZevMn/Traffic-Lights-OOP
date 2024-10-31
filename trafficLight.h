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

		Time delay_time;

		std::string name;

		TrafficLight* pair; // Traffic light's partner

		std::string colour = "red";
};

#endif

