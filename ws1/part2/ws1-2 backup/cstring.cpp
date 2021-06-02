#include <iostream>
#include "cstring.h"
using namespace std;
namespace sdds
{
    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src)
    {

        
   /*     while (*src != '\0'  )
        {
            *des = *src;
            src++;
            des++;
        }*/
        int count = 0;

        while (src[count] != '\0')
        {
            des[count] = src[count];
            ++count;
        }

        des[count] = '\0';
     
      /*  while ((*des++ = *src++) != 0)
        {
        }*/
 
    }
    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len)
    {
        int i;
        for (i = 0; i < len; i++)
        {
            *des = *src;
            des++;
            src++;
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


        int i;
        for (; *str1; str1++)
        {
            if (*str1 == *str2)
            {
                for (i = 1;*(str1 + i) == *(str2 + i);i++);

                if (i == strLen(str2))
                {
                    return str1;
                }


            }

        }

        return NULL;
    }


    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src)
    {
        int w = strLen(des);
        int i = 0;
        while (src[i] != '\0')
        {
            des[w++] = src[i++];

        }
        des[w] = '\0';

    }
}
