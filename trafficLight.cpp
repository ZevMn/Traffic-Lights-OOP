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
    controlling: */

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

    /* 3. When a traffic light is requested to turn to red: */
    if (request_to_turn_red) {

        if (colour == "green") {
            current_time.add(delay_time);
            colour = "yellow";
            requestPairChangeColour("green");
        }

        // if (colour == "yellow")
        current_time.add(delay_time);
        colour = "red";
        requestPairChangeColour("green");
    }

    /* 4. When a traffic light is requested to turn to green: */
    if (request_to_turn_green) {
        
        if (colour == "red") {
            current_time.add(delay_time);
            colour = "yellow";
            requestPairChangeColour("red");
        }

        // if (colour == "yellow")
        current_time.add(delay_time);
        colour = "green";
    }



}

void TrafficLight::requestPairChangeColour(string new_colour) {
    if (new_colour == "red") {
        request_to_turn_red = true;
        return;
    }
    if (new_colour == "green") {
        request_to_turn_green = true;
        return;
    }
    request_to_turn_yellow = true;
}

static void TrafficLight::setTheTime(Time& time) {
    current_time = time;
}