#ifndef DYRET_CONTROLLER_WAGGENERATOR_H
#define DYRET_CONTROLLER_WAGGENERATOR_H

#include "../kinematics/kinematicTypes.h"
#include "../kinematics/kinematicFunctions.h"

class WagGenerator {

    float wagPhase = 0.0;
    float wagAmplitude_x = 0.0;
    float wagAmplitude_y = 0.0;

    float getWagPhase() { return wagPhase; };
    float getWagAmplitude_x(){ return wagAmplitude_x; };
    float getWagAmplitude_y(){ return wagAmplitude_y; };

public:

    void enableWag(float givenWagPhase, float givenWagAmplitude_x, float givenWagAmplitude_y) {
        wagPhase       = givenWagPhase;
        wagAmplitude_x = givenWagAmplitude_x;
        wagAmplitude_y = givenWagAmplitude_y;
    }

    vec3P getGaitWagPoint(double givenTime, bool walkingForwards){
        vec3P wagPoint = getWagPoint(getWagAmplitude_x(),
                                     getWagAmplitude_y(),
                                     1.0,
                                     givenTime/1000,
                                     getWagPhase());

        if (walkingForwards == false){
            wagPoint.points[0] = -wagPoint.points[0];
            wagPoint.points[1] = -wagPoint.points[1];
        }

        return wagPoint;

    }

};

#endif
