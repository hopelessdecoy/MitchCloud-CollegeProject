#include "security.h"

security::security()
{
    //ctor
}

security::~security()
{
    //dtor
}

string security::loginName(){
    string tempUname;

    cout<< "Please enter User name: ";
    cin>> tempUname;
    return tempUname;
}

string security::loginPass(){
    string tempPass;

    cout<< "Please enter a Password: ";
    cin>> tempPass;
    return tempPass;
}

int security::secCheck(string name, string passw){
    // Cashier, Customer
    if((name == usrName[0] && passw== pass[0]) || (name == usrName[1] && passw== pass[1])){
        return 1;
    }else{
        // Manager
        if(name == usrName[2] && passw== pass[2]){
            return 2;
        }
        // Sales
        if(name == usrName[3] && passw== pass[3]){
            return 3;
        }
    }
}

void security::writeToLog(string log){
    ofstream outfile;
    outfile.open("data/SysLog.txt", ios_base::app);

    time_t now = time(0);
    tm *ltm = localtime(&now);

    outfile<< ltm->tm_hour<< ":"<< ltm->tm_min<< ":"<< ltm->tm_sec<< "_"<< ltm->tm_mday<< "/"<< ltm->tm_mon<< "/"<<  1900 + ltm->tm_year<< "___";
    outfile<< log<< "\n";
    outfile.close();
};

void security::readLog(){
    ifstream infile;
    string tempStr;

    infile.open("data/SysLog.txt");
    while (!infile.eof()) {
        infile >> tempStr;
        cout<< tempStr<< "\n";
    }
    infile.close();
};

int security::checkIN(int selection){
    if((!(cin>> selection)) || selection < 0){
        while(!(cin >> selection)) {
            cout << "Incorrect input. Hit ENTER to try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while(selection < 0){
            cout << "The number you entered is negative. Please enter a positive number to continue.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return selection;
};
