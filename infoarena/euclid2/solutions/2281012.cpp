#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned int a,b,t;
    int dvz(int a,int b){
        if(!b)
            return a;
        return dvz(b,a%b);}

int main(){
    int i;

         f>>t;
         for(i=1;i<=t;i++){
                    f>>a>>b;
         g<<dvz(a,b)<<endl;}
         f.close();
         g.close();
         return 0;}
