#include <iostream>

using namespace std;

int main()
{
    // 1 uzduotis
    int k, v;
    cout<<"ivesk zibuokliu kieki kiskiu miske: ";
    cin>>k;
    cout<<"ivesk zibuokliu kieki vilku miske: ";
    cin>>v;
    if(k>v)
        cout<<"Pas vilkus maziau";
    else
        cout<<"Pas kiskius maziau";
}
