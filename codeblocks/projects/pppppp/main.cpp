#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Ivesk mokiniu skaiciu: ";
    cin>>n;
    int u[n];

    cout<<"ivesk ju ugius: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>u[i];
    }

    float vid;
    for(int i=0;i<n;i++)
    {
        vid+=u[i];
    }

    vid=vid/n;
    cout<<"vidutinis ugis: "<<vid;
}
