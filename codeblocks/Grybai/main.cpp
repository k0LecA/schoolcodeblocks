#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

int n=100;         //mokiniu maksimalus kiekis remiantis uzduotimi
int data[100][2];  //data nieko idomaus 0-menesis   1-diena

//duomenys
//indeksas:     0           1               2
//           |      |               |
//           | mase | baravyku kiek | raudonvirsiu kiek
//           |      |               |
//
float duomenys[100][3];


//duomenu skaitymas
void FileRead();

//rezultatu rasymas
void FileWrite();

//derlingiausios dienos indeksas pagal kuri is masyvo veliau trauksim menesi ir diena
int DerlingiausiaDiena(int select);


int main()
{
    FileRead();
    FileWrite();
}

void FileRead()
{
    for(int i=0;i<n;i++)
    {
        data[i][0]=0;
        data[i][1]=0;
        duomenys[i][0]=0;
        duomenys[i][1]=0;
        duomenys[i][2]=0;
    }

    ifstream fd("duomenys.txt");
    fd>>n;
    for(int i=0;i<n;i++)
    {
        fd>>data[i][0]>>data[i][1]>>duomenys[i][0]>>duomenys[i][1]>>duomenys[i][2];
        //cout<<data[i][0]<<" "<<data[i][1]<<" "<<duomenys[i][0]<<" "<<duomenys[i][1]<<" "<<duomenys[i][2]<<endl;
    }
    fd.close();
}

void FileWrite()
{
    ofstream fr("rezultatai.txt");
    //kvieciant funkcija DerlingiausiaDiena irasome argumenta kuris nurodo pagal kokius duomenys isvedam data
    fr<<"Derlingiausia diena: "<<data[DerlingiausiaDiena(0)][0]<<" "<<data[DerlingiausiaDiena(0)][1]<<endl;
    fr<<"Derlingiausia baravyku diena: "<<data[DerlingiausiaDiena(1)][0]<<" "<<data[DerlingiausiaDiena(1)][1]<<endl;
    fr<<"Derlingiausia raudonvirsiu diena: "<<data[DerlingiausiaDiena(2)][0]<<" "<<data[DerlingiausiaDiena(2)][1];
    fr.close();
}

///int select pasirinkimas
//select=0 MASE
//select=1 BARAVYKU KIEKIS
//select=2 RAUDONVIRSIU KIEKIS
int DerlingiausiaDiena(int select)
{
    int maks=0;
    int indeks=0;
    for(int i=0;i<n;i++)
    {
        if(duomenys[i][select]>maks)
        {
            maks=duomenys[i][0];
            indeks=i;
        }
    }
    return indeks;
}

