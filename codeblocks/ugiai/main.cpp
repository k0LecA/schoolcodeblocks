#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

int n=30;         //mokiniu maksimalus kiekis remiantis uzduotimi
int duomenys[30]; //duomenys
int bernai[30];
int mergos[30];

//duomenu skaitymas
void FileRead();

//rezultatu rasymas
void FileWrite();

//klases ugio vidurkis
float KlasesUgioVidurkis();

float MerginuVidutinisUgis();

float VaikinuVidutinisUgis();

string MerginuKomanda();

string VaikinuKomanda();

int main()
{
    FileRead();
    FileWrite();
}

void FileRead()
{
    for(int i=0;i<n;i++)
    {
        duomenys[i]=0;
    }

    ifstream fd("duomenys.txt");
    fd>>n;
    for(int i=0;i<n;i++)
    {
        fd>>duomenys[i];
        //cout<<duomenys[i]<<endl;
    }
    fd.close();
}

void FileWrite()
{
    ofstream fr("rezultatai.txt");
    fr<<fixed<<setprecision(1)<<KlasesUgioVidurkis()<<endl;
    fr<<fixed<<setprecision(2)<<MerginuVidutinisUgis()<<endl;
    fr<<fixed<<setprecision(2)<<VaikinuVidutinisUgis()<<endl;
    fr<<MerginuKomanda()<<endl;
    fr<<VaikinuKomanda()<<endl;
    fr.close();
}

float KlasesUgioVidurkis()
{
    float sum=0; //suma
    for(int i=0;i<n;i++)
    {
        if(duomenys[i]<0)
            sum+=abs(duomenys[i]);
        else
            sum+=duomenys[i];

    }
    float ave=(sum/n);
    //ave=1.5;
    //cout<<sum<<" "<<n<<endl;
    cout<<fixed<<setprecision(1)<<ave;
    return ave;
}

float MerginuVidutinisUgis()
{
    float sum=0; //suma
    int merginuSkaicius=0;
    for(int i=0;i<n;i++)
    {
        if(duomenys[i]>0)
        {
            sum+=duomenys[i];
            merginuSkaicius++;
        }
    }
    float vidurkis=sum/merginuSkaicius;
    return vidurkis;
}

float VaikinuVidutinisUgis()
{
    float sum=0; //suma
    int vaikinuSkaicius=0;
    for(int i=0;i<n;i++)
    {
        if(duomenys[i]<0)
        {
            sum+=duomenys[i];
            vaikinuSkaicius++;
        }
    }
    float vidurkis=abs(sum/vaikinuSkaicius);
    return vidurkis;
}

string MerginuKomanda()
{
    int kiekis=0;
    for(int i=0;i<n;i++)
    {
        if(duomenys[i]>0)
        {
            if(duomenys[i]>=175)
            {
                kiekis++;
            }
        }

    }
    if(kiekis>=7)
        return "Merginu komanda sudaryti galima";
    else
        return "Merginu komandos sudaryti negalima";
}

string VaikinuKomanda()
{
    int kiekis=0;
    for(int i=0;i<n;i++)
    {
        if(duomenys[i]<0)
        {
            if(duomenys[1]<=-175)
                kiekis++;
        }

    }
    if(kiekis>=7)
        return "Vaikinu komanda sudaryti galima";
    else
        return "Vaikinu komandos sudaryti negalima";
}
