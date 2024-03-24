#include <iostream>
using namespace std;

class Date
{
    
    private:
       int day;
       int month;
       int year;
    public:
       Date(int day, int month, int year)
       {
        setDay(day);
        setMonth(month);
        setYear(year);
       }

       void setDay(int day)
       {
        day = this.day;
       }

       void setMonth(int month)
       {
        month = this.month;
       }

       void setYear(int year)
       {
        year = this.year;
       }

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

}
