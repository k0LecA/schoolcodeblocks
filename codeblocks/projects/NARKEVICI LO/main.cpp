#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;

    double d;
    d=b*b-(4*a*c);
    cout<<d<<endl;
    if(d<0)
    {
        cout<<"Sprendiniu nera";
    }
    else if(d==0)
    {
        double x;
        x= -b/(2*a);
        cout<<x;
    }
    else
    {
        double x1,x2;
        x1= (-b-sqrt(d))/(2*a);
        x2= (-b+sqrt(d))/(2*a);
        cout<<x1<<"   "<<x2;
    }
}
