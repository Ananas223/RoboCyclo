#include "Cyclogram.h"

Cyclogram::Cyclogram(std::vector<std::string> joints_list){
    joints = joints_list;
}

std::vector<std::string> Cyclogram::getJoints() {
    return joints;
}