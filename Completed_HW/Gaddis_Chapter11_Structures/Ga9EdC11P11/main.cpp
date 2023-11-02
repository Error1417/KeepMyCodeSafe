/* 
 * File:   
 * Author: Ismael Perez
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
struct MonthlyBudget{
    float husing=500.00, // housing 
          utls=150.00, // utilities
          housEx=65.00, // household expenses
          transpr=50.00, // Transportation
          food=250.00, // food cost
          medcl=30.00, // medical cost
          inurnce=100.00, // insurance
          entrmnt=150.00, // Entertainment
          clthng=75.00, // clothing
          mislus=50.00; // Miscellaneious
};

struct MonthlySpent{
    float husing, // housing 
          utls, // utilities
          housEx, // household expenses
          transpr, // Transportation
          food, // food cost
          medcl, // medical cost
          inurnce, // insurance
          entrmnt, // Entertainment
          clthng, // clothing
          mislus; // Miscellaneious
};
//Function Prototypes

void input(MonthlySpent &);
void output(MonthlySpent &, MonthlyBudget);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    MonthlyBudget MonBug; // MonthlyBudget structure
    MonthlySpent MonSpt; // Monthly amount spent
    
    input(MonSpt);
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    
    //Display Outputs
    output(MonSpt, MonBug);
    //Exit stage right!
    return 0;
}


void input(MonthlySpent &s){
    cout << "Enter housing cost for the month:$" << endl;
    cin >> s.husing;
    
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> s.utls;
    
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> s.housEx;
    
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> s.transpr;
    
    cout << "Enter food cost for the month:$" << endl;
    cin >> s.food;
    
    cout << "Enter medical cost for the month:$" << endl;
    cin >> s.medcl;
    
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> s.inurnce;
    
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> s.entrmnt;
    
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> s.clthng;
    
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> s.mislus;
}



void output(MonthlySpent &s, MonthlyBudget b){
    cout << setprecision(2) << showpoint << fixed;
    
    float spentTot, // total spent 
          budgTot, // budget total
          final; // final over or under total
          
    
    //Housing
    if(s.husing < b.husing) cout << "Housing Under" << endl;
    else if(s.husing > b.husing) cout << "Housing Over" << endl;
    else cout << "Housing Even" << endl;
    
    //Utilities
    if(s.utls < b.utls) cout << "Utilities Under" << endl;
    else if(s.utls > b.utls) cout << "Utilities Over" << endl;
    else cout << "Utilities Even" << endl;

    //Household Expenses
    if(s.housEx < b.housEx) cout << "Household Expenses Under" << endl;
    else if(s.housEx > b.housEx) cout << "Household Expenses Over" << endl;
    else cout << "Household Expenses Even" << endl;
    
    //Transportations
    if(s.transpr < b.transpr) cout << "Transportation Under" << endl;
    else if(s.transpr > b.transpr) cout << "Transportation Over" << endl;
    else cout << "Transportation Even" << endl;
    
    //Food
    if(s.food < b.food) cout << "Food Under" << endl;
    else if(s.food > b.food) cout << "Food Over" << endl;
    else cout << "Food Even" << endl;
    
    //Medical
    if(s.medcl < b.medcl) cout << "Medical Under" << endl;
    else if(s.medcl > b.medcl) cout << "Medical Over" << endl;
    else cout << "Medical Even" << endl;
    
    //Insurance 
    if(s.inurnce < b.inurnce) cout << "Insurance Under" << endl;
    else if(s.inurnce > b.inurnce) cout << "Insurance Over" << endl;
    else cout << "Insurance Even" << endl;
    
    //Entertainment
    if(s.entrmnt < b.entrmnt) cout << "Entertainment Under" << endl;
    else if(s.entrmnt > b.entrmnt) cout << "Entertainment Over" << endl;
    else cout << "Entertainment Even" << endl;
    
    //Clothing
    if(s.clthng < b.clthng) cout << "Clothing Under" << endl;
    else if(s.clthng > b.clthng) cout << "Clothing Over" << endl;
    else cout << "Clothing Even" << endl;
    
    //Miscellaneous
    if(s.mislus < b.mislus) cout << "Miscellaneous Under" << endl;
    else if(s.mislus > b.mislus) cout << "Miscellaneous Over" << endl;
    else cout << "Miscellaneous Even" << endl;
    
    spentTot = s.husing + s.utls + s.housEx + s.transpr + s.food + s.medcl + s.inurnce + s.entrmnt + s.clthng + s.mislus;
    budgTot = b.husing + b.utls + b.housEx + b.transpr + b.food + b.medcl + b.inurnce + b.entrmnt + b.clthng + b.mislus;
    
    
    if(spentTot > budgTot){
        final = spentTot - budgTot;
        cout << "You were $" << final << " over budget";
    }
    
    else if(spentTot < budgTot){
        final = budgTot - spentTot;
        cout << "You were $" << final << " under budget";
    }
    
    else{
        final = budgTot - spentTot;
        cout << "You were $" << final <<  " even budget"<< endl;
    }
}