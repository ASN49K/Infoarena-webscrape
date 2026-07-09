#include<iostream>
#include<fstream>
using namespace std;
main(){ ifstream opa("euclid2.in");
        ofstream op("euclid2.out");
        int a,b;
       opa >>a >>b;
        while(a!=0 && b!=0){
                    if(a>b){
                            a=a%b;}
                            else{
                                 b=b%a;}
                                 }
                                 
                                              op<<a+b;
                                 }
