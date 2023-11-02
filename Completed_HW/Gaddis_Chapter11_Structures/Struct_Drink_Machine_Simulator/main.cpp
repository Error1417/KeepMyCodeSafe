#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Machine{
    string name;
    float cost;
    int numDrink;
};


int main(){
    int NUMDRINK = 5, 
        x = 1,
        monMade = 0;
    Machine drink[NUMDRINK];
    
    drink[0].name = "Cola";
    drink[1].name = "Root Beer";
    drink[2].name = "Lemon-Lime";
    drink[3].name = "Grape Soda";
    drink[4].name = "Cream Soda";
    
    drink[0].cost = 75;
    drink[1].cost = 75;
    drink[2].cost = 75;
    drink[3].cost = 80;
    drink[4].cost = 80;
    
    drink[0].numDrink = 20;
    drink[1].numDrink = 20;
    drink[2].numDrink = 20;
    drink[3].numDrink = 20;
    drink[4].numDrink = 20;
    
    while(x > 0){
        string choiceVl;
        float money,
              total;
        int noMoney = 0,
            chceNum,
            chceCheck = 0;
            
        
        for(int i = 0; i < NUMDRINK; i++){
            cout << left << setw(11);
            cout << drink[i].name << drink[i].cost <<"  " << drink[i].numDrink << endl;
        }
        cout << "Quit" << endl;
        
        while(chceCheck == 0){
            getline(cin, choiceVl);
            
            if(choiceVl == drink[0].name){
                if(drink[0].numDrink != 0){
                    chceNum = 0;
                    chceCheck = 1;
                    drink[0].numDrink--;
                }
            }
            
            else if(choiceVl == drink[1].name){
                if(drink[0].numDrink != 0){
                    chceNum = 1;
                    chceCheck = 1;
                    drink[1].numDrink--;
                }
            }
            
            else if(choiceVl == drink[2].name){
                if(drink[0].numDrink != 0){
                    chceNum = 2;
                    chceCheck = 1;
                    drink[2].numDrink--;
                }
            }
            
            else if(choiceVl == drink[3].name){
                if(drink[0].numDrink != 0){
                    chceNum = 3;
                    chceCheck = 1;
                    drink[3].numDrink--;
                }
            }
            
            else if(choiceVl == drink[4].name){
                if(drink[0].numDrink != 0){
                    chceNum = 4;
                    chceCheck = 1;
                    drink[4].numDrink--;
                }
            }
            
            else if(choiceVl == "Quit"){
                cout << monMade << endl;
                return 0;
            }
            
            else{
                cout <<"Try again" << endl;
                chceCheck = 0;
            }
        }
    
        while(noMoney == 0){
            cin >> money;
            cin.ignore();
            
            if((money < 0) or (money > 100)){
                cout << "NO MONEY";
            }
            
            else{
                noMoney = 1;
            }
        }

        switch(chceNum){
            case 0:
                total = money - drink[0].cost;
                break;
            case 1:
                total = money - drink[1].cost;
                break;
            case 2:
                total = money - drink[2].cost;
                break;
            case 3:
                total = money - drink[3].cost;
                break;
            case 4:
                total = money - drink[4].cost;
        }
        
        cout << total << endl;
        monMade = monMade + (money-total);
    }
    
    return 0;
}