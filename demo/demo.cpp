#include "../include/Cyclogram.h"
#include <vector>
#include <string>

int main(){
    //Создание объекта класса Cyclogram
    std::vector<std::string> jnt = {"Joint_1", "Joint_2", "Joint_3"};
    Cyclogram my_cycle(jnt);

    return 0;
}