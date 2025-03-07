#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int x=0;
    int v=0;
    int k=0;
    ifstream fd("duomenys.txt");
    fd>>x>>v;
    fd.close();
    while(x>0)
    {
        x-=(v+1)*3;
        if(x>0)
            k++;
    }
    ofstream fr("rezultatai.txt");
    fr<<k<<endl;
    if(k>92)
        fr<<"uzteks";
    else
        fr<<"neuzteks";
    fr.close();
}
