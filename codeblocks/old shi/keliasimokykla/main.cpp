#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int steps=0;
    int penk=0;
    int desim=0;
    ifstream fd("duomenys.txt");
    fd>>steps;
    fd.close();
    for(int i=1;i<=steps;i++)
    {
        if(i%5==0 && i%10!=0)
            penk++;
        if(i%10==0)
            desim++;
    }
    ofstream fr("rezultatai.txt");
    fr<<"suplojimu: "<<desim<<endl;
    fr<<"spragtelejimu: "<<penk<<endl;
    fr.close();
}
