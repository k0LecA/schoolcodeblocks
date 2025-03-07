#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

int n=50;
int k=50;
int duomenys[50][50]; //skaitymo duomenys
int rezultatai[50][50]; //rezultatai

//duomenu skaitymas
void FileRead();

//rezultatu rasymas
void FileWrite();

//garso signalo islyginimas
void SignaloLyginimas();

int main()
{
    FileRead();
    SignaloLyginimas();
    FileWrite();
}

void FileRead()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            duomenys[i][j]=0;
            rezultatai[i][j]=0;
        }
    }

    ifstream fd("duomenys.txt");
    fd>>n>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            fd>>duomenys[i][j];
        }
    }
    fd.close();
}

void FileWrite()
{
    ofstream fr("rezultatai.txt");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            fr<<rezultatai[i][j]<<" ";
        }
        fr<<endl;
    }
    fr.close();
}

void SignaloLyginimas()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(j==0)
                rezultatai[i][j]=(duomenys[i][j]+duomenys[i][j+1])/2;
            else if(j==(k-1))
                rezultatai[i][j]=(duomenys[i][j]+duomenys[i][j-1])/2;
            else
                rezultatai[i][j]=(duomenys[i][j]+duomenys[i][j-1]+duomenys[i][j+1])/3;
        }
    }
}
