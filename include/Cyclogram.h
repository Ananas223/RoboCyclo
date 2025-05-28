#include <vector>
#include <map>
#include <string>
#include <algorithm>

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
    bool checkJoints(std::vector<std::string> joints_list); //Функция для проверки степени свободы на существование
    static bool comparePoints(const Point& a, const Point& b);
    void sortPoints(); //Функция для сортировки точек по времени

public:

    Cyclogram(std::vector<std::string> joints_list); //Конструктор, принимает вектор существующих степеней свободы
    std::vector<std::string> getJoints();
    void addPoint(std::map<std::string, double> cords, double time);

};
