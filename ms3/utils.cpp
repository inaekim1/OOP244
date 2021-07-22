/* Citation and Sources...
Final Project Milestone 3
Module: utils
Filename: utils.cpp
Version 1.0
Author	Inae Kim
Seneca ID :  132329202
Seneca email : ikim36@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/17  cstring functions added
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
    bool debug = false;  // made global in utils.h
    int getTime()
    {
        int mins = -1;
        if (debug)
        {
            Time t(0);
            cout << "Enter current time: ";
            do
            {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin)
                {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else
                {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    int getInt(const char* prompt)
    {
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        int value = 0;
        char ch{};
        cin >> value;
        cin.get(ch);
        while (cin.fail() || ch != '\n')
        {
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
            }
            else if (ch != '\n')
            {
                cout << "Enter only an integer, try again: ";
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> value;
            cin.get(ch);
        }
        cin.clear();
        return value;

    }
    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
    {
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        int value = 0;
        char ch{};
        cin >> value;
        cin.get(ch);
        while (cin.fail() || ch != '\n' || value < min || value > max)
        {
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (ch != '\n')
            {
                cout << "Enter only an integer, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (value < min || value > max)
            {
                if (errorMessage != nullptr)
                {
                    cout << errorMessage;
                }
                if (showRangeAtError)
                {
                    cout << "[" << min << " <= value <= " << max << "]: ";
                }
            }
            cin.clear();
            cin >> value;
            cin.get(ch);
        }
        cin.clear();

        return value;
    }
    char* getcstr(
        const char* prompt,   // User entry prompt
        std::istream& istr,  // the Stream to read from
        char delimiter   // Delimiter to mark the end of data
    )
    {
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        char str[1800]{};
        char* str2 = nullptr;
        istr.getline(str, 1000, delimiter);
        str2 = new char[strlen(str) + 1]; //186 mem leak
        strcpy(str2, str);

        return str2;
    }
    void strCpy(char* des, const char* src)
    {
        int count = 0;

        while (src[count] != '\0')
        {
            des[count] = src[count];
            count++;
        }

        des[count] = '\0';

    }
    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len)
    {
        int count;
        for (count = 0; count < len; count++)
        {
            des[count] = src[count];

        }
        des[count] = '\0';
    }
    // Compares two C-strings 
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2)
    {
        int count = 0;
        while (s1[count] != '\0' && s2[count] != '\0' && s1[count] == s2[count])
        {
            count++;
        }
        return s1[count] - s2[count];
    }
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len)
    {
        int count = 0;

        while (len == 0 || (s1[count] != '\0' && s2[count] != '\0' && s1[count] == s2[count]))
        {
            count++;
            len--;
        }
        return s1[count] - s2[count];
    }
    // returns the lenght of the C-string in characters
    int strLen(const char* s)
    {
        int count = 0;
        while (s[count] != '\0')
        {
            count++;
        }
        return count;
    }
    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2)
    {
        int limit, i, j;
        const char* ret = NULL;
        limit = strLen(str1) - strLen(str2);

        for (i = 0; i < limit; i++)
        {
            if (str1[i] == str2[0])
            {
                for (j = 1; j < strLen(str2); j++)
                {
                    if (str1[i + j] != str2[j])
                    {
                        break;
                    }
                }
                if (j == strLen(str2))
                {
                    ret = (char*)(str1 + i);
                }

            }

        }
        return ret;

    }
    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src)
    {
        int start = strLen(des);
        int i;

        for (i = 0; src[i] != '\0'; i++, start++)
        {
            des[start] = src[i];
        }

        des[start] = '\0';

    }

}
