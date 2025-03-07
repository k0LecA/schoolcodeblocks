#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int n=500;          //namu maksimalus kiekis remiantis uzduotimi
int duomenys[500][2]; //duomenys

//duomenu skaitymas
void FileRead();

//rezultatu rasymas
void FileWrite();

//kiek is viso yra gyventoju
int IsvisoGyventoju();

//kiek gyventoju yra kaireje pusuje
int GyventojuKairejePuseje();

//kiek gyventoju yra desineje puseje
int GyventojuDesinejePuseje();

//kiek vidutiniskai gyvena gyventoju kiekviename name kaireje puseje
float VidutiniskaiKairejePuseje();

//kiek vidutiniskai gyvena gyventoju kiekviename name desineje puseje
float VidutiniskaiDesinejePuseje();

int main()
{
    FileRead();
    FileWrite();
}

void FileRead()
{
    for(int i=0;i<n;i++)
    {
        duomenys[i][0]=0;
        duomenys[i][1]=0;
    }

    ifstream fd("duomenys.txt");
    fd>>n;
    for(int i=0;i<n;i++)
    {
        fd>>duomenys[i][0]>>duomenys[i][1];
        cout<<duomenys[i][0]<<" "<<duomenys[i][1]<<endl;
    }
    fd.close();
}

void FileWrite()
{
    ofstream fr("rezultatai.txt");
    fr<<IsvisoGyventoju()<<endl;
    fr<<GyventojuKairejePuseje()<<endl;
    fr<<GyventojuDesinejePuseje()<<endl;
    fr<<setprecision(2)<<VidutiniskaiKairejePuseje()<<endl;
    fr<<setprecision(2)<<VidutiniskaiDesinejePuseje()<<endl;
    fr.close();
}

int IsvisoGyventoju()
{
    int sum=0;
    cout<<"a";
    for(int i=0;i<n;i++)
    {

        sum+=duomenys[i][1];
    }
    return sum;
}

int GyventojuKairejePuseje()
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if((duomenys[i][0]%2)>0)
            sum+=duomenys[i][1];
    }
    return sum;
}

int GyventojuDesinejePuseje()
{
    int ats=0;
    int isviso=IsvisoGyventoju();
    int kaireje=GyventojuKairejePuseje();
    ats=isviso-kaireje;
    return ats;
}

float VidutiniskaiKairejePuseje()
{
    float average=0; //vidurkis
    int namuSkaicius=0;
    for(int i=0;i<n;i++)
    {
        if((duomenys[i][0]%2)>0)
            namuSkaicius++;
    }
    int kaireje=GyventojuKairejePuseje();
    average=kaireje/namuSkaicius;
    return average;
}

float VidutiniskaiDesinejePuseje()
{
    float average=0; //vidurkis
    int namuSkaicius=0;
    for(int i=0;i<n;i++)
    {
        if((duomenys[i][0]%2)==0)
            namuSkaicius++;
    }
    int desineje=GyventojuDesinejePuseje();
    average=desineje/namuSkaicius;
    return average;
}
