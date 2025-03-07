#include <iostream>
#include <fstream>

using namespace std;

int n=100;
char batuTipas[100];
int batuDydis[100];

//failu skaitymo rasymo funkcijos
void Skaitymas();
void Rasymas();

//batu paieska
int IeskotiBatus(string variant);

//batu salinimas
void SalintiBatus();

int main()
{
    Skaitymas();
    Rasymas();
}

void Skaitymas()
{
    ifstream fd("duomenys.txt");
    fd>>n;
    for(int i=0;i<n;i++)
    {
        batuTipas[i]='.';
        batuDydis[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        fd>>batuTipas[i]>>batuDydis[i];
    }
    fd.close();
}

void Rasymas()
{
    int mykoloIndeksas=IeskotiBatus("mykolas");
    int marytesIndeksas=IeskotiBatus("maryte");

    ofstream fr("rezultatai.txt");
    fr<<"Batu sarasas"<<endl;
    fr<<"----------------"<<endl;
    fr<<" Tipas   Dydis"<<endl;
    fr<<"----------------"<<endl;
    for(int i=0;i<n;i++)
    {
    fr<<"   "<<batuTipas[i]<<"     "<<batuDydis[i]<<endl;
    }
    fr<<"----------------"<<endl;
    fr<<"Mykolo 43-io dydzio batu indeksas masyve "<<mykoloIndeksas<<endl;
    fr<<"Marytes 38-o dydzio batu indeksas masyve "<<marytesIndeksas<<endl;
    fr<<"Batu sarasas"<<endl;
    fr<<"----------------"<<endl;
    fr<<" Tipas   Dydis"<<endl;
    fr<<"----------------"<<endl;
    for(int i=0;i<n;i++)
    {
        if(i==mykoloIndeksas || i==marytesIndeksas)
        {
            cout<<"AA";
        }
        else
        {
            fr<<"   "<<batuTipas[i]<<"     "<<batuDydis[i]<<endl;
        }
    }
    fr<<"----------------"<<endl;
}

int IeskotiBatus(string variant)
{
    if(variant=="mykolas")
    {
        for(int i=0;i<n;i++)
        {
            if(batuDydis[i]==43 && batuTipas[i]=='v')
                return i;
        }
    }
    else if(variant=="maryte")
    {
        for(int i=0;i<n;i++)
        {
            if(batuDydis[i]==38 && batuTipas[i]=='m')
                return i;
        }
    }
    return 0;
}
