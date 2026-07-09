#include<fstream>
#include <iostream>
#include <cstring>
using namespace std;
ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

char A[20000001], B[20000001];

int main(){
    fin.getline(A,200000);
    fin.get();
    fin.getline(B,200000);
    int lenA = strlen(A), lenB = strlen(B), cnt = 0, poz[100001];
    for(int i = 0; i<lenB-lenA+1; i++)
    {
        int j = 0;
        bool ok = true;
        while(j<lenA && ok)
        {
            if(A[j]!=B[i+j])
                ok = false;
            j++;
        }
        if(ok)
        {
            cnt++;
            poz[cnt] = i+1;
        }
    }
    fout<<cnt<<" ";
    for(int i=1;i<=cnt;i++)
    {
        fout<<poz[i]<<" ";
    }
}
