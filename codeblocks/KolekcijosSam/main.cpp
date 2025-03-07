#include <iostream>
#include <fstream>

using namespace std;

int GetArraySize(int choice); //gauti masyvo didzius

void FailoSkaitymas(int choice, int* arr ,int size);

void FilterArrays(int* arr1, int* arr2, int size1, int size2); //atskirti dvizenklius ir trizenklius skaicius

void FailoRasymas(int* arr1, int* arr2, int size1, int size2);

void BubbleSort(int* arr, int size); //rikiavimas

int main()
{
    //gautus didzius issaugome
    int sizeRas=GetArraySize(1);
    int sizeRim=GetArraySize(2);

    //kolekciju masyvai
    int RasosKolekcija[sizeRas];
    int RimoKolekcija[sizeRim];

    //kolekciju duomenu skaitymas is failo
    FailoSkaitymas(1,RasosKolekcija,sizeRas);
    FailoSkaitymas(2,RimoKolekcija,sizeRim);

    //rusivimas ,rikiavimas ir rasymas i failus
    FilterArrays(RasosKolekcija,RimoKolekcija,sizeRas,sizeRim);
}

int GetArraySize(int choice)
{
    int size;
    if(choice==1)
    {
        ifstream fd("file1.txt");
        fd>>size;
        fd.close();
    }
    else if(choice==2)
    {
        ifstream fd("file2.txt");
        fd>>size;
        fd.close();
    }
    return size;
}

void FailoSkaitymas(int choice, int* arr,int size)
{
    int cache=0;
    if(choice==1)
    {
        ifstream fd("file1.txt");
        fd>>cache;
        for(int i=0;i<size;i++)
        {
            fd>>arr[i];
        }
        fd.close();
    }
    if(choice==2)
    {

        ifstream fd("file2.txt");
        fd>>cache;
        for(int i=0;i<size;i++)
        {
            fd>>arr[i];
        }
        fd.close();
    }

}

void FilterArrays(int* arr1, int* arr2, int size1, int size2)
{
    int count3=0;
    for(int i=0;i<size1;i++)
    {
        if(arr1[i]>99)
            count3++;
    }
    for(int i=0;i<size2;i++)
    {
        if(arr2[i]>99)
            count3++;
    }
    int count2=size1+size2-count3;
    //cout<<count2<<" "<<count3;

    int Rasos[count2];
    int Rimo[count3];
    int cc=0;
    for(int i=0;i<size1;i++)
    {
        //cout<<arr1[i]<<endl;
        if(arr1[i]<100)
        {
            Rasos[cc]=arr1[i];
            //cout<<Rasos[cc]<<endl;
            cc++;

        }
    }
    for(int i=0;i<size2;i++)
    {
        if(arr2[i]<100)
        {
            Rasos[cc]=arr2[i];
            cc++;
        }
    }

    cc=0;
    for(int i=0;i<size1;i++)
    {
        if(arr1[i]>99)
        {
            Rimo[cc]=arr1[i];
            cc++;
        }
    }
    for(int i=0;i<size2;i++)
    {
        if(arr2[i]>99)
        {
            Rimo[cc]=arr2[i];
            cc++;
        }
    }
    for(int i=0;i<count3;i++)
    {
        cout<<Rimo[i]<<endl;
    }
    BubbleSort(Rasos,count2);
    BubbleSort(Rimo,count3);
    FailoRasymas(Rasos,Rimo,count2,count3);
}

void FailoRasymas(int* arr1, int* arr2, int size1, int size2)
{
    ofstream fr("rezultatai.txt");
    fr<<"Rasos kolekcija:"<<endl;
    for(int i=0;i<size1;i++)
    {
        fr<<arr1[i]<<" ";
    }
    fr<<endl<<"Rimo kolekcija:"<<endl;
    for(int i=0;i<size2;i++)
    {
        fr<<arr2[i]<<" ";
    }
    fr.close();
}

void BubbleSort(int* arr, int size)
{
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                // swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
