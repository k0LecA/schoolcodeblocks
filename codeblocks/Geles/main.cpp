#include <bits/stdc++.h>
using namespace std;

int diena[3] = {0,30,61};
ifstream fd("duomenys.txt");
ofstream fr("rezultatai.txt");

int rastiPradzia(int zydi[]){
    int p = 0;
    for (int i = 1; i<=92; i++){
        if(zydi[i]>zydi[p]){
            p = i;
        }
    }
    return p;
}
void ats(int d){
    if(d<=30){
        fr << 6 << " " << d;
    }
    else if(d<=61){
        fr << 7 << " " << d-30;
    }
    else{
        fr << 8 << " " << d-61;
    }
}
int main(){
    int n; fd >> n;
    int zydi[100] = {0};
    for (int i = 0; i<n; i++){
        int m1,d1,m2,d2;
        fd >> m1/*nr jo nereikia*/ >> m1 >> d1 >> m2 >> d2;
        for (int j = diena[m1-6]+d1; j<=diena[m2-6]+d2; j++){
            zydi[j]++;
        }
    }

    int pradzia = rastiPradzia(zydi);
    int pabaiga = pradzia;
    while(zydi[pradzia]==zydi[pabaiga+1] and pabaiga+1<=92){
        pabaiga++;
    }

    fr << zydi[pradzia] << endl;
    ats(pradzia);
    fr << endl;
    ats(pabaiga);

    fd.close();
    fr.close();
    return 0;
}
