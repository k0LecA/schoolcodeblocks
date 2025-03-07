#include <iostream>
#include <fstream>

using namespace std;

struct Students{
    string name;
    float height;
    int points;
};

int GautiElementuSkaiciu();

void FailoSkaitymas(int n,Students* stud, int& p, int& k);

int MaxHeight(int n,Students* stud);

int MaxPoints(int n,Students* stud);

void FailoRasymas(int n,Students* stud, int p,int k, int mh, int mp);

int main()
{
    int n=0;
    int p=0;
    int k=0;

    int maxHeight=0;
    int maxPoints=0;

    n=GautiElementuSkaiciu();
    Students stud[100];
    FailoSkaitymas(n,stud,p,k);

    maxHeight=MaxHeight(n, stud);
    maxPoints=MaxPoints(n, stud);
    FailoRasymas(n,stud,p,k,maxHeight,maxPoints);
}

int GautiElementuSkaiciu()
{
    int n;
    ifstream fd("duomenys.txt");
    fd>>n;
    return n;
    fd.close();
}

void FailoSkaitymas(int n,Students* stud, int& p, int& k)
{
    int c;
    ifstream fd("duomenys.txt");
    fd>>c;
    for(int i=0;i<n;i++)
    {
        fd>>stud[i].name;
        fd>>stud[i].height;
        fd>>stud[i].points;
    }
    fd>>p>>k;
    fd.close();
}

int MaxHeight(int n,Students* stud)
{
    int maxHeight=0;
    for(int i=0;i<n;i++)
    {
        if(stud[i].height>maxHeight)
            maxHeight=stud[i].height;
    }
    return maxHeight;
}

int MaxPoints(int n,Students* stud)
{
    int maxPoints=0;
    for(int i=0;i<n;i++)
    {
        if(stud[i].points>maxPoints)
            maxPoints=stud[i].points;
    }
    return maxPoints;
}

void FailoRasymas(int n,Students* stud, int p,int k, int mh, int mp)
{
    float tinkamasUgis=(mh/100)*(100-p);
    float _k=k;
    float _mp=mp;

    float tinkamasTaskuSkaicius=(100-_k)*(_mp/100);

    //cout<<_k<<endl;
    //cout<<_mp<<endl;
    //cout<<tinkamasTaskuSkaicius;


    ofstream fr("rezultatai.txt");
    fr<<"------------------------------"<<endl;
    fr<<"Vardas         Ugis     Taskai"<<endl;
    fr<<"------------------------------"<<endl;
    for(int i=0;i<n;i++)
    {
        //cout<<"a";
        if(stud[i].height>=tinkamasUgis || stud[i].points>=tinkamasTaskuSkaicius)
        {
            fr<<stud[i].name<<"         "<<stud[i].height<<"    "<<stud[i].points<<endl;
        }
    }
    fr<<"------------------------------"<<endl;
    fr.close();
    //cout<<"fin"<<endl;
}
