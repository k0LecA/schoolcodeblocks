#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

int m=100;         //
int n=0;         //
float x[100]; //duomenys
float y[100]; //duomenys


//duomenu skaitymas
void FileRead();

//rezultatu rasymas
void FileWrite();

float MaziausiasGreitis();
float VidutinisGreitis();
float DidziausiasGreitis();

float Nukeliautas();

int main()
{
    FileRead();
    FileWrite();
}

void FileRead()
{
    for(int i=0;i<m;i++)
    {
        x[i]=0;
        y[i]=0;
    }

    ifstream fd("duomenys.txt");
    fd>>m>>n;
    for(int i=0;i<m;i++)
    {
        fd>>x[i]>>y[i];
        //cout<<duomenys[i]<<endl;
    }
    fd.close();
}

void FileWrite()
{
    ofstream fr("rezultatai.txt");
    fr<<"Maziausias greitis: "<<fixed<<setprecision(2)<<MaziausiasGreitis()<<" mm/s"<<endl;
    fr<<"Vidutinis greitis: "<<fixed<<setprecision(2)<<VidutinisGreitis()<<" mm/s"<<endl;
    fr<<"Maziausias greitis: "<<fixed<<setprecision(2)<<DidziausiasGreitis()<<" mm/s"<<endl;
    fr<<"Nukeliautas atstumas: "<<fixed<<setprecision(2)<<Nukeliautas()<<" mm"<<endl;
    fr.close();
}

float MaziausiasGreitis()
{
    float mini=50;
    float dist=0;
    float greitis=0;
    for(int i=1;i<m;i++)
    {
        dist=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
        greitis=dist/n;
        if(greitis<mini)
            mini=greitis;
    }
    return mini;
}

float VidutinisGreitis()
{
    float dist=0;
    float greitis=0;
    float countt=0;
    for(int i=1;i<m;i++)
    {
        dist=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
        greitis+=dist/n;
        countt++;
    }
    return greitis/countt;
}

float DidziausiasGreitis()
{
    float maksi=0;
    float dist=0;
    float greitis=0;
    for(int i=1;i<m;i++)
    {
        dist=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
        greitis=dist/n;
        if(greitis>maksi)
            maksi=greitis;
    }
    return maksi;
}

float Nukeliautas()
{
    float dist=0;
    for(int i=1;i<m;i++)
    {
        dist+=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
    }
    return dist;
}
