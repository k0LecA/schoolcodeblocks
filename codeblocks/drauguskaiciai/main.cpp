#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n=0;
    int c=0;
    int s=0;
    ifstream fd("duomenys.txt");
    fd>>n;
    for(int i=0;i<n;i++)
    {
        fd>>c;
        if(c%2==0)
            s++;
    }
    fd.close();
    ofstream fr("rezultatai.txt");
    fr<<s;
    fr.close();
}
