#include "Cyclogram.h"

Cyclogram::Cyclogram(std::vector<std::string> joints_list){
    joints = joints_list;
}

std::vector<std::string> Cyclogram::getJoints() {
    return joints;
}

bool Cyclogram::checkJoints(std::map<std::string, double> cords) {
    // Создается пустой список joints_list в который записываются степени свободы из словаря cords
    std::vector<std::string> joints_list;
    // Цикл проходит по каждому элементу cords и добавляет его ключ в joints_list
    for(auto it = cords.begin(); it != cords.end(); ++it){
        joints_list.push_back(it->first);
    }
    return joints_list == joints;
}

bool Cyclogram::comparePoints(const Point &a, const Point &b) {
    return a.time < b.time;
}

void Cyclogram::sortPoints() {
    std::sort(points.begin(), points.end(), comparePoints);
}

void Cyclogram::addPoint(std::map<std::string, double> cords, double time) {
    if (!checkJoints(cords)){
        throw std::invalid_argument("Incorrect joints!");
    } else {
        Point new_p;
        new_p.time = time;
        new_p.cords = cords;
        points.push_back(new_p);
        sortPoints();
    }
}

void Cyclogram::addPoint(Point new_p) {
    if (!checkJoints(new_p.cords)) {
        throw std::invalid_argument("Incorrect joints!");
    } else {
        points.push_back(new_p);
        sortPoints();
    }
}

void Cyclogram::saveCSV(const std::string& file_name) {
    std::ofstream out(file_name);
    // Создание первой строки таблицы
    out << "time";
    for(const auto& joint : joints){
        out << "," << joint;
    }
    out << "\n";

    // Добавление остальных строк
    for(const auto& point : points){
        // Запись текущего времени
        out << point.time << ",";
        // Запись текущей координаты для каждой степени свободы
        for(const auto& cord : point.cords){
            out << cord.second << ",";
        }
        out << "\n";
    }
    out.close();
}