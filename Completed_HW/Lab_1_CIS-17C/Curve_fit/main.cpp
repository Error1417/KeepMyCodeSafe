/* Project- Curve fit
 * Author- Ismael Perez
 * Date- 09/28/23
 * 
 * 
 * 
 */

#include <iostream>
#include <fstream>

using namespace std;

//structure for data in file
struct DataPoint {
    float deg_f;
    float deg_c;
};


float calculateIntercept(const DataPoint[], int, float); //intercept calculations
float calculateSlope(const DataPoint[], int); //slope calculations
float calculateMean(const float [], int); //calculating the mean values for x and y


int main() {
    ifstream file("data.txt");
    if (!file) {
        ofstream createFile("data.txt");
        if(!createFile) {
            cout << "Failed to create file." << endl;
            return 1;
        }
        createFile.close();
        cout << "File was created, but no data inside." << endl;
        return 0; // Exit as no data exists in a newly created file.
    }

    // Continue with your existing logic here
    // Count the number of data points
    int count = 0;
    float deg_f, deg_c;
    while (file >> deg_f >> deg_c) {
        count++;
    }
    file.close();

    if (count == 0) {
        cout << "No data points available." << endl;
        return 1;
    }

    // Assume DataPoint is a defined structure or class
    DataPoint data[count];

    // Reopen the file to read the data points
    file.open("data.txt");
    for (int i = 0; i < count && file >> deg_f >> deg_c; i++) {
        data[i] = {deg_f, deg_c};
    }
    file.close();

    float slope = calculateSlope(data, count);
    float intercept = calculateIntercept(data, count, slope);

    cout << "Calculations done using Celsius with error values" << endl;
    cout << "Slope (m): " << slope << endl;
    cout << "Intercept (b): " << intercept << endl;

    return 0;
}




float calculateMean(const float values[], int size) {
    if (size <= 0) return 0.0;
    
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum / size;
}


float calculateSlope(const DataPoint data[], int size) {
    if (size <= 0) return 0.0;
    
    float xVals[size];
    float yVals[size];

    for (int i = 0; i < size; i++) {
        xVals[i] = data[i].deg_f;
        yVals[i] = data[i].deg_c;
    }

    float meanX = calculateMean(xVals, size);
    float meanY = calculateMean(yVals, size);

    float numtor = 0.0;
    float denom = 0.0;
    
    for (int i = 0; i < size; i++) {
        numtor += (xVals[i] - meanX) * (yVals[i] - meanY);
        denom += (xVals[i] - meanX) * (xVals[i] - meanX);
    }
    
    if (denom == 0.0f) return 0.0; // to avoid division by zero
    return numtor / denom;
}


float calculateIntercept(const DataPoint data[], int size, float slope) {
    if (size <= 0) return 0.0;
    
    float xVals[size];
    float yVals[size];

    for (int i = 0; i < size; i++) {
        xVals[i] = data[i].deg_f;
        yVals[i] = data[i].deg_c;
    }

    float meanX = calculateMean(xVals, size);
    float meanY = calculateMean(yVals, size);

    return meanY - (slope * meanX);
}



