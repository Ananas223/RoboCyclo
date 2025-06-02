#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <fstream>

#pragma once

/*
 * Структура, описывающая точку
 * Содержит координаты каждой степени свободы в заданное время
 */
struct Point {
    std::map<std::string, double> cords; // Словарь степень свободы робота -> ее координата
    double time; // Время текущей точки
};

class Cyclogram {
private:

    std::vector<Point> points; // Вектор точек циклограммы
    std::vector<std::string> joints; // Вектор существующих степеней свободы

    /*
     * Метод для проверки степеней свободы на существование
     * Получает словарь степень свободы робота -> ее координата
     */
    bool checkJoints(std::map<std::string, double> cords);

    /*
     * Метод для сравнения двух точек по их времени
     * Принимает две сравниваемые точки
     * Используется для сортировки точек по возрастанию
     */
    static bool comparePoints(const Point& a, const Point& b);

    // Метод для сортировки точек по возрастанию времени
    void sortPoints();

public:

    /*
     * Конструктор класса
     * Принимает вектор существующих степеней свободы
     */
    Cyclogram(std::vector<std::string> joints_list);

    // Метод возвращающий существующие степени свободы
    std::vector<std::string> getJoints();

    /*
     * Метод для добавления новой точки
     * cords - словарь степень свободы робота -> ее текущая координата
     * time - время новой точки
     */
    void addPoint(std::map<std::string, double> cords, double time);

    /*
     * Метод для сохранения циклограммы в формате CSV
     * Принимает имя файла для сохранения циклограммы
     */
    void saveCSV(const std::string& file_name);

};
