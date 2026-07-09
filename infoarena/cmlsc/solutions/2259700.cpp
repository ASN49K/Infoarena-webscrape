#include <iostream>
#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int sir1[1024];
int sir2[1024];
int subsir[1024];
int subsir2[1024];
int subsir_max=0;
int m,n;
void read(int n,int sir[]){
for(int i=0;i<n;i++){
    in>>sir[i];
}
}
void subsir_get(){
int subsir_length=0;
int limit2=0;
for(int i=0;i<m;i++){
    subsir_length=0;
    limit2=0;
    for(int p=i;p<m;p++){
    for(int k=limit2;k<n;k++){
        if(sir1[p]==sir2[k]){
            limit2=k+1;
            subsir[subsir_length]=sir1[p];
            subsir_length++;
        }
    }
    }
    if(subsir_length>subsir_max){
        subsir_max=subsir_length;
        for(int i=0;i<subsir_max;i++)
            subsir2[i]=subsir[i];
    }

}
out<<subsir_max<<endl;
for(int i=0;i<subsir_max;i++)
    out<<subsir2[i]<<" ";
}
void readall(){
in>>m>>n;
read(m,sir1);
read(n,sir2);
}

int main()
{
readall();
subsir_get();
}
