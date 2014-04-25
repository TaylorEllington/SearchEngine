
// File:   DateStamp.cpp
// Author: taylor
// Id:     36679283
// Contents:
//

#include "DateStamp.hpp"


DateStamp::DateStamp() {
}
DateStamp::DateStamp(int _day, int _month, int _year) {
    setDate(_day, _month, _year);
}


DateStamp::DateStamp(const DateStamp& orig) {
}

DateStamp::~DateStamp() {
}


void DateStamp::setDate(int _day, int _month, int _year){
    day = _day;
    month = _month;
    year = _year;
    
}
int DateStamp::getDay(){
    return day;
    
}
int DateStamp::getMonth(){
    return month;
    
}
int DateStamp::getYear(){
    return year;
}



 ostream& operator<<( ostream& os,  DateStamp& ds ){
     // mm/dd/yyyy
     os << ds.getMonth() <<"/"<<ds.getDay() <<"/" <<ds.getYear();
     return os;
     
 }