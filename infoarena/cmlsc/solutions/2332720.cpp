#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int const maxim=1050;
int vector1[maxim];
int vector2[maxim];
int a,b;
int matrice[maxim][maxim]={0};

void matricus(){
for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
        if(vector1[i]==vector2[j]){
            matrice[i][j]=matrice[i-1][j-1]+1;
        }
        else{
            matrice[i][j]=max(matrice[i-1][j],matrice[i][j-1]);
        }
    }

}
}

int afisare(int x,int y){
if(vector1[x]==vector2[y]) {afisare(x-1,y-1); out << vector1[x] << " "; return 0;}
if(x==0 || y==0)return 0;
else{
    if(matrice[x-1][y]>matrice[x][y-1])return afisare(x-1,y);
    else return afisare(x,y-1);
}
}



void citire(){
in >> a >> b;
for(int i=1;i<=a;i++){
    in >> vector1[i];
}
for(int i=1;i<=b;i++){
    in >> vector2[i];
}
}

int main(){
citire();
matricus();
afisare(a,b);
return 0;}
