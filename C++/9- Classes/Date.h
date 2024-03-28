#include <iostream>
/// Guards - to prevent header file from being included twice
#ifndef DATE_H
#define DATE_H
using namespace std;

/// OOP - based on objects that encapsulate the data and functions that work on them
/// Class - a programmer-defined data type used to define objects.
class Date
{
    /*
    * Access Specifiers:
    *                   private (default): can only be called or accessed by member functions (functions of inheritance class won't be able to access it)
    *                   protected: can only be called or accessed by member functions (functions of inheritance class will be able to access it)
    *                   public: can be accessed by functions outside of the class.
    
    */
    // Attributes/Member variables are usually private. A private member function can only be called by another private function of the same class
    private:
        int day; 
        int month;
        int year;
    
    // Setters and getters functions are usually public
    public:

        /// Member Functions - procedures/functions that act on the attributes of the class. They are part of the class definition, we can place the entire function definition inside the class (inline functions) or just the prototype (to be defined elsewhere)
        // Constructor - member function used to initialize data members of a class. It must be public with the same name as the class and cannot have a return type
        /*Date() // Default constructor - takes no argument due to no parameters OR all parameters have default values. If a class has any programmer-defined constructors, it must have a programmer-defined default constructor
        {
            day = 0;
            month = 0;
            year = 0;
        }*/

        Date(int d = 0, int m = 0, int y = 0) //Also a default constructor as all parameters have default values
        {
            setDay(d);
            setMonth(m);
            setYear(y);
        }

        // Mutator/Setter functions - modifies a member variable
        void setDay(int d)
        {
            day = d;
        }

        void setMonth(int m)
        {
            month = m;
        }

        void setYear(int y)
        {
            year = y;
        }


        // Accesor/Getter function - uses, acceses a member variable but does not modify it
        int getDay() const
        {
            return day;
        }

        int getMonth() const
        {
            return month;
        }

        int getYear() const
        {
            return year;
        }

        // Functions Prototype, to be define elsewhere
        void printDate();

        // Destructor - member function automatically called when an object is to be destroyed
        ~Date()
        {

        }
};

#endif