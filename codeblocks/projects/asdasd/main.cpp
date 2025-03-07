#include <iostream>

using namespace std;

int main()
{
    int k, n, ek;
    cout<<"Vidutine vieno kilogramo grybu kaina: ";
    cin>>k;
    cout<<"Kiek kg pardave: ";
    cin>>n;
    cout<<"Kokia ekskursijos kaina: ";
    cin>>ek;
    if((k*n)>ek)
    {
        cout<<"uzteks ir liks "<<(k*n)-ek;
    }
    else{
        cout<<"ne uzteks, pritruko "<<ek-(k*n);
    }

}
