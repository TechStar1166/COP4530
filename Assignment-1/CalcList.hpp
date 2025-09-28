/* 
CalcList.hpp 

Name: 
U-Number: 

Instructions: 

● Add the CalcListInterface class and the CalcList class to this file.
● Implement the CalcList class in the CalcList.cpp file.
● Do not change the names or parameters of any of the methods in the CalcListInterface class.
● Do not change the names or parameters of any of the methods in the CalcList class.
● Do not change the name of the FUNCTIONS enum or the values in the enum.
● Do not add any additional public methods to the CalcList class.
● You may add private methods and private member variables to the CalcList class as needed.
● You may add additional #include statements if needed.

*/

// ifndef and define to prevent multiple inclusions
#ifndef CALCLIST_HPP
#define CALCLIST_HPP

// Include the CalcListInterface header
#include "CalcListInterface.hpp"
// Include necessary standard libraries
#include <string>

// Node structure for linked list
struct Node {
    FUNCTIONS operation;    // What operation was performed (+, -, *, /)
    double operand;        // The number used in the operation
    double totalBefore;    // What the total was BEFORE this operation
    double totalAfter;     // What the total was AFTER this operation
    Node* next;           // Pointer to the next node
    
    // Constructor to make creating nodes easier
    Node(FUNCTIONS op, double oper, double before, double after) 
        : operation(op), operand(oper), totalBefore(before), totalAfter(after), next(nullptr) {}
};

class CalcList : public CalcListInterface {
private:
    Node* head;           // Points to the most recent operation (top of list)
    double currentTotal;  // Current running total
    int operationCount;   // How many operations we've done
    
    // Helper function to convert FUNCTIONS enum to operator symbol
    char functionToSymbol(FUNCTIONS function) const;

public:
    // Constructor
    CalcList();
    
    // Destructor to clean up memory
    ~CalcList();
    
    // Required methods from interface
    double total() const override;
    void newOperation(const FUNCTIONS function, const double operand) override;
    void removeLastOperation() override;
    std::string toString(unsigned short precision) const override;
};

#endif /* CALCLIST_HPP */