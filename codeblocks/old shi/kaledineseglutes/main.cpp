#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n=0;
    float c=0;
    cout<<"kiek egluciu atvezta: ";
    cin>>n;
    int e[n];
    for(int i=0;i<n;i++)
    {
        cout<<"iveskite "<<i+1<<" eglutes auksti: ";
        cin>>e[i];
        c+=e[i];
    }
    c/=n;
    cout<<endl<<endl<<"auskcio vidurkis: "<<c<<" cm";

}
