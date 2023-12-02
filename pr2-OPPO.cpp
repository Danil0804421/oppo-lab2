#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");
    string filename = "task.txt";
    vector<RealEstate> propertyObjects = createObjectsFromFile(filename);
    printrealestateinfo(propertyObjects);
    return 0;
}
