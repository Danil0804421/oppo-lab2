#include "Header.h"

vector<RealEstate> createObjectsFromFile(const string& filename) {
    vector<RealEstate> properties;
    ifstream file(filename);

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string type, owner, date, value;
        getline(iss, owner, ',');
        getline(iss, date, ',');
        getline(iss, value);

        int year, month, day;
        sscanf_s(date.c_str(), "%d.%d.%d", &year, &month, &day);

        Data registrationDate;
        registrationDate.setData(day, month, year); // Используем метод setData

        properties.push_back({ owner, registrationDate, stoi(value) });
    }
    return properties;
}

void printrealestateinfo(const vector<RealEstate>& properties) {
    for (const auto& property : properties) {
        cout << "Владелец: " << property.owner << endl;
        cout << "Дата постановки на учет: " << property.registrationDate.formattedDate() << endl;
        cout << "Ориентировочная стоимость: " << property.estimatedValue << endl;
        cout << endl;
    }
}
