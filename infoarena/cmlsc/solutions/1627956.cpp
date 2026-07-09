#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const char inFile[] = "cmlsc.in";
const char outFile[] = "cmlsc.out";

int N, M;
vector<int> A, B, S;
vector<vector<int>> D;

int maxim( int a, int b ){
    return a > b ? a : b;
}

void read(){

    ifstream fin(inFile);
    int tmp;

    fin >> M >> N;

    A.push_back(0);
    B.push_back(0);

    for( int i = 0; i < M; i++ ){
        fin >> tmp;
        A.push_back( tmp );
    }

    for( int i = 0; i < N; i++ ){
        fin >> tmp;
        B.push_back( tmp );
    }

    fin.close();

}

void find_max_length(){

    for( int i = 0; i <= M; i++ ){

        D.push_back( *(new vector<int>) );

        for( int j = 0; j <= N; j++ ){

            if( i == 0 || j == 0 ){
                D[i].push_back(0);
                continue;
            }

            if( A[i] == B[j] )
                D[i].push_back( D[i-1][j-1] + 1 );
            else
                D[i].push_back( maxim( D[i-1][j], D[i][j-1] ) );

        }

    }

}

void find_solution(){

    int length = D[M][N];
    int i = M, j = N;

    while( length ){

        if( A[i] == B[j] ){
            S.push_back( A[i] );
            length--;
            i--, j--;
        }
        else
            D[i-1][j] > D[i][j-1] ? i-- : j--;

    }

}

void print(){

    ofstream fout(outFile);

    fout << D[M][N] << "\n";

    for( int i = S.size() - 1 ; i >= 0 ; i-- )
        fout << S[i] << " ";

    fout << "\n";

    fout.close();

}

int main()
{

    read();

    find_max_length();

    find_solution();

    print();

    return 0;
}
