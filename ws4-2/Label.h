/* Workshop 4 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/21
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 

#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_
#include <iostream>
namespace sdds
{
    class Label
    {
        char* m_frame;
        char* m_content;
        int m_width;
        void setToDefault();
        void setName(const char* str);
        void setContent(const char* content);
        int Width();
        bool isEmpty()const;
    public: 
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream& printLabel()const;


    };

}
#endif
