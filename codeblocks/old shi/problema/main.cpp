#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int var=0;
    int a=0;
    int b=0;
    int x=0;

    ifstream fd("duomenys.txt");
    fd>>var>>a>>b;
    fd.close();

    if(var==1)
        x=a*b+3;
    if(var==2)
        x=a+b;
    if(var==3)
        x=a-b;

    ofstream fr("rezultatai.txt");
    fr<<"x="<<x;
    fr.close();
}
