#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,n;
    fin>>n;
    for (int i = 0;i<n ;i++ )
    {
        fin>>a>>b;
        while(b!=0)
        {
            a=a%b;
            if(b>a)
                swap(a,b);
        }
        fout<<a<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
