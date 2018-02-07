#include "salesAnalysis.h"

salesAnalysis::salesAnalysis(){
    readFrFile();
}

salesAnalysis::~salesAnalysis(){
    //dtor
}

float salesAnalysis::getSales(){
    return totalSales;
}

float salesAnalysis::getBreakEvenProfit(){
    return (totalSales - overhead);
}

float salesAnalysis::getOverhead(){
    return overhead;
}

void salesAnalysis::addOverhead(float cost){
    overhead+= cost;
}

void salesAnalysis::addSales(float profit){
    totalSales+= profit;
}

void salesAnalysis::setBreakEven(){
    breakinEven= totalSales - overhead;
}

void salesAnalysis::readFrFile(){
    ifstream infile1;
    string tempStr;
    string token;

    const char s= ',';
    int i= 0;

    infile1.open("data/Sales.txt");
    infile1 >> tempStr;

    istringstream strs(tempStr);


    while(getline(strs, token, s)){
        if(i== 0){
            totalSales= stof(token);
        }else if(i== 1){
            overhead= stof(token);
        }else{
            breakinEven= stof(token);
            break;
        }
        i++;
    }
    infile1.close();
}

void salesAnalysis::writeToFile(){
    ofstream outfile;
    outfile.open("data/Sales.txt");

    outfile<< totalSales<< ",";
    outfile<< overhead<< ",";
    outfile<< breakinEven;
    outfile.close();
};
