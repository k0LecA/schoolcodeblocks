#include <iostream>

using namespace std;

int main()
{
    cout<<"ivesk x: ";
    int x, y;
    cin>>x;

    if(x<-1)
    {
        y=5+x;
    }
    if(x==-1)
    {
        y=4;
    }
    if(x>-1)
    {
        y=x+1;
    }
    cout<<"y="<<y;
}
