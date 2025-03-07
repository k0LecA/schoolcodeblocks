#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int n1=1;
    int n2=1;
    int n3=1;
    int next;
    bool cont=true;

    while(cont)
    {
        if(n>next)
        {
            next=n1+n2+n3;
            n1=n2;
            n2=n3;
            n3=next;
        }
        else
        {
            cont=false;
        }
    }
    cout<<next;
}
