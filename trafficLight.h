/* trafficLights.h - header file for the class TrafficLight */

/* Author: Zev Menachemson 
 * Last Edited: 18/11/2024
 */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"
#include <string>

/*********************** Class TrafficLight ***************************/

class TrafficLight {

	public:

		/* Constructors */

		/* 
		 * Parameterised constructor to be called for creating an instance
		 * of the first traffic light in a given pair.
		 *
		 * @param delay1 The delay time associated with the first traffic light in the pair.
		 * @param name1 The name of the first traffic light in the pair.
		 */
		TrafficLight(Time delay1, std::string name1);

		/* 
		 * Parameterised constructor to be called for creating an instance
		 * of the second traffic light in a given pair. This constructor should only
		 * be called after the first traffic light in the pair has already been instantiated,
		 * otherwise an error message will be returned. This constructor will also set the pair
		 * attribute of the corresponding traffic light to point to this traffic light.
		 * 
		 * @param delay2 The delay time associated with the second traffic light in the pair.
		 * @param name2 The name of the second traffic light in the pair.
		 * @param partner A reference to the partner of this traffic light.
		 */
		TrafficLight(Time delay2, std::string name2, TrafficLight& partner);

		/* Functions */

		/* 
		 * Simulates the behaviour when a car signals to cross the crossing controlled
		 * by this traffic light. This function initiates a series of behaviours and actions
		 * based on the current light colour, its pair and their delay times
		 */
		void carWantsToCross();

		/* 
		 * Sets the time of the global clock. This is a static function
		 * as all traffic lights must reference a shared global clock.
		 *
		 * @param time The instance of Time representing the global clock.
		 */
		static void setTheTime(Time& time);

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

