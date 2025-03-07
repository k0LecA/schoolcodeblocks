#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int m, s;

    cout<<"virves ilgis: ";
    cin>>m;

    if(m%4<2)
    {
        int krastine = m/4;
        s=krastine*krastine;
    }
    else
    {
        int krastine = m/4;
        s=krastine * (krastine+1);
    }

    cout<<"s="<<s;

}
