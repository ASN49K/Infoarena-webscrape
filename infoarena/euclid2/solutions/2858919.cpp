#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int divizor(int a,int b){

    if(a%b==0) return b;
    else if(b%a==0) return a;
    else if(a>=b) divizor(a%b,b);
    else divizor(a,b%a);

}

int main()
{
    int n,a,b;
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>a>>b;
        fout<<divizor(a,b)<<endl;
    }
    return 0;
}
