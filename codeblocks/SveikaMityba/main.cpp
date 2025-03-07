#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Produktai{
    string produktas;
    string parduotuve;
    float kaina;
};

string prodArr[8];
int nProd=0;

string pardArr[5];
int nPard=5;

int mazKainaArr[5][8];

void FailoSkaitymas(Produktai* prod, int& pinigai);

void FailoRasymas(Produktai* prod);

float Suma(Produktai* prod); //maziausiai kainuojaciu prekiu kainu suma

int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            mazKainaArr[i][j]=0;
        }
    }
    //cout<<(8%8)<<endl<<endl;
    for(int i=0;i<nProd;i++)
    {
        prodArr[i]=" ";
    }
    for(int i=0;i<nPard;i++)
    {
        pardArr[i]=" ";
    }

    int pinigai=0;

    Produktai prod[100];
    FailoSkaitymas(prod,pinigai);
    //cout<<endl<<nPard<<" "<<nProd<<" "<<nProd<<endl;
    //cout<<"    "<<((nPard*nProd)+nProd)-2<<"    ";

    for(int i=0;i<nPard;i++)
    {
        cout<<pardArr[i]<<" ";
    }

    cout<<endl<<endl;

    for(int i=0;i<nProd*nPard;i++)
    {
        //cout<<prod[i].kaina<<" "<<prod[i].parduotuve<<" "<<prod[i].produktas<<endl;
    }
    float sum=Suma(prod);

    cout<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<mazKainaArr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<pardArr[0]<<endl;
    FailoRasymas(prod);
}

void FailoSkaitymas(Produktai* prod, int& pinigai)
{
    string pardPavadinimas;
    int count=0;

    ifstream fd("U1.txt");
    fd>>nProd;
    fd>>pinigai;
    for(int i=0;i<nProd;i++)
    {
        fd>>prodArr[i];
    }
    string input="0";
    for(int i=0;i<nProd*nPard+nPard;i++)
    {
        //string input="0";
        //float inputf;
        if(i==0 || (i%nProd)==0)
        {
            //cout<<"a";
            fd>>input;
            //cout<<input;
            //cout<<pardPavadinimas;
            pardArr[i/nProd]=input;
            //cout<<i<<endl;
            //cout<<"   "<<(i/7)<<endl;
            //cout<<input<<endl;
        }
        float inputf=0;
        fd>>inputf;
        //cout<<inputf<<endl;
        prod[i].kaina=inputf;
        prod[i].parduotuve=input;
        prod[i].produktas=prodArr[i%nProd];
        count++;
    }
}

float Suma(Produktai* prod)
{
    float sum=0;
    for(int i=0;i<nProd;i++)
    {
        float maz=100;
        for(int j=0;j<nPard;j++)
        {
            if(prod[j*nProd+i].kaina==0)
            {

            }
            else
            {
                if(prod[j*nProd+i].kaina<maz)
                    maz=prod[j*7+i].kaina;
                //cout<<prod[j*7+i].kaina<<endl;
            }
        }
        //cout<<endl;
        sum+=maz;
        for(int j=0;j<nPard;j++)
        {
            if(prod[j*nProd+i].kaina==maz)
            {
                mazKainaArr[j][i]=1;
            }
        }
    }
    //cout<<sum;
    return sum;
}

void FailoRasymas(Produktai* prod)
{
    ofstream fr("rezultatai.txt");
    fr<<endl;
    fr<<Suma(prod)<<endl;
    for(int i=0;i<nPard;i++)
    {
        int cc=0;
        for(int j=0;j<nProd;j++)
        {
            cc+=mazKainaArr[i][j];
        }
        if(cc>0)
        {
            fr<<pardArr[i]<<i<<"   ";
            for(int j=0;j<nProd;j++)
            {
                if(mazKainaArr[i][j]==1)
                {
                    fr<<prodArr[j]<<"   ";
                }
            }
            fr<<endl;
        }
    }
    fr.close();
}
