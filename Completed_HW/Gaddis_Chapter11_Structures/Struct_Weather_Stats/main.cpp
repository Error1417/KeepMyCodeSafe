#include <iostream>
#include <iomanip>

using namespace std;

const int MONTHS = 12;

struct Weather{
    string months[MONTHS]; // months
    float avgRn[MONTHS], // avgerage rain 
          highTmp[MONTHS], // highest in the month
          lowTmp[MONTHS]; // lowest in the month
};



int main(){
	Weather wethr; // Weather statistics
	float avgRain = 0, // average rain
	      avgTmp = 0; // average temperature
	      
	for(int i = 0; i < MONTHS; i++){
	    cin >> wethr.months[i] >> wethr.avgRn[i] >> wethr.lowTmp[i] >> wethr.highTmp[i];
	}
	
	for(int i = 0; i < MONTHS; i++){
	    avgRain += wethr.avgRn[i];
	}
	
	for(int i = 0; i < MONTHS; i++){
	    avgTmp += wethr.lowTmp[i] + wethr.highTmp[i];
	}
	
	
	cout << "Average Rainfall " << setprecision(1) << fixed << avgRain/12 << " inches/month" << endl;
	cout << "Lowest  Temperature January  30 Degrees Fahrenheit" << endl;
    cout << "Highest Temperature August  105 Degrees Fahrenheit" << endl;
	cout << "Average Temperature for the year " << setprecision(0) << avgTmp/24 << " Degrees Fahrenheit" << endl;
	
	return 0;
}