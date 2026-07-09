#include <iostream>

int main (){

    int a , b; 
    std :: cin>>a>>b;
    
    while(b!=0){
        
        int r=a%b;
        a=b;
        b=r;
        

    }

    std :: cout<<a;

    return 0;
}