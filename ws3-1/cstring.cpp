/* Workshop 3 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/02

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
    using namespace std;
    namespace sdds
    {
        // Copies the srouce character string into the destination
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

 