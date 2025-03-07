#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a=0;
    int b=0;
    int sum=0;
    ifstream fd("duomenys.txt");
    fd>>a>>b;
    fd.close();
    for(int i=a;i<=b;i++)
    {
        if(i%6==0)
            sum++;
    }
    ofstream fr("rezultatai.txt");
    fr<<sum;
    fr.close();
}
