#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main(){
    int tests;
    fin>>tests;
    
    while (tests)
    {
        int n;
        fin>>n;
        vector<int>v(n);
        fin>>v[0];
        int rez=v[0];
        for(int i=1;i<n;++i){
            fin>>v[i];
            rez=rez^v[i];
        }
        if(rez==0){
            fout<<"NU"<<"\n";
        }else{
            fout<<"DA"<<"\n";
        }
        --tests;
    }
    
    return 0;
}