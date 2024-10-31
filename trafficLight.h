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

		void requestPairChangeColour(string new_colour);

		static void setTheTime(Time&);

		friend std::ostream& operator << (std::ostream&, TrafficLight*);

		bool request_to_turn_red=false, request_to_turn_orange=false, request_to_turn_green=false;

	private:
	
		// Global time
		static Time current_time;

		// Delay
		Time delay_time;

		// Name
		string name;

		// Pairing
		TrafficLight* pair;

		// Colour
		string colour = "red";
};

#endif

