/* 
CalcList.cpp 

Name: Amrit Selva Ganesh
U-Number: U31598674

Instructions: 

    For Programming Project 1, the student will implement a linked list based arithmetic calculator. 
    he calculator will be able to perform addition, subtraction, multiplication, and division. The 
    calculator will keep a running total of the operations completed, the number of operations 
    completed, and what those operations were. The calculator will also have an "undo" function for 
    removing the last operation. The calculator will also be able to output a string of the operations 
    completed so far with fixed precision.

    The calculator (which must be called “CalcList”) has to be implemented using a singly, doubly, or 
    circularly linked list. Any projects that use the C++ Standard Library Lists or other sources to 
    implement the linked list will receive a zero. The calculator has to implement at least four 
    methods:

    Abstract Class and Files 

        double  t o t a l ( )   const

        This method returns the current total of the CalcList. Total should run as a constant time 
        operation. The program should not have to iterate through the entire list each time the total is 
        needed.

        void  newOperation(const  FUNCTIONS  f u n c ,   const  double  operand)

        Adds an operation to the CalcList and creates a new total. The operation alters total by using
        the function with the operand. Example: new O per at i on( A D D I T I O N ,   1 0 )  => adds 10 to the 
        total.

        void  removeLastOperation()
        
        Removes the last operation from the calc list and restores the previous total.
        s t d : : s t r i n g   t o S t r i n g ( u n s i g n e d   s h o r t   p r e c i s i o n )   const
        Returns a string of the list of operations completed so far formatted with a fixed point precision. 
        The form of the string should strictly be: "(step): (totalAtStep)(Function)(operand) = (newTotal) 
        \n".

        Example: t o S t r i n g ( 2 )   =>  " 3 :   3 0 . 0 0 * 1 . 0 0 = 3 0 . 0 0 \ n 2 :   10.00+20.00=30.00\n1:
        0.00+10.00=10.00\n"

        This project includes an abstract class for the CalcList from which to inherit. This abstract class 
        (CalcListInterface) contains the pure virtual version of all the required methods. This file also 
        includes a typedef of an enum used for the four arithmetic functions called FUNCTIONS.
        Error Message handling and Throw exceptions Handling

        Your code will be tested for all functionality and in order to successfully pass the test cases, 
        please ensure the following is included in your CaclList.cpp File
        
        • Throw a  std::invalid_argument with message “ Cannot Divide By Zero” 
        • Throw std::runtime_error with message “No Operations to Remove”
*/