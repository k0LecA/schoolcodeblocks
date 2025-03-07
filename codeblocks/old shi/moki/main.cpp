#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    float arr[4]={0};
    float maxA=0;

    ifstream fd("duomenys.txt");
    for(int i=0;i<4;i++)
    {
        fd>>arr[i];
        if(arr[i]>maxA)
            maxA=arr[i];
    }

    ofstream fr("rezultatai.txt");
    fr<<maxA<<endl;
    for(int i=0;i<4;i++)
    {
        if((maxA-arr[i])>0)
            fr<<maxA-arr[i]<<" ";
    }
}
