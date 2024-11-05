/* trafficLights.h - header file for the class TrafficLight */

/* Author: Zev Menachemson 
 * Last Edited: 05/11/2024
 */

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

		/* Function to set the time */
		static void setTheTime(Time&);

		/* Functions to overload << operator */
		friend std::ostream& operator << (std::ostream&, TrafficLight*);

		enum Colours {red, yellow, green};
		friend std::ostream &operator<<(std::ostream& out, Colours colour);

	private:

		/* Functions to request the traffic light's partner to change colour */
		void requestPairChangeRed();
		void requestPairChangeGreen();

		/* Functions to change the traffic light's colour */
		void change_colour(Colours new_colour);

		/* Function to display the time message */
		void display();

		/* Attributes */
		static Time current_time;

		Time delay_time;

		std::string name;

		TrafficLight* pair; // Traffic light's partner

		Colours colour = red;
};

#endif

