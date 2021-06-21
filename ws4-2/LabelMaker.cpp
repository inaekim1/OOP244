/* Workshop 4 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/21
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 

#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
using namespace std;
namespace sdds
{
        LabelMaker::LabelMaker(int noOfLabels)
        {
            m_noOfLabels = noOfLabels;
            labels = new Label[noOfLabels];
        }
        void LabelMaker::readLabels()
        {
            cout << "Enter " << m_noOfLabels << " labels:" << endl;
            for (int i = 0; i < m_noOfLabels; i++)
            {
                cout << "Enter label number " << i+1 << endl;
                cout << "> ";
                labels[i].readLabel();
            }
        }
        void LabelMaker::printLabels()
        {
            for (int i = 0; i < m_noOfLabels; i++)
            {
                if (i != m_noOfLabels-1)
                {
                    labels[i].printLabel();
                    cout << endl;
                }
                else
                {
                    labels[i].printLabel() << endl;
                }
 
            }

        }
        LabelMaker::~LabelMaker()
        {
           
            
                delete[] labels;
            
            
        }
        

}