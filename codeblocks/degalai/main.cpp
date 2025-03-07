#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int t=0;
    int n=0;
    int c=1;
    ifstream fd("duomenys.txt");
    fd>>t>>n;
    fd.close();
    cout<<t<<" "<<n<<endl;
    while(t>0)
    {
        if(c%2==0)
            t-=n;
        else
            t-=2*n;
        c++;
        cout<<t<<" "<<c<<endl;
    }
    ofstream fr("rezultatai.txt");
    c--;
    fr<<c;
    fr.close();
}
