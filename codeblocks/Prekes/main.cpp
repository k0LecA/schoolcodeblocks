#include <iostream>
#include <fstream>

using namespace std;

int n=50;
int kainos[50];
int balance=0;

//failu skaitymo rasymo funkcijos
void Skaitymas();
void Rasymas();

int main()
{
    Skaitymas();
    Rasymas();
}

void Skaitymas()
{
    for(int i=0;i<n;i++)
    {
        kainos[i]=0;
    }

    ifstream fd("duomenys.txt");
    fd>>balance;
    fd>>n;
    for(int i=0;i<n;i++)
    {
        while(!fd.eol)
        {

        }
    }
}

void Rasymas()
{

}
