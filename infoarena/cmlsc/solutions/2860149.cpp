#include <iostream>
#include <fstream>

using namespace std;

int mem[1024];
int v1[1024];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int main() {

    int n,m,x,ct;

    fin>>n>>m;

    for(int i=0;i<n;i++)
        fin>>v1[i];

    for(int i=0;i<m;i++){
        fin>>x;

        ct=0;

        for(int j=0;j<n;j++)
            if(mem[j]==0){
                if(v1[j]==x){
                    mem[j]=ct+1;
                    break;
                }

            }else
                if(ct < mem[j])
                    ct = mem[j];

    }

    ct++;
    fout<<ct<<"\n";
    int j=1;

    for(int i=0;i<n && j<=ct;i++)
        if(mem[i]==j){
            fout<<v1[i]<<" ";
            j++;
        }



    return 0;
}
