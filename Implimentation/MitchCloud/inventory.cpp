#include "inventory.h"

inventory::inventory(){
    readFrFile();
    readFrFile2();
    readFrFile3();
    readFrFile4();
}

inventory::~inventory(){
    //dtor
}

void inventory::getMenu(){
    cout<< "\nICE CREAMS:"<< setw(65)<< right<< "DIETARY RESTRICTIONS:";
    for(int i= 0; i< 24; i++){
        cout<< "\n"<< i+1<< ". "<< icFlavors[i]<< setw(60 - icFlavors[i].length())<< right<< icDietaryInfo[i];
    }
    cout<< "\n\nTOPPINGS:";
    for(int j= 0; j< 14; j++){
        cout<< "\n"<< j+30<< ". "<< toppings[j];
    }
}

void inventory::getStock(){
    cout<< "\nICE CREAM STOCK BY PERCENT:";
    for(int i= 0; i< 24; i++){
        cout<< "\n"<< i<< ". "<< icFlavors[i]<< setw(60 - icFlavors[i].length())<< right<< icStock[i];
    }
}

int inventory::processOrder(int orderNum){
    int sentOrder= orderNum;
    return sentOrder;
}

void inventory::lowerStock(int menuNum){
    icStock[menuNum]-= 2;
}

void inventory::appyShipment(int shipSize){
    for(int i= 0; i< 24; i++){
        icStock[i] += shipSize;
    }
    getStock();
}

void inventory::getFilterMenu(string restriction){
    cout<< "\nFILTERRED ICE CREAMS:" << setw(55)<< right<< "DIETARY RESTRICTIONS:";
    if(restriction== "all"){
        for(int i= 0; i< 24; i++){
            if(icDietaryInfo[i] != "-None"){
                cout<< "\n"<< i<< ". "<< icFlavors[i]<< setw(60 - icFlavors[i].length())<< right<< icDietaryInfo[i];
            }
        }
    }else{
        for(int i= 0; i< 24; i++){
            if(icDietaryInfo[i] == ("-" + restriction)){
                cout<< "\n"<< i<< ". "<< icFlavors[i]<< setw(60 - icFlavors[i].length())<< right<< icDietaryInfo[i];
            }
        }
    }
    cout<< "\n\n";
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void inventory::readFrFile(){
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

void inventory::readFrFile2(){
    ifstream infile2;
    string tempStr;
    string token;
    const char s= ',';
    int i= 0;
    infile2.open("data/Dietary.txt");
    infile2 >> tempStr;

    istringstream strs1(tempStr);

    i= 0;
    while(getline(strs1, token, s)){
        icDietaryInfo[i]= token;
        i++;
    }
    infile2.close();
}
void inventory::readFrFile3(){
    ifstream infile3;
    string tempStr;
    string token;
    const char s= ',';
    int i= 0;
    infile3.open("data/Toppings.txt");
    infile3 >> tempStr;

    istringstream strs3(tempStr);

    i= 0;
    while(getline(strs3, token, s)){
        toppings[i]= token;
        i++;
    }
    infile3.close();
}
    ////////////////////////////////////////////////
void inventory::readFrFile4(){
    ifstream infile4;
    string tempStr;
    string token;
    const char s= ',';
    int i= 0;
    infile4.open("data/Stock.txt");
    infile4 >> tempStr;

    istringstream strs4(tempStr);

    i= 0;
    while(getline(strs4, token, s)){
        icStock[i]= stoi(token);
        i++;
    }
    infile4.close();
}
    ////////////////////////////////////////////////
void inventory::writeToFile(){
    ofstream outfile;
    outfile.open("data/Stock.txt");
    for(int i= 0; i< 24; i++){
        outfile<< icStock[i]<< ",";
        if(i== 23){
            outfile<< icStock[i];
        }
    }
    outfile.close();
};

