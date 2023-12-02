#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

struct Data {
    int day;
    int month;
    int year;

    // Метод для установки значений даты
    void setData(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    static Data parseDate(const string& dateStr) {
        int day, month, year;
        sscanf_s(dateStr.c_str(), "%d.%d.%d", &year, &month, &day);
        Data data;
        data.setData(day, month, year);
        return data;
    }

    // Метод для форматированного вывода даты
    string formattedDate() const {
        return to_string(year) + ", " + to_string(month) + ", " + to_string(day);
    }

};

struct RealEstate {
    string owner;
    Data registrationDate;
    int estimatedValue;
};

vector<RealEstate> createObjectsFromFile(const string& filename);

void printrealestateinfo(const vector<RealEstate>& properties);
