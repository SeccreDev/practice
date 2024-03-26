#include <iostream>
using namespace std;

/// Class - a programmer-defined data type used to define objects.
class Date
{
    /*
    * Access Specifiers:
    *                   private (default): can only be called or accessed by member functions (functions of inheritance class won't be able to access it)
    *                   protected: can only be called or accessed by member functions (functions of inheritance class will be able to access it)
    *                   public: can be accessed by functions outside of the class.
    
    */
    // Member variables are usually private
    private:
        int day;
        int month;
        int year;

    // Setters and getters functions are usually public
    public:

        /// Member Functions - are part of the class definition, we can place the entire function definition inside the class (inline functions) or just the prototype (to be defined elsewhere)
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
        int getDay()
        {
            return day;
        }

        int getMonth()
        {
            return month;
        }

        int getYear()
        {
            return year;
        }

        // Functions Prototype, to be define elsewhere
        void printDate();
};
