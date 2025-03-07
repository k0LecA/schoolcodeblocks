#include <iostream>

using namespace std;

int main()
{
    float g, m, n;
    cout<<"1000 grudu mase: ";
    cin>>g;
    cout<<"kiek metu: ";
    cin>>m;
    cout<<"kiek kg grudu gali skirti: ";
    cin>>n;

    int kggs= n*1000*g;//kiek grudu gali skirti - kggs

    if((kggs*2)>m*(365.25))
        cout<<"vesti apsimoka";
    else
        cout<<"vesti neapsimoka";
}
