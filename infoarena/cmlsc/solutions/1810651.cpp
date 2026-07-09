#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int max(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

int main() {
    int m,n;
    ifstream in;
    in.open("cmlsc.in");

    ofstream out;
    out.open("cmlsc.out");

    in>>m>>n;

    int A[m];
    int B[n];
    for (int i = 0; i < m; i++)
    {
        in>>A[i];
    }
    for (int i = 0; i < n; i++)
    {
       in>>B[i];
    }
    int H[m+1][n+1];
    for (int i = 0; i < m+1; i++)
    {
       H[i][0] = 0;
    }
    for (int i = 0; i < n+1; i++)
    {
        H[0][i] = 0;
    }
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++){
            if (A[i-1] == B[j-1])
            {
                H[i][j] = H[i-1][j-1]+1;
            } else
            {
                H[i][j] = max(H[i-1][j],H[i][j-1]);
            }
        }


    }
    out<<H[m][n];
    string s = "";
    int i = m;
    int j = n;
    out << "\n";
    while(H[i][j] != 0)
    {
        if (A[i-1] == B[j-1])
        {
            ostringstream passage;
            passage << A[i-1];
            s = passage.str() + " " + s;
            i = i-1;
            j = j-1;
        } else if(H[i-1][j]>H[i][j-1])
        {
            i = i-1;
        } else {
            j = j-1;
        }
    }

    out << s;

    return 0;
}