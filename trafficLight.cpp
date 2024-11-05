/* trafficLight.cpp - Implementation file for the class TrafficLight */

/* Author: Zev Menachemson 
 * Last Edited: 05/11/2024
 */

#include <iostream>
#include <string>
#include "trafficLight.h"

using namespace std;

/* INITIALISING THE CURRENT TIME VARIABLE */
Time TrafficLight::current_time(0,0,0);

/* CONSTRUCTOR 1 */
TrafficLight::TrafficLight(Time delay1, string name1)
    : delay_time(delay1), name(name1), pair(NULL) {}
/* END OF CONSTRUCTOR 1 */

/* CONSTRUCTOR 2 */
TrafficLight::TrafficLight(Time delay2, string name2, TrafficLight& partner)
    : delay_time(delay2), name(name2), pair(&partner) {

	if (!(pair->pair == NULL)) {
	    cout << "ERROR: THE TRAFFIC LIGHT ALREADY HAS A PARTNER.";
        exit(1);
	}

	if (pair == this) {
		cout << "ERROR: A TRAFFIC LIGHT CANNOT BE PARTNERS WITH ITSELF.";
        exit(1);
	}
    pair->pair = this;
}
/* END OF CONSTRUCTOR 2 */

/* MEMBER FUNCTION 1: A CAR APPROACHES THE CROSSING */
void TrafficLight::carWantsToCross() {

    cout << "\n***  at " << current_time << " a car wants to cross light "
         << name << ", with colour: " << colour << endl;

    // If the traffic light is red and its partner is green...
    if (colour == red && pair->colour == green) {
        requestPairChangeRed();
    }

    // If the traffic light is red and its partner is also red...
    if (colour == red && pair->colour == red) {
        current_time.add(delay_time);
        change_colour(yellow);

        current_time.add(delay_time);
        change_colour(green);
    }
}
/* END OF MEMBER FUNCTION 1 */

/* MEMBER FUNCTION 2: REQUEST TRAFFIC LIGHT'S PARTNER TO TURN RED */
void TrafficLight::requestPairChangeRed() {

    if (pair->colour == green) {
        current_time.add(pair->delay_time);
        pair->change_colour(yellow);
        pair->requestPairChangeGreen();
    }

    if (pair->colour == yellow) {
        current_time.add(pair->delay_time);
        pair->change_colour(red);
        pair->requestPairChangeGreen();
    }
}
/* END OF MEMBER FUNCTION 2 */

/* MEMBER FUNCTION 3: REQUEST TRAFFIC LIGHT'S PARTNER TO TURN GREEN */
void TrafficLight::requestPairChangeGreen() {

    if (pair->colour == red) {
        current_time.add(pair->delay_time);
        pair->change_colour(yellow);
        pair->requestPairChangeRed();
    }

    if (pair->colour == yellow) {
        current_time.add(pair->delay_time);
        pair->change_colour(green);
    }
}
/* END OF MEMBER FUNCTON 3 */

/* MEMBER FUNCTION 4: CHANGE COLOUR OF TRAFFIC LIGHT */
void TrafficLight::change_colour(Colours new_colour) {
    colour = new_colour;
    display();
}
/* END OF MEMBER FUNCTION 4 */

/* MEMBER FUNCTION 5: SET THE TIME */
void TrafficLight::setTheTime(Time& time) {
    current_time = time;
}
/* END OF MEMBER FUNCTION 5 */

/* MEMBER FUNCTION 6: DISPLAY THE TIME MESSAGE */
void TrafficLight::display() {
    cout << "     at " << current_time << " "
         << name << " changes colour to " << colour << endl;
}
/* END OF MEMBER FUNCTION 6 */

/* MEMBER FUNCTION 7: OVERLOAD << OPERATOR FOR TYPE "Colours" */
std::ostream& operator<<(std::ostream& out, TrafficLight::Colours colour) {
  	switch (colour) {
  		case TrafficLight::red: out << "red"; break;
		case TrafficLight::yellow: out << "yellow"; break;
		case TrafficLight::green: out << "green"; break;
    }
		return out;
}
/* END OF MEMBER FUNCTION 7 */
