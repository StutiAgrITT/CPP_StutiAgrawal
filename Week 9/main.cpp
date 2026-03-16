#include "Simulation.h"
#include "Intersection.h"
#include "TrafficLight.h"
#include "Lane.h"

int main() {
    Lane lane1(LANE_1);
    Lane lane2(LANE_2);
    Lane lane3(LANE_3);
    Lane lane4(LANE_4);

    TrafficLight light(&lane1, &lane2, &lane3, &lane4);

    lane1.setLight(&light);
    lane2.setLight(&light);
    lane3.setLight(&light);
    lane4.setLight(&light);

    Intersection intersection(&lane1, &lane2, &lane3, &lane4, &light);

    Simulation simulation(&intersection);
    simulation.run();

    return 0;
}