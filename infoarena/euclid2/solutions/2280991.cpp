#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned int a,b,t,i;
    int dvz(int a,int b){
        if(!b)
            return a;
        else if(a>b)
        return dvz(a-b,b);
        else
        return dvz(a,b-a);}
     int main(){
         f>>t;
         for(i=1;i<=t;i++){
                    f>>a>>b;
         g<<dvz(a,b)<<endl;}
         return 0;}
