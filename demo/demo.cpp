#include "../include/Cyclogram.h"
#include <vector>
#include <string>

int main(){
    //Создание объекта класса Cyclogram
    std::vector<std::string> jnt = {"Joint_1", "Joint_2", "Joint_3"};
    Cyclogram my_cycle(jnt);

    // Словарь степень свободы -> текущая координата
    std::map<std::string, double> new_p = {
            {"Joint_1", 0.7},
            {"Joint_2", 1.2},
            {"Joint_3", 3.4}
    };

    // Добавления новой точки
    my_cycle.addPoint(new_p, 0.5);

    // Сохранение в CSV
    my_cycle.saveCSV("test.csv");

    return 0;
}