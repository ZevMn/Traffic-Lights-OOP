/* trafficLight.cpp - Implementation file for the class TrafficLight */

#include <iostream>
#include <string>
#include "trafficLight.h"

using namespace std;

Time current_time = Time(0,0,0);

/* CONSTRUCTOR 1 */
TrafficLight::TrafficLight(Time delay1, string name1)
    : delay_time(delay1), name(name1), pair(NULL) {}
/* END OF CONSTRUCTOR 1 */

/* CONSTRUCTOR 2 */
TrafficLight::TrafficLight(Time delay2, string name2, TrafficLight& partner)
    : delay_time(delay2), name(name2), pair(&partner) {

	if (!pair->pair == NULL) {
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

/* FUNCTION TO SIMULATE A CAR APPROACHING THE CROSSING */
void TrafficLight::carWantsToCross() {

    cout << "\n***  at " << current_time << " a car wants to cross light "
         << name << ", with colour: " << colour << endl;

    // If the traffic light is red and its partner is green...
    if (colour == "red" && pair->colour == "green") {
        requestPairChangeRed();
    }

    // If the traffic light is red and its partner is also red...
    if (colour == "red" && pair->colour == "red") {
        current_time.add(delay_time);
        change_yellow();

        current_time.add(delay_time);
        change_green();
    }
}
/**/

void TrafficLight::requestPairChangeRed() {

    if (pair->colour == "green") {
        current_time.add(pair->delay_time);
        pair->change_yellow();
        pair->requestPairChangeGreen();
    }

    if (pair->colour == "yellow") {
        current_time.add(pair->delay_time);
        pair->change_red();
        pair->requestPairChangeGreen();
    }
}

void TrafficLight::requestPairChangeGreen() {
    if (pair->colour == "red") {
        current_time.add(pair->delay_time);
        pair->change_yellow();
        pair->requestPairChangeRed();
    }

    if (pair->colour == "yellow") {
        current_time.add(pair->delay_time);
        pair->change_green();
    }
}

void TrafficLight::change_red() {
    colour = "red";
    display();
}

void TrafficLight::change_yellow() {
    colour = "yellow";
    display();
}

void TrafficLight::change_green() {
    colour = "green";
    display();
}

void TrafficLight::setTheTime(Time& time) {
    current_time = time;
}

void TrafficLight::display() {
    cout << "     at " << current_time << " "
         << name << " changes colour to " << colour << endl;
}
