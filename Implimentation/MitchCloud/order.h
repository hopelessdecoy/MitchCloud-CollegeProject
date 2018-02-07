#ifndef ORDER_H
#define ORDER_H

#include "salesAnalysis.h"

class order{
    public:
        order();
        ~order();

        void getMenu(string*, string*);
        void addToReciept(int item);
        void getReciept();
        float getCustCost();

    private:
        string custCart;
        float custCost= 0.00;

        const float icPrice= 6.20;
        const float topPrice= 0.35;
        string icFlavors[24];
        string toppings[20];

        void readFrFile();
        void readFrFile2();
};

#endif // ORDER_H
