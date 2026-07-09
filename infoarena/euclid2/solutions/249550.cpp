/*
    Nume:Temian
    Date:
    Problema:
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");  
    int c,a,b,n;
    fin>>n;
    while(n){
    fin>>a>>b;		     
    while (b) {  
        c = a % b;  
        a = b;  
        b = c;  
    }  
    fout<<a<<"\n";n--;}
    system ("pause");
    return 0;
}
