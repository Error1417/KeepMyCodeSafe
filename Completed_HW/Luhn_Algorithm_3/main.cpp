#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring> // For strlen

using namespace std;

// Enumerated type for the credit card
enum CrdCard { AmericanExpress, Visa, MasterCard, Discover, ALL };

//Function Prototypes
char* genCC(CrdCard card); // luhn algorithm was added in here
void flipDig(char card[]);
void traDig(char card[]); //digit transposition
bool validCC(char card[]);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int validCount = 0, invalidCount = 0;

    // Loop 10,000 times
    for (int i = 0; i < 10000; i++) {
        CrdCard cardType = static_cast<CrdCard>(rand() % 5); // picks a card
        char* card = genCC(cardType); // generates valid card

        //print out the cards
        //cout << card << endl;
        
        //flip two in the function
        flipDig(card); // flips a random digit

        //transpose two in the function
        // Perform digit transposition
        traDig(card);

        //we should see a 10 to 1 for invalid to valid cards
        if (validCC(card)) validCount++; // valid cards
        else invalidCount++; // invalid cards

        delete[] card; //delete
    }

    float total = validCount + invalidCount;
    float validPercentage = (validCount / total) * 100;
    float invalidPercentage = (invalidCount / total) * 100;

    cout << "Valid Count: " << validCount << endl;
    cout << "Invalid Count: " << invalidCount << endl;
    cout << endl;
    cout << "Percentage of Valid Cards: " << validPercentage << "%" << endl;
    cout << "Percentage of Invalid Cards: " << invalidPercentage << "%" << endl;

    return 0;
}

char* genCC(CrdCard card) {
    int length;
    switch (card) {
    case AmericanExpress: length = 15; break;
    case Visa: length = rand() % 2 ? 13 : 16; break;
    case MasterCard: length = 16; break;
    case Discover: length = 16; break;
    case ALL: return genCC(static_cast<CrdCard>(rand() % 4));
    }

    char* cc = new char[length + 1];
    cc[length] = '\0';

    for (int i = 0; i < length - 1; i++) {
        cc[i] = '0' + rand() % 10;  // Not assigning random value to the last digit initially
    }

    int sum = 0;
    for (int i = length - 2; i >= 0; i -= 2) {
        int num = (cc[i] - '0') * 2;
        if (num >= 10) num -= 9;  // Subtracts 9 if the doubled value is more than 9
        sum += num;
    }

    for (int i = length - 1; i >= 0; i -= 2) {
        sum += cc[i] - '0';
    }

    int checksum = (sum * 9) % 10;
    cc[length - 1] = '0' + checksum;

    return cc;
}

void flipDig(char card[]) {
    int length = strlen(card); // getting the length of the string
    int idx1 = rand() % length;
    int idx2 = rand() % length;

    // Ensure that idx1 and idx2 are different
    while (idx2 == idx1) {
        idx2 = rand() % length;
    }

    // Flip two random digits
    int newDig1 = rand() % 10;
    int newDig2 = rand() % 10;

    card[idx1] = '0' + newDig1;
    card[idx2] = '0' + newDig2;
}

void traDig(char card[]) {
    int length = strlen(card); // getting the length of the string
    int idx1 = rand() % length;
    int idx2 = rand() % length;

    // Ensure that idx1 and idx2 are different
    while (idx2 == idx1) {
        idx2 = rand() % length;
    }

    // Swap the digits at idx1 and idx2
    char temp = card[idx1];
    card[idx1] = card[idx2];
    card[idx2] = temp;
}

bool validCC(char card[]) {
    int length = strlen(card);// getting the length of the string
    int sum = 0;
    for (int i = length - 1; i >= 0; i -= 2) {
        int num = card[i] - '0';
        sum += num;
    }
    for (int i = length - 2; i >= 0; i -= 2) {
        int num = (card[i] - '0') * 2;
        sum += num / 10 + num % 10;
    }

    return sum % 10 == 0;
}


