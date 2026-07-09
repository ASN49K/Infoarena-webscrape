#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int a[1100], b[1100];

string celMaiLungSubsirComun(int n, int m){
    if(n==0 or m==0)
        return "";
    if(a[n-1] == b[m-1]){
        return celMaiLungSubsirComun(n-1, m-1)+to_string(a[n-1])+" ";
    }
    string str1 = celMaiLungSubsirComun(n-1, m);
    string str2 = celMaiLungSubsirComun(n, m-1);
    if(str1.length()>str2.length())
        return str1;
    return str2;
}

int main() {
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n, m;
    f>>n>>m;
    for(int i=0; i<n; i++){
        f>>a[i];
    }
    for(int i=0; i<m; i++){
        f>>b[i];
    }
    string cmlsc = celMaiLungSubsirComun(n, m);
    g<<cmlsc.length()/2<<endl<<cmlsc;
    return 0;
}