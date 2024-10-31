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
    /* 2. When a traffic light receives the message that a car wants to pass the crossing it is
    controlling */

    // If the traffic light is red and its partner is green...
    if (colour == "red" && pair->colour == "green") {
        requestPairChangeColour("red");
    }

    // If the traffic light is red and its partner is also red...
    if (colour == "red" && pair->colour == "red") {
        current_time.add(delay_time);
        colour = "yellow";

        current_time.add(delay_time);
        colour = "green";
    }

    /* 3. When a traffic light is requested to turn to red, then
    (a) if it has green colour it will wait for its delay time and then turn to yellow and
    request the collaborating light to turn to green.
    (b) if it has yellow colour, then it will wait for its delay time and then turn to red and
    request the collaborating light to turn to green. */
}

void TrafficLight::requestPairChangeColour(string new_colour) {

}

static void setTheTime(Time& time) {
    current_time = time;
}