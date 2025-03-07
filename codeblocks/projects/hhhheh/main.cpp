#include <iostream>

using namespace std;

int main()
{
    int n,k;
    int s=0;
    cout<<"eiles: ";
    cin>>n;
    cout<<"kedes pirmoje eileje: ";
    cin>>k;
    for(int i=0;i<n;i++)
    {
        s+=k;
        k+=2;
    }
    cout<<"s= "<<s;
}
