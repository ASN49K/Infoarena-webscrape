#include <fstream>
#include<iostream>
using namespace std;
 
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
 
int euclid(int,int);
     
int main(){
    int n,x,y;
    fin>>n;
    while(n){
        fin>>x>>y;
        fout<<euclid(x,y)<<"\n";
        n--;
    }
    fin.close();
    fout.close();
}
 
int euclid(int x,int y){
    int aux;
    while(y){
    aux=y;
    y=x%y;
    x=aux;
    }
    return x;
}