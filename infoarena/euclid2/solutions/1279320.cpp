#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,m=0,i;
int main(){
    f>>a>>b;
   while (a !=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
   }
   g<< a;

}
