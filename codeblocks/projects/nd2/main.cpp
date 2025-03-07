#include <iostream>

using namespace std;

int main()
{
    float s,c,v;

    //cout<<"antra uzduotis"<<endl;
    cout<<"kiek laiko bega tarakonas: ";
    cin>>s;
    cout<<"kiek cm nubega tarakonas: ";
    cin>>c;
    cout<<"koks muses greitis (m/s): ";
    cin>>v;

    if(((c/100)/s)>v)
        cout<<"Tarakonas greitesnis";
    else
        cout<<"Muse greitesne";
}
