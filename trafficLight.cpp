/* trafficLight.cpp - Implementation file for the class TrafficLight */

#include <iostream>
#include <string>
#include "trafficLight.h"

using namespace std;


TrafficLight::TrafficLight(Time delay1, string name1) 
    : delay(delay1), name(name1), pair(NULL) {}

TrafficLight::TrafficLight(Time delay2, string name2, TrafficLight& partner) 
    : delay(delay2), name(name2), pair(&partner) {
        pair->pair = this;

        /* ADD DEFENSIVE PROGRAMMING IN-CASE THEY INPUT THE WRONG THING */
    }

void TrafficLight::carWantsToCross() {
    // Add delay time to global time

    if (colour == "red" && pair->colour == "green") {
        // Request collaborating light to turn red
    }

    /* 2. When a traffic light receives the message that a car wants to pass the crossing it is
controlling, then
(a) if it has red colour, and the collaborating light has green colour, it will request the
collaborating light to turn to red.
(b) if it has red colour, and the collaborating light has red colour, it will wait for its
delay time, then turn to yellow, then again it will wait for its delay time, and then
turn to green. */
}

static void setTheTime() {}