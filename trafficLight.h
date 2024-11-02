/* trafficLights.h - header file for the class TrafficLight */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"
#include <string>

/*********************** Class TrafficLight ***************************/

class TrafficLight {

	public:

		/* Constructors */
		TrafficLight(Time, std::string);
		TrafficLight(Time, std::string, TrafficLight&);

		/* Function for when car approaches crossing */
		void carWantsToCross();

		/* Function to overload << operator */
		friend std::ostream& operator << (std::ostream&, TrafficLight*);

	private:

		/* Functions to request the traffic light's partner to change colour */
		void requestPairChangeRed();
		void requestPairChangeGreen();

		/* Functions to change the traffic light's colour */
		void change_yellow();
		void change_green();
		void change_red();

		/* Function to set the time */
		static void setTheTime(Time&);

		/* Function to display the time */
		void display();

		/* Attributes */
		Time delay_time;

		std::string name;

		TrafficLight* pair; // Traffic light's partner
		
		std::string colour = "red";
};

#endif

