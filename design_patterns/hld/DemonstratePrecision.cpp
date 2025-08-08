#include <iostream>
#include <iomanip>
/**
 iomanip stands for Input/Output Manipulators and is a standard C++ header used to control formatting of data when using cin/cout.
 */
using namespace std;

int main() {
    double myValue = 123.456789;
    double anotherValue = 9.876;
    double aLargeValue = 1234567.89;

    // Default output without formatting
    cout << "Default output:" << endl;
    cout << myValue << endl;
    cout << anotherValue << endl;
    cout << aLargeValue << endl; //1234567.89 is a large number, and cout decides it's more readable in scientific notation (i.e., exponential format: 1.234567 × 10⁶).
    cout << endl;

    // Output with formatting
    cout << "Formatted output (fixed with 2 decimal places):" << endl;
    cout << fixed << setprecision(2);
    cout << myValue << endl;
    cout << anotherValue << endl;
    cout << aLargeValue << endl;

    return 0;
}
