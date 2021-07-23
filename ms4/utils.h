
/* Citation and Sources...
Final Project Milestone 4
Module: utils
Filename: utils.h
Version 1.0
Author	Inae Kim
Seneca ID :  132329202
Seneca email : ikim36@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/22  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

//#ifndef SDDS_UTILS_H_
//#define SDDS_UTILS_H_
#include <iostream>
namespace sdds
{
    extern bool debug;
    int getTime(); // returns the time of day in minutes
    int getInt(
        const char* prompt = nullptr   // User entry prompt
    );
    int getInt(
        int min,   // minimum acceptable value
        int max,   // maximum acceptable value
        const char* prompt = nullptr,  // User entry prompt
        const char* errorMessage = nullptr, // Invalid value error message
        bool showRangeAtError = true    // display the range if invalud value entered 
    );
    char* getcstr(
        const char* prompt = nullptr,   // User entry prompt
        std::istream& istr = std::cin,  // the Stream to read from
        char delimiter = '\n'    // Delimiter to mark the end of data
    );
    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src);
    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len);
    // Compares two C-strings 
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2);
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len);
    // returns the lenght of the C-string in characters
    int strLen(const char* s);
    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2);
    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src);
}
//#endif // !SDDS_UTILS_H_


