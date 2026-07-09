#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

struct data{
    int preced;
    int val;
};

// we search from left to right the best match (the highest yield one by comparing to each element) and remember to the position
// in the memory the yield

int mem[1024][1024];
int v1[1024];
int v2[1024];

stack<int> stiva;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int main() {

    int n,m,ct,maxyield, maxpoz, maxglobal;
    bool maxglobalChange;

    fin>>n>>m;

    for(int i=0;i<n;i++)
        fin>>v1[i];

    for(int i=0;i<m;i++)
        fin>>v2[i];

    for(int i=0;i<n;i++){

        maxglobal =0;
        maxglobalChange= true;

        for(int j=0;j<m;j++){

            if(i>0)
                mem[i][j] = mem[i-1][j];

            if(v1[i] == v2[j]  && maxglobalChange && maxglobal >= mem[i][j]){
                maxglobal++;
                maxglobalChange = false;
                mem[i][j] = maxglobal;
                continue;
            }

            if(mem[i][j] >= maxglobal){
                maxglobal = mem[i][j];
                maxglobalChange = true;
            }


        }


    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<mem[i][j]<<" ";

        cout<<"\n";
    }



    fout<<maxglobal<<"\n";

    int i=n-1;

    for(int j=m-1;j>=0 && maxglobal!=0;j--)
        if(mem[i][j] == maxglobal){

            while (mem[i][j] == maxglobal)
                i--;

            stiva.push(v2[j]);
            maxglobal--;

        }

    while (!stiva.empty()){
        fout<<stiva.top()<<" ";
        stiva.pop();
    }


    return 0;
}
