#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int arr[3];
    bool found=false;

    ifstream fd("duomenys.txt");
    fd>>arr[0]>>arr[1]>>arr[2];
    fd.close();

    ofstream fr("rezultatai.txt");

    for(int i=0;i<3;i++)
    {
        if(arr[i]%3==0)
        {
            found=true;
            fr<<arr[i];
            break;
        }
    }
    if(found==false)
        fr<<"nera";

    fr.close();
}
