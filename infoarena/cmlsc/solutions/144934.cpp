#include <fstream.h>

ifstream f1("cmlsc.in");
ofstream f2("cmlsc.out");

int main ()
{
int n,i,j,v[10001],subsir[10001];
int lungime,inceput,maxime[10001],urmatorul[10001];
f1>>n;
for (i=1;i<=n;i++)f1>>v[i];
maxime[n]=1;
urmatorul[n]=-1;
for (i=n-1;i>=1;i--){
    maxime[i]=1;
    urmatorul[i]=-1;
    for (j=i+1;j<=n;j++){
        if (v[i]<=v[j]&&maxime[i]<=maxime[j]){
                                              maxime[i]=maxime[j]+1;
                                              urmatorul[i]=j;
        }
    }
}
lungime=maxime[1];
inceput=1;
for (i=1;i<=n;i++){
    if (lungime<maxime[i]){
                           lungime=maxime[i];
                           inceput=i;
    }
}
subsir[1]=v[inceput];
for (i=2;i<=lungime;i++){
    inceput=urmatorul[inceput];
    subsir[i]=v[inceput];
}
for (i=1;i<=lungime;i++)f2<<subsir[i]<<" ";
f1.close();
f2.close();
return 0;
}
