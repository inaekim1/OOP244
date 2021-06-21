/* Workshop 4 part 2
Name : Inae Kim
Seneca ID : 132329202
Seneca email : ikim36@myseneca.ca
Date : 2021/06/21
Section : OOP244 NBB

*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 

#ifndef SDDS_LABELMAKER_H_
#define SDDS_LABELMAKER_H_
namespace sdds
{
    class LabelMaker
    {
        int m_noOfLabels;
        Label* labels;
public:
    LabelMaker(int noOfLabels);
    void readLabels();
    void printLabels();
    ~LabelMaker();
};

}
#endif