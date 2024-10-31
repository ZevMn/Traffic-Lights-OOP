/* trafficLight.cpp - Implementation file for the class TrafficLight */

#include <iostream>
#include <string>
#include "trafficLight.h"

using namespace std;

Time current_time = Time(0,0,0);


TrafficLight::TrafficLight(Time delay1, string name1) 
    : delay_time(delay1), name(name1), pair(NULL) {}

TrafficLight::TrafficLight(Time delay2, string name2, TrafficLight& partner) 
    : delay_time(delay2), name(name2), pair(&partner) {
        pair->pair = this;

        /* ADD DEFENSIVE PROGRAMMING IN-CASE THEY INPUT THE WRONG THING */
    }

void TrafficLight::carWantsToCross() {

    cout << "\n*** at " << current_time << " a car wants to cross light "
         << name << ", with colour: " << colour << endl;

    // If the traffic light is red and its partner is green...
    if (colour == "red" && pair->colour == "green") {
        requestPairChangeRed();
    }

    // If the traffic light is red and its partner is also red...
    if (colour == "red" && pair->colour == "red") {
        current_time.add(delay_time);
        colour = "yellow";
        display();

        current_time.add(delay_time);
        colour = "green";
        display();
    }
}

void TrafficLight::requestPairChangeRed() {

    if (pair->colour == "green") {
        current_time.add(pair->delay_time);
        pair->colour = "yellow";
        pair->display();
        pair->requestPairChangeGreen();
    }

    if (pair->colour == "yellow") {
        current_time.add(pair->delay_time);
        pair->colour = "red";
        pair->display();
        pair->requestPairChangeGreen();
    }
}

void TrafficLight::requestPairChangeGreen() {
    if (pair->colour == "red") {
        current_time.add(pair->delay_time);
        pair->colour = "yellow";
        pair->display();
        pair->requestPairChangeRed();
    }

    if (pair->colour == "yellow") {
        current_time.add(pair->delay_time);
        pair->colour = "green";
        pair->display();
    }
}

void TrafficLight::setTheTime(Time& time) {
    current_time = time;
}

void TrafficLight::display() {
    cout << "   at " << current_time << " " 
         << name << " changes colour to " << colour << endl;
}