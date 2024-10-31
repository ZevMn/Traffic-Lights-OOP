/* trafficLight.cpp - Implementation file for the class trafficLight */

#include <iostream>
#include "trafficLight.h"

using namespace std;

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
		// Name const
		// Pairing const
		// Colour

};


