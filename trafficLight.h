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
		 * of the first traffic light in a given pair. Inititates the pair attribute
		 * to NULL. This constructor should be called for the first instance of a traffic light
		 * in a pair.
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

		/* enum decleration for the three possible traffic light colours */
		enum Colours {red, yellow, green};

		/*
		 * Overloads the << operator for the colour attribute.
		 *
		 * @param out A reference to the output stream.
		 * @param colour The colour to display.
		 * 
		 * @return A reference to the output stream.
		 */
		friend std::ostream &operator<<(std::ostream& out, Colours colour);

	private:

		/* 
		 * Sends a message to the partner trafflic light with a request to change
		 * colour to red and increments the time accordingly.
		 * The actions initiated by this function depend on the current colour
		 * of the partner traffic light.
		 */
		void requestPairChangeRed();

		/*
		 * Sends a message to the partner trafflic light with a request to change
		 * colour to green and increments the time accordingly.
		 * The actions initiated by this function depend on the current colour
		 * of the partner traffic light.
		 */
		void requestPairChangeGreen();

		/*
		 * Changes the traffic light's colour and displays a corresponding message.
		 * This method should only be called within carWantsToCross(), requestPairChangeRed()
		 * or requestPairChangeGreen(), as in this implementation it doesn't increment the global time
		 * itself.
		 *
		 * @param new_colour The colour to change this traffic light to.
		 */
		void change_colour(Colours new_colour);

		/* 
		 * Displays a time message specifying the traffic light, new colour and the global time
		 * at which the change occured.
		 */
		void display();

		/* Attributes */
		static Time current_time; // The shared global time.

		Time delay_time; // The delay time specific to this traffic light.

		std::string name; // The name of this traffic light.

		TrafficLight* pair; // A pointer to the partner of this traffic light

		Colours colour = red; // The colour of this traffic light. Should only be accessed through member functions.
};

#endif

