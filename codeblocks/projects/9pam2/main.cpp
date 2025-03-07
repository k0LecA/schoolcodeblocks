#include <iostream>

using namespace std;


int pirmasVariantas(int a,int b,int x)
{
    int y = a*(x*x)+b;
    return y;
}
int antrasVariantas(int a,int b,int x)
{
    int y =a*x+b*b;
    return y;
}

int main()
{
    int a, b, x,y, eil;
    cout<<"ivesk a:";
    cin>>a;
    cout<<"ivesk b:";
    cin>>b;
    cout<<"ivesk x:";
    cin>>x;
    cout<<"ivesk eiles numeri:";
    cin>>eil;

    if(eil%2!=0)
    {
        y = pirmasVariantas(a,b,x);
        cout<<"y="<<y;
    }
    else
    {
        y = antrasVariantas(a,b,x);
        cout<<"y="<<y;
    }
}
