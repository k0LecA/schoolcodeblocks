#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    int arr[3]={0};
    int didz=0;
    int maz=10000;

    cout<<"kiek pauksciu: ";
    for(int i=0;i<3;i++)
    {
        cin>>arr[i];
        if(arr[i]>didz)
            didz=arr[i];
        if(arr[i]<maz)
            maz=arr[i];
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3-i-1;j++)
        {
              if(arr[j]<arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }

    ofstream fr("rezultatai.txt");
    for(int i=0;i<3;i++)
    {
        fr<<arr[i]<<endl;
    }
    fr<<"skirtums: "<<didz-maz;
}
