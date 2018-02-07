#include "security.h"

int main(){
    security sys;
    string tempPass, tempUname;
    int selection, sizeOfShip, secCheck;

    tempUname= sys.loginName();
    tempPass= sys.loginPass();
    secCheck= sys.secCheck(tempUname, tempPass);

    if(secCheck>= 1){
        if(secCheck== 1){
            cout<< "\nWelcome ELEVATED USER! \nLoading updates...\nWelcome to Mitchel's Homemade Ice Cream!\n";
        }else{
            cout<< "\nWelcome USER! \nLoading updates...\nWelcome to Mitchel's Homemade Ice Cream!\n";
        }
        inventory inven;
        order cart;
        salesAnalysis numDat;
        sys.writeToLog("LOGGED_IN:" + tempUname);

        while(true){
            if(secCheck>= 2){
                cout<< "1= View menu   2= I have dietary restrictions   3= View cart   4= Exit   5= Elevated options(admin only)\n";
                selection= sys.checkIN(selection);
            }else{
                cout<< "1= View menu   2= I have dietary restrictions   3= View cart   4= Exit\n";
                selection= sys.checkIN(selection);
                if(selection> 4){
                    cout<< "Sorry, that is not an option!\n";
                    continue;
                }
            }
            /////////////////////////////////////////////////////////////
            if(selection== 1){
                inven.getMenu();
                cout<< "\nEnter choice or 0 to go back:\n";
                while(true){
                    selection= sys.checkIN(selection);;
                    if(selection== 0){
                        break;
                    }else{
                        cart.addToReciept(inven.processOrder(selection));
                        inven.lowerStock(selection);
                        if(selection>= 30){
                            numDat.addSales(6.20);
                        }else{
                            numDat.addSales(0.35);
                        }
                        sys.writeToLog("Item:" + to_string(selection) + "_ordered");
                        cout<< "Would you like more? Or toppings? Press 0 to go back:\n";
                    }
                }
            }
            /////////////////////////////////////////////////////////////
            if(selection== 2){
                cout<< "Please enter your restriction:\n"<< "1= Vegan       2=Egg Free      3=All   4= Back\n";
                selection= sys.checkIN(selection);
                if(selection== 1){
                    inven.getFilterMenu("Vegan");
                    cout<< "\nEnter choice or 0 to go back:\n";
                    while(true){
                        selection= sys.checkIN(selection);
                        if(selection== 0){
                            break;
                        }else{
                            cart.addToReciept(inven.processOrder(selection));
                            inven.lowerStock(selection);
                            if(selection>= 30){
                                numDat.addSales(6.20);
                            }else{
                                numDat.addSales(0.35);
                            }
                            sys.writeToLog("Item:" + to_string(selection) + "_ordered");
                            cout<< "Would you like more? Or toppings? Press 0 to go back:\n";
                        }
                    }
                }
                if(selection== 2){
                    inven.getFilterMenu("Egg_Free");
                    cout<< "\nEnter choice or 0 to go back:\n";
                    while(true){
                        selection= sys.checkIN(selection);
                        if(selection== 0){
                            break;
                        }else{
                            cart.addToReciept(inven.processOrder(selection));
                            inven.lowerStock(selection);
                            if(selection>= 30){
                                numDat.addSales(6.20);
                            }else{
                                numDat.addSales(0.35);
                            }
                            sys.writeToLog("Item:" + to_string(selection) + "_ordered");
                            cout<< "Would you like more? Or toppings? Press 0 to go back:\n";
                        }
                    }
                }
                if(selection== 3){
                    inven.getFilterMenu("all");
                    cout<< "\nEnter choice or 0 to go back:\n";
                    while(true){
                        selection= sys.checkIN(selection);
                        if(selection== 0){
                            break;
                        }else{
                            cart.addToReciept(inven.processOrder(selection));
                            inven.lowerStock(selection);
                            if(selection>= 30){
                                numDat.addSales(6.20);
                            }else{
                                numDat.addSales(0.35);
                            }
                            sys.writeToLog("Item:" + to_string(selection) + "_ordered");
                            cout<< "Would you like more? Or toppings? Press 0 to go back:\n";
                        }
                    }
                }
                if(selection!= 1 && selection!= 2 && selection!= 3){
                    continue;
                }
            }

            if(selection== 3){
                cart.getReciept();
                sys.writeToLog("Receipt_requested");
                continue;
            }
            /////////////////////////////////////////////////////////////
            if(selection== 4){
                break;
            }
            /////////////////////////////////////////////////////////////
            if(selection== 5){
                while(secCheck== 2){
                    cout<< "\n1= show stock       2= Order Stock      3=View System Logs        4= Back\n";
                    selection= sys.checkIN(selection);
                    if(selection== 1){
                        inven.getStock();
                        sys.writeToLog("Total_Stock_requested");
                    }
                    if(selection== 2){
                        cout<< "\nWhat was the size of the shipment in ounces?\n";
                        sizeOfShip= sys.checkIN(selection);
                        inven.appyShipment(sizeOfShip);
                        numDat.addOverhead(sizeOfShip * 2.60);
                        sys.writeToLog("Shipment_of=" + to_string(sizeOfShip));
                    }
                    if(selection== 3){
                        sys.readLog();
                        sys.writeToLog("Logs_Viewed");
                    }
                    if(selection> 3){
                        break;
                    }
                }
                while(secCheck== 3){
                    cout<< "\n1= Show Sales       2= Show Overhead      3=View Net Profit        4= Back\n";
                    selection= sys.checkIN(selection);
                    if(selection== 1){
                        sys.writeToLog("Sales_Numbers_Analysis_Viewed");
                        cout<< "\nTotal profits: "<< numDat.getSales()<< "\n";
                    }
                    if(selection== 2){
                        sys.writeToLog("Overhead_Analysis_Viewed");
                        cout<< "\nTotal business overhead: "<< numDat.getOverhead()<< "\n";
                    }
                    if(selection== 3){
                        sys.writeToLog("Net_Profits_Analysis_Viewed");
                        cout<< "\nNet Profits: "<< numDat.getBreakEvenProfit()<< "\n";
                    }
                    if(selection== 4){
                        break;
                    }
                }
            }
            numDat.writeToFile();
            inven.writeToFile();
        }
    }else{
        cout<< "\nI'm sorry your user name or password is incorrect please try again or contact customer support.\n";
        sys.writeToLog("incorrect_manager_login_USERNAME=" + tempUname + "_PASSWORD=" + tempPass);
    }
    sys.writeToLog("SYS_EXIT");
    return 0;
}
