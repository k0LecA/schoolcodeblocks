#include <iostream>
#include <fstream>

using namespace std;

int n=90;       //vasaros maksimalus dienu skaicius apitiksliai
int krit[90];   //duomenys

//duomenu skaitymas
void FileRead();

//rezultatu rasymas
void FileWrite();

//kiek milimetru krituliu iskrito is viso
int IsViso();

//kiek dienu nelijo
int Nelijo();

//vidutiniskai kiekviena lietinga diena iskrito krituliu
int KrituliuVidutiniskai();


int main()
{
    FileRead();
    FileWrite();
}

void FileRead()
{
    for(int i=0;i<n;i++)
    {
        krit[i]=0;
    }

    ifstream fd("duomenys.txt");
    fd>>n;
    for(int i=0;i<n;i++)
    {
        fd>>krit[i];
        cout<<krit[i]<<endl;
    }
    fd.close();
}

void FileWrite()
{
    ofstream fr("Rezultatai.txt");
    fr<<"Krituliai (lietus)"<<endl;
    fr<<"---------------------------"<<endl;
    fr<<"Diena       Krituliu kiekis (mm)"<<endl;
    fr<<"---------------------------"<<endl;
    for(int i=0;i<n;i++)
    {
    fr<<"   "<<i+1<<"             "<<krit[i]<<endl;
    }
    fr<<"---------------------------"<<endl;
    fr<<"Is viso iskrito krituliu (mm) : "<<IsViso()<<endl;
    fr<<"Nelijo (dienas) : "<<Nelijo()<<endl;
    fr<<"Vidutiniskai kiekviena lietinga diena iskrito krituliu (mm) : "<<KrituliuVidutiniskai();
    fr.close();
}

int IsViso()
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=krit[i];
    }
    return sum;
}

int Nelijo()
{
    int skaicius=0; //dienu skaicius
    for(int i=0;i<n;i++)
    {
        if(krit[i]==0)
            skaicius++;
    }
    return skaicius;
}

int KrituliuVidutiniskai()
{
    return IsViso()/(n-Nelijo());
}
