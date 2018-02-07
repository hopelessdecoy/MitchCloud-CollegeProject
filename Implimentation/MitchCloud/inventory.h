#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include<limits>

using namespace std;

class inventory{
    public:
        inventory();
        ~inventory();

        void getMenu();
        void getStock();
        void getFilterMenu(string restriction);
        int processOrder(int menuNum);
        void appyShipment(int shipSize);
        void lowerStock(int menuNum);
        void custProcess();
        void writeToFile();

    private:
        string icFlavors[24];
        string icDietaryInfo[24];
        string toppings[20];
        int icStock[24];

        void readFrFile();
        void readFrFile2();
        void readFrFile3();
        void readFrFile4();
};

#endif // INVENTORY_H
