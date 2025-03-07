#include <iostream>
#include <fstream>

using namespace std;

void FailoSkaitymas(int* arr1,int* arr2, int size1, int size2);

int GetArraySize(int choice);

void Algorithm(int* arr1,int* arr2, int size1, int size2, int* newArr, int& temp);

void FailoRasymas(int* arr,int size);


int main()
{
    int sizeA=GetArraySize(1);
    int sizeB=GetArraySize(2);
    int A[sizeA]={0};
    int B[sizeB]={0};
    FailoSkaitymas(A,B,sizeA,sizeB);
    int newA[1000]={0};
    int temp=0;
    Algorithm(A,B,sizeA,sizeB,newA,temp);
    //cout<<"a";
    //for(int i=0;i<sizeA+sizeB;i++)
    //{
    //    cout<<newA[i]<<" ";
    //}
    FailoRasymas(newA,temp);
}

int GetArraySize(int choice)
{
    int size=0;
    int temp=0;
    if(choice==1)
    {
        ifstream fd("duomenys.txt");
        fd>>size;
        fd.close();
    }
    else if(choice==2)
    {
        ifstream fd("duomenys.txt");
        fd>>size;
        for(int i=0;i<size;i++)
        {
            fd>>temp;
        }
        fd>>size;
        fd.close();
    }
    return size;
}

void FailoSkaitymas(int* arr1,int* arr2, int size1, int size2)
{
    int n=0;
    ifstream fd("duomenys.txt");
    fd>>n;
    for(int i=0;i<n;i++)
    {
        fd>>arr1[i];
    }
    fd>>n;
    for(int i=0;i<n;i++)
    {
        fd>>arr2[i];
    }
}

void Algorithm(int* arr1,int* arr2, int size1, int size2, int* newArr, int& temp)
{
    temp=0;
    int temp2=0;
    /*for(int i=0;i<8;i++)
    {
        newArr[i]=arr1[i];
        cout<<newArr[i]<<"       "<<i<<endl;
        temp2=0;
        for(int j=0;j<size2;j++)
        {
            cout<<arr2[j]<<"                  "<<j<<endl;
            if((arr2[j]%newArr[i])==0)
            {
                temp2++;
                newArr[i+temp2+j]=arr2[j];
            }

        }
        temp++;
        i=i+temp+temp2;
    }*/
    for(int i=0;i<size1;i++)
    {
        newArr[temp]=arr1[i];
        temp2=0;
        for(int j=0;j<size2;j++)
        {
            if((arr2[j]%newArr[temp])==0)
            {
                cout<<arr2[j]<<" % "<<newArr[temp]<<" = "<<(arr2[j]%newArr[temp])<<endl;
                //cout<<arr2[j]<<endl<<endl;
                temp2++;
                newArr[temp+temp2]=arr2[j];
            }
        }
        temp+=temp2+1;
    }

    for(int i=0;i<temp;i++)
    {
        cout<<newArr[i]<<" ";
    }
}

void FailoRasymas(int* arr, int size)
{
    ofstream fr("rezultatai.txt");
    for(int i=0; i<size;i++)
    {
        fr<<arr[i]<<" ";
    }
    fr.close();
}
