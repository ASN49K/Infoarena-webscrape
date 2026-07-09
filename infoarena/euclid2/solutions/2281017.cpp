#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned int a,b,T;
    int dvz(int a,int b){
        if(!b)
            return a;
        return dvz(b,a%b);}

int main(){
    unsigned int i;

         f>>T;
         for (; T; --T){
                    f>>a>>b;
         g<<dvz(a,b)<<endl;}
         f.close();
         g.close();
         return 0;}
