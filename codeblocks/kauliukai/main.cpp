#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    int n=0;
    int c=0;
    float s=0;

    ifstream fd("duomenys.txt");
    fd>>n;
    for(int i=0;i<n;i++)
    {
        fd>>c;
        s+=c;
    }
    fd.close();
    ofstream fr("rezultatai.txt");
    fr<<n*6<<endl;
    fr<<s<<endl;
    s/=n;
    fr<<s<<endl;
    if(s<3)
        fr<<"pralaimeta";
    else if(s>3)
        fr<<"laimeta";
    else
        fr<<"nieko";
    fr.close();
}
