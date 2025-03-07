#include <iostream>

using namespace std;

int main()
{
    int b,s,n;

    cout<<"kiek litru benzino ipilta: ";
    cin>>b;

    cout<<"kiek turi nuvaziuoti km: ";
    cin>>s;

    cout<<"kiek per 100km litru sunaudoja: ";
    cin>>n;


    if((100/n)*b>s)
    {
        cout<<"uzteks ir liks "<<(100/n)*b-s<<" litru";
    }
    else if((100/n)*b<s)
    {
        cout<<"neuzteks, pritruks "<<s-(100/n)*b<<" litru";
    }
    else if((100/n)*b==s)
    {
        cout<<"visko uztenka nieko netruksta nieko nelieka";
    }
}
