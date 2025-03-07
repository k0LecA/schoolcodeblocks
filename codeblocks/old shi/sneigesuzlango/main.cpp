#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int k=0;
    int n=0;
    int s=0;
    int last=0;
    ifstream fd("duomenys.txt");
    fd>>k>>n;
    fd.close();
    last=k;
    s+=last;
    for(int i=1;i<n;i++)
    {
        last*=2;
        s+=last;
    }
    ofstream fr("rezultatai.txt");
    fr<<s;
    fr.close();
}
