/* Workshop 6 part 1
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/07/08
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 
// version 2 : I removed comments and added reflect.txt. Please review this one and reflection!
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }
   void TextFile::setEmpty()
   {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }
   void TextFile::setFilename(const char* fname, bool isCopy)
   {
       if (!isCopy)
       {
           m_filename = new char[strLen(fname) + 1];
           strCpy(m_filename, fname);

       }
       else
       {
           char temp[100] = "C_";
           m_filename = new char[strLen(fname) + strLen(temp) + 2];
           strCat(temp, fname);
           strCpy(m_filename, temp);
     
       }
   }
   void TextFile::setNoOfLines()
   {
       ifstream ifst;
       ifst.open(m_filename);
       while (ifst)
       {
           if (ifst.get() == '\n')
           {
               m_noOfLines++;
           }
       }
       if (m_noOfLines == 0)
       {
           delete[] m_filename;
           m_filename = nullptr;
       }
       m_noOfLines++;
       ifst.close();
   }
   void TextFile::loadText() 
   {
   
       if (m_filename != nullptr)
       {
           delete[] m_textLines;
           m_textLines = nullptr;
           m_textLines = new Line[m_noOfLines];
           int count{};
           string str{};
           ifstream ifst(m_filename);
           while (ifst)
           {
              if (getline(ifst, str))
              {
                  m_textLines[count] = str.c_str();
                  count++;
              }

           }
           m_noOfLines = count;
           ifst.close();
       }
       
   }
   void TextFile::saveAs(const char* fileName)const
   {
       ofstream ofs;
       ofs.open(fileName);
       for (unsigned int i = 0; i < m_noOfLines; i++)
       {
           ofs << m_textLines[i] << endl;
       }
       ofs.close();
   }
   TextFile::TextFile(unsigned pageSize)
   {
       m_pageSize = pageSize;
       m_filename = nullptr;
       m_noOfLines = 0;
       m_textLines = nullptr;
   }
   TextFile::TextFile(const char* filename, unsigned pageSize)
   {
       m_pageSize = pageSize;
       m_filename = nullptr;
       m_noOfLines = 0;
       m_textLines = nullptr; 

       if (filename != nullptr)
       {
           setFilename(filename);
           setNoOfLines();
           loadText();
       }
       
   }
   TextFile::TextFile(const TextFile& T)
   {
       m_pageSize = T.m_pageSize;
       m_filename = nullptr;
       m_textLines = nullptr;
       m_noOfLines = 0;

       if (T.m_filename != nullptr)
       {

           setFilename(T.name(), true);
           T.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
 
   }
   TextFile& TextFile::operator=(const TextFile& T)
   {
       if (T && *this)
       {
           delete[] m_textLines;
           m_textLines = nullptr;
           T.saveAs(m_filename);
           setNoOfLines();
           loadText();

       }
       return *this;
   }
   TextFile::~TextFile()
   {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;

   }
   std::ostream& TextFile::view(std::ostream& ostr)const
   {
       if (m_filename != nullptr)
       {
           ostr << m_filename << endl;
           for (int i = 0; i < strLen(m_filename); i++)
           {
               cout << "=";
           }
           cout << endl;

           char ch{};
           unsigned int i = 0;
           for (i = 0; i < m_noOfLines; i++)
           {
               ostr << m_textLines[i].m_value << endl;
               if ((i+1) % m_pageSize == 0)
               {
                   ostr << "Hit ENTER to continue...";
                   cin.ignore(1000, '\n');
                   cin.clear();
                   while (ch != '\n')
                   {
                       cin.get(ch);
                   }
                  
               }
               
           }
       }
      
       return ostr;
   }
   std::istream& TextFile::getFile(std::istream& istr)
   {
       char fname[30]{};
       istr >> fname;
      setFilename(fname);
       setNoOfLines();
       loadText();

       return istr;

   }
   TextFile::operator bool()const
   {
       return m_textLines != nullptr;
   }
   unsigned TextFile::lines()const
   {
       return m_noOfLines;
   }
   const char* TextFile::name()const
   {
       return m_filename;
   }
   const char* TextFile::operator[](unsigned index)const
   {
       return *this ? (const char*)m_textLines[index % m_noOfLines] : nullptr;
   }
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
   {
       return text.view(ostr);
   }
   std::istream& operator>>(std::istream& istr, TextFile& text)
   {
       return text.getFile(istr);
   }

}