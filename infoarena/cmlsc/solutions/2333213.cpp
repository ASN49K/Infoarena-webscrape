#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int const maxim=1050;
int vector1[maxim];
int vector2[maxim];
int a,b,contor=0;
int vector3[maxim];
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
 
void afisare(int x,int y){
while(x&&y){
    if(vector1[x]==vector2[y]){vector3[contor]=vector1[x];contor++;x--;y--;}
    else{
        if(matrice[x-1][y]>matrice[x][y-1])--x;
        else y--;
    }
}
out << contor << endl;
for(int i=contor-1;i>-1;i--){
    out << vector3[i] << " ";
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
