#include "order.h"

order::order(){
    readFrFile();
    readFrFile2();
}

order::~order(){
    //dtor
}


void order::readFrFile(){
    ifstream infile1;
    string tempStr;
    string token;
    const char s= ',';
    int i= 0;

    infile1.open("data/Flavors.txt");
    infile1 >> tempStr;

    istringstream strs(tempStr);


    while(getline(strs, token, s)){
        icFlavors[i]= token;
        i++;
    }
    infile1.close();
}

void order::readFrFile2(){
    ifstream infile2;
    string tempStr;
    string token;
    const char s= ',';
    int i= 0;
    infile2.open("data/Toppings.txt");
    infile2 >> tempStr;

    istringstream strs2(tempStr);

    i= 0;
    while(getline(strs2, token, s)){
        toppings[i]= token;
        i++;
    }
    infile2.close();
}

void order::addToReciept(int item){
    if(item < 25){
        custCart+= icFlavors[item] + "\n";
        custCost+= icPrice;
    }else{
        custCart+= toppings[item-30] + "\n";
        custCost+= topPrice;
    }
}

void order::getReciept(){
    cout<< "Ice Cream = $6.20       Toppings = $0.35\n";
    cout<< custCart;
    cout<< "\nTOTAL: $";
    cout<< custCost;
    cout<< "\n";
}

float order::getCustCost(){
    return custCost;
}
