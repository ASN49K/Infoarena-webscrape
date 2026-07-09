#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

//Aceasta prima solutie este una ineficienta, nefolosind Algoritmul lui Euclid.
// int main(){
//     int n,a,b,i,j,sol;
//     in>>n;
//     for(i=0;i<n;++i){
//         in>>a>>b;
//         sol=1;
//         for(j=min(a,b);j>=1;--j){
//             if(a%j==0&&b%j==0){
//                 out<<j<<endl;
//                 break;
//             }
//         }
//     }
    
//     return 0;
// }

// Aceasta solutie foloseste Algoritmul lui Euclid prin scadere, deci este eficient, dar NU cel mai eficient!
// int main(){
//     int n,a,b,i;
//     in>>n;
//     for(i=0;i<n;++i){
//         in>>a>>b;
//         while(a!=b){
//             if(a>b){
//                 a-=b;
//             }
//             else{
//                 b-=a;
//         }
//     }
//     out<<a<<endl;
//     }

//     return 0;
// }

int main(){
    int n,a,b,i;
    in>>n;
    for(i=0;i<n;++i){
        in>>a>>b;
        while(b!=0){
            int r=a%b;
            a=b;
            b=r;
        }
        out<<a<<endl;
    }
    return 0;
}