#include <vector>
#include <map>
#include <string>

#pragma once

//Структура описывающая одну точку в циклограмме
struct Point {
    std::map<std::string, double> cords; //Словарь степень свободы робота -> ее координата
    double time; //Время текущей точки
};

class Cyclogram {
private:

    std::vector<Point> points;
    std::vector<std::string> joints; //Вектор существующих степеней свободы
    void checkJoints(); //Функция для проверки степени свободы на существование
    void sortPoints(); //Функция для сортировки точек по времени

public:

    Cyclogram(std::vector<std::string> joints_list); //Конструктор, принимает вектор существующих степеней свободы
    std::vector<std::string> getJoints();
    int addPoint(std::map<std::string, double> cords, double time);

};
