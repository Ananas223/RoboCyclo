#include "Cyclogram.h"

Cyclogram::Cyclogram(std::vector<std::string> joints_list){
    joints = joints_list;
}

std::vector<std::string> Cyclogram::getJoints() {
    return joints;
}

bool Cyclogram::checkJoints(std::vector<std::string> joints_list) {
    return joints_list == joints;
}

bool Cyclogram::comparePoints(const Point &a, const Point &b) {
    return a.time < b.time;
}

void Cyclogram::sortPoints() {
    std::sort(points.begin(), points.end(), comparePoints);
}