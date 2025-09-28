/* 
CalcList.cpp 

Name: 
U-Number: 

Restrictions:

● Do not change the names or parameters of any of the methods in the CalcList class.
● Do not add any additional public methods to the CalcList class.
● You may add private methods and private member variables to the CalcList class as needed.
● You may add additional #include statements if needed.  

*/

#include "CalcList.hpp"
#include <stdexcept>  // for std::invalid_argument and std::runtime_error
#include <sstream>    // for std::stringstream
#include <iomanip>    // for std::fixed and std::setprecision

// Constructor - Initialize empty calculator
CalcList::CalcList() : head(nullptr), currentTotal(0.0), operationCount(0) {
    // Start with empty list and zero total
}

// Destructor - Clean up all allocated memory
CalcList::~CalcList() {
    // Remove all operations to free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Return current total (constant time operation)
double CalcList::total() const {
    return currentTotal;
}

// Add a new operation to the calculator
void CalcList::newOperation(const FUNCTIONS function, const double operand) {
    // Check for division by zero - EXACT error message required
    if (function == DIVISION && operand == 0.0) {
        throw std::invalid_argument("Cannot divide by zero.");
    }
    
    // Store the total before this operation
    double previousTotal = currentTotal;
    
    // Calculate new total based on operation
    switch (function) {
        case ADDITION:
            currentTotal += operand;
            break;
        case SUBTRACTION:
            currentTotal -= operand;
            break;
        case MULTIPLICATION:
            currentTotal *= operand;
            break;
        case DIVISION:
            currentTotal /= operand;  // We already checked for zero above
            break;
    }
    
    // Create new node with this operation
    Node* newNode = new Node(function, operand, previousTotal, currentTotal);
    
    // Add to front of linked list (most recent operation first)
    newNode->next = head;
    head = newNode;
    
    // Increment operation counter
    operationCount++;
}

// Remove the last operation and restore previous total
void CalcList::removeLastOperation() {
    // Check if there are any operations to remove - EXACT error message required
    if (head == nullptr) {
        throw std::runtime_error("No operations to remove.");
    }
    
    // Restore the total to what it was before the last operation
    currentTotal = head->totalBefore;
    
    // Remove the first node (most recent operation)
    Node* nodeToDelete = head;
    head = head->next;
    delete nodeToDelete;
    
    // Decrement operation counter
    operationCount--;
}

// Convert the list of operations to a formatted string
std::string CalcList::toString(unsigned short precision) const {
    if (head == nullptr) {
        return "";  // Empty string if no operations
    }
    
    std::stringstream result;
    result << std::fixed << std::setprecision(precision);
    
    // We need to traverse the list and number operations from most recent to oldest
    int stepNumber = operationCount;
    
    // Traverse the list and build the string
    Node* current = head;
    while (current != nullptr) {
        // Format: "step: totalBefore(symbol)operand=totalAfter\n"
        result << stepNumber << ": "
               << current->totalBefore
               << functionToSymbol(current->operation)
               << current->operand
               << "="
               << current->totalAfter
               << "\n";
        
        current = current->next;
        stepNumber--;
    }
    
    return result.str();
}

// Helper function to convert FUNCTIONS enum to operator symbol
char CalcList::functionToSymbol(FUNCTIONS function) const {
    switch (function) {
        case ADDITION:
            return '+';
        case SUBTRACTION:
            return '-';
        case MULTIPLICATION:
            return '*';
        case DIVISION:
            return '/';
        default:
            return '?';  // Should theoretically and practically never happen
    }
}