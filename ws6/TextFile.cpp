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
           char str[] =  "C_";
           m_filename = new char[strLen(fname) + 1];
           strCpy(m_filename, fname);
           strCat(str, m_filename);
       }
   }
   void TextFile::setNoOfLines()
   {
       m_noOfLines = 1;
       ifstream ifst;
       ifst.open(m_filename);
       while (ifst)
       {
           if (ifst.get() == '\n')
           {
               m_noOfLines++;
           }
       }
       ifst.close();
   }
   void TextFile::loadText() // error
   {
           delete[] m_textLines;

       if (m_filename != nullptr)
       {
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
       }
       
   }
   void TextFile::saveAs(const char* fileName)const
   {
       ofstream ofs;
       ofs.open(fileName);
       for (unsigned int i = 0; i < m_noOfLines; i++)
       {
           ofs << m_textLines[i].m_value;
       }
       ofs.close();
   }
   TextFile::TextFile(unsigned pageSize)
   {
       setEmpty();
       m_pageSize = pageSize;
   }
   TextFile::TextFile(const char* filename, unsigned pageSize)
   {
       setEmpty();
       m_pageSize = pageSize;
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
       m_noOfLines = 0;
       m_pageSize = 0;
      
       if (T)
       {
           setFilename(T.name());
           T.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
 
   }
   TextFile& TextFile::operator=(const TextFile& T)
   {
       if (T && *this)
       {
           delete[] m_textLines; // array of text?
           delete[] this->m_filename;
           this->m_filename = nullptr;
           T.saveAs(m_filename);
           setNoOfLines();
           loadText();

       }
       return *this;
   }
   TextFile::~TextFile()
   {
       delete[] m_filename;
       delete[] m_textLines;

   }
   std::ostream& TextFile::view(std::ostream& ostr)const
   {
       ostr.width(strLen(m_filename));
       ostr << m_filename << endl;
       ostr.fill('=');
       unsigned int i = 0;
       for ( i = 0; i < m_noOfLines; i++)
       {
           ostr << m_textLines[i].m_value << endl;
       }
       return ostr;
   }
   std::istream& TextFile::getFile(std::istream& istr)
   {
       char fname[100]{};
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
       char* s{};
       if (m_textLines[index] == NULL)
       {
           s = nullptr;
       }
       else if (index > m_noOfLines)
       {
           index = index % m_noOfLines;
           s = m_textLines[index].m_value;
       }
       return s;
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