#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <stack>
//#define CONSOLE /// daca ai in consola
#define int long long
using namespace std;
 
ifstream fin("paranteze1.in");
ofstream fout("paranteze1.out");
 
#ifdef CONSOLE
    #define fin cin 
    #define fout cout 
#endif
stack<bool> S;
signed main() { 
    int t,a,b;
    fin>>t;
    for(int i=1;i<=t;i++){
        fin>>a>>b;
        int r;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';
    }
    return 0;
}
/*
dropper si dispenser, doi prieteni buni
cumi e grasuta =_)
e gras fetita
"sunt un suta" - cumi =_)
*/