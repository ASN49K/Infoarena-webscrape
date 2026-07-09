#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,t,i,m;
int main(){
    f>>t;
    while(t>0){
    f>>a>>b;
    m=1;
    t--;
    if(a>b){
        for(i=2;i<=b;i++){
            if(a%i==0 && b%i==0)
                if(m<i)
                    m=i;
        };
        }
        else
        {
        for(i=2;i<=b;i++){
            if(a%i==0 && b%i==0)
                if(m<i)
                    m=i;
        };};
        g<<m<<endl;
    };


};
