#include <iostream>
#include <stdexcept>
#include "CalcList.hpp"
using namespace std;

int main() {
    cout << "=== Manual Debug Test ===" << endl;
    
    CalcList testCalc;
    cout << "Initial total: " << testCalc.total() << endl;

    cout << "\nTesting removeLastOperation on empty list:" << endl;
    try {
        testCalc.removeLastOperation();
    } catch (const runtime_error& e) {
        cout << "Caught error: " << e.what() << endl;
    }

    cout << "\nTesting subtraction operation:" << endl;
    try {
        testCalc.newOperation(SUBTRACTION, 3);
        cout << "After subtraction 3, total: " << testCalc.total() << endl;
    } catch (const exception& e) {
        cout << "Caught error: " << e.what() << endl;
    }

    cout << "\nTesting division by zero:" << endl;
    try {
        testCalc.newOperation(DIVISION, 0);
        cout << "Division by zero succeeded - THIS IS WRONG!" << endl;
    } catch (const invalid_argument& e) {
        cout << "Caught error: " << e.what() << endl;
    }

    cout << "\nFinal toString(2) output:" << endl;
    string result = testCalc.toString(2);
    if (result.empty()) {
        cout << "(empty string)" << endl;
    } else {
        cout << "'" << result << "'" << endl;
    }
    
    cout << "\n=== Test Complete ===" << endl;

    return 0;
}