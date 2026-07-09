#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T,a,b,i;
    f>>T;
    for(i=1;i<T;i++){
        f>>a;
        f>>b;
        if(a==0 || b==0)
            {if(a==0 && b!=0)
                g<<b;
            if(a!=0 && b==0)
                g<<a;
            if(a==0 && b==0)
                g<<"0";}
        else
            {while(a!=0 && b!=0){
                if(a>=b)
                    a=a%b;
                else
                    b=b%a;
            }
            if(a==0)
                g<<b;
            if(b==0)
                g<<a;
            }
        g<<endl;}
        f>>a;
        f>>b;
        if(a==0 || b==0)
            {if(a==0 && b!=0)
                g<<b;
            if(a!=0 && b==0)
                g<<a;
            if(a==0 && b==0)
                g<<"0";}
        else
            {while(a!=0 && b!=0){
                if(a>=b)
                    a=a%b;
                else
                    b=b%a;
            }
            if(a==0)
                g<<b;
            if(b==0)
                g<<a;
            }



    return 0;}
