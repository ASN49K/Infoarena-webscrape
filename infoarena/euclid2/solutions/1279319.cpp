#include<iostream>
using namespace std;
int a,b,m=0,i;
int main(){
    cin>>a>>b;
   while (a !=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
   }
   return a;

}
