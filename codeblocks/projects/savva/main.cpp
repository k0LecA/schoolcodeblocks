#include <iostream>

using namespace std;

int main()
{
    int s, k, n, t, m;
    cout<<"pajamos vienam seimos nariui: ";
    cin>>s;
    cout<<"kiek lieka litu: ";
    cin>>k;
    cout<<"kiek asmenu sudaro seima: ";
    cin>>n;
    cout<<"tevo atlyginimas: ";
    cin>>t;
    cout<<"motinos atlyginimas: ";
    cin>>m;

    int lik = (t+m)-(n*s);
    if(lik>k)
    {
        cout<<"Bankas suteiks paskola";
    }
    else
    {
        cout<<"Bankas nesuteiks paskolos";
    }
}
