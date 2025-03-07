#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;

    int v,d,t;
    //pirmas
    if(a<b && a<c)
    {
        v=a;
    }
    if(b<a && b<c)
    {
        v=b;
    }
    if(c<b && c<a)
    {
        v=c;
    }
    //trecias
    if(a>b && a>c)
    {
        t=a;
    }
    if(b>a && b>c)
    {
        t=b;
    }
    if(c>b && c>a)
    {
        t=c;
    }
    //atnras
    if(a>b && a<c || a<b && a>c)
    {
        d=a;
    }
    if(b>a && b<c || b<a && b>c)
    {
        d=b;
    }
    if(c>b && c<a || c<b && c>a)
    {
        d=c;
    }
    cout<<" "<<v<<" "<<d<<" "<<t;
}
