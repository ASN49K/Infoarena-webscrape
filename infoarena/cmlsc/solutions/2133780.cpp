#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

istream & in = fin;
ostream & out = fout;

int matw, math;
int v1[1041], v2[1041];
int mat[1041][1041];

int whomlen;
int whom[2082];

void read()
{
    in >> matw >> math;
    for(int i = 1; i <= matw; i++){
        in >> v1[i];
    }
    for(int i = 1; i <= math; i++){
        in >> v2[i];
    }
}

void genmat()
{
    for(int y = 1; y <= math; y++){
        for(int x = 1; x <= matw; x++){
            if(v1[x] == v2[y]){
                mat[x][y] = mat[x - 1][y - 1] + 1;
            }else{
                mat[x][y] = max(mat[x - 1][y - 1], max(mat[x - 1][y], mat[x][y - 1]));
            }
            //cout << mat[x][y] << " ";
        }
        //cout << "\n";
    }
}

void solve()
{
    genmat();
}

void write()
{
    int x = matw, y = math;
    while(x != 0 && y != 0){
        if(v1[x] == v2[y]){
            whom[whomlen++] = v1[x];
            x--, y--;
        }else{
            if(mat[x][y] == mat[x - 1][y]){
                x--;
            }else{
                y--;
            }
        }
    }
    out << whomlen << "\n";
    for(int i = whomlen - 1; i >= 0; i--){
        out << whom[i] << " ";
    }
}

int main()
{
    read();
    solve();
    write();
    return 0;
}
