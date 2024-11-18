#include <iostream>  // Library required to use input/output operations
#include <string>    // Library to handle the card number as a string
using namespace std; // Sets the default namespace to avoid using std::prefix



bool checkLuhn(const string& cardNumber) {      // To check if the card number is valid using the Luhn Algorithm
    int sum = 0;                                // Initialize sum to store the cumulative total of processed digits
    bool doubleDigit = false;                   // Flag to indicate whether to double the digit

    
    for (int i = cardNumber.length() - 1; i >= 0; i--) {    // Loop through each digit of the card number from right to left
        int digit = cardNumber[i] - '0';                    // It converts the current character into an integer digit

        
        if (doubleDigit) {       // It checks if this digit should be doubled or not
            digit *= 2;          // It doubles the digit
            if (digit > 9) {     // If doubling results in a number >9 
                digit -= 9;      // subtract 9 from it to get sum of the digits
            }
        }

        sum += digit;                   // Add processed digit to cumulative sum
        doubleDigit = !doubleDigit;     // Alternate the doubling for the next digit
    }

    
    return (sum % 10 == 0);             // If the sum modul 10 is zero, the card number is valid; otherwise, it is invalid
}

int main() {
    string cardNumber;                  // Variable to store user's input for the card number

    
    cout << "Enter a 16-digit credit card number: ";    // Asks the user to enter the 16-digit credit card number
    cin >> cardNumber;                                  // Stores the credit card number into the string

    
    if (checkLuhn(cardNumber)) {                                // It checks if the entered card number is valid using the Luhn Algorithm
        cout << "The credit card number is valid." << endl;     // Output if the card is valid
    }
    else {
        cout << "The credit card number is invalid." << endl;  // Output if the card is invalid
    }

    return 0;  // Program Ends
}
