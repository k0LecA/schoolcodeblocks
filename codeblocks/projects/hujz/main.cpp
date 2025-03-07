#include <iostream>

using namespace std;

int main()
{
    int m,n;
    cout<<"nuo: ";
    cin>>m;
    cout<<"iki: ";
    cin>>n;
    for(int i=m;i<n;i++)
    {
        if(i%100==0)
        {
            if(i%400==0)
            {
                cout<<i<<endl;
            }
        }
        else
        {
            if(i%4==0)
            {
                cout<<i<<endl;
            }
        }
    }
}
