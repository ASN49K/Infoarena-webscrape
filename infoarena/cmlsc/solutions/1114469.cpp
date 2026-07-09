// Cel mai lung subsir comun intre 2 siruri date
// Recurenta:
// Notam cu d[i][j] cel mai lung subsir al sirurilor a[1..i] si 
// b[1..j], 
// d[i][j] = d[i-1][j-1]+1 daca a[i] == b[j];
// d[i][j] = max(d[i-1][j], d[i][j-1]) daca a[i] != b[j];
// Solutia se va afla in d[n][m].

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cstring>

const int MaxN = 1024;

inline int maxim(int a, int b)
{
    return a > b ? a : b;
}

void initialize(int d[MaxN][MaxN], int n, int m)
{
    for( int i=0 ; i<=n ; i++)
        for( int j=0 ; j<=m ; j++ )
            d[i][j] = 0;
}

std::stack<int> findSubstring(int d[MaxN][MaxN], std::vector<int>& a,std::vector<int>& b)
{
    int i,j,n,m;
    std::stack<int> stack;
    
    n = a.size()-1;
    m = b.size()-1;
    for( i = n , j = m ; i ; ){
        if( a[i] == b[j] )
            stack.push(a[i]), i-- , j--;
        else if( d[i][j-1] > d[i-1][j] )
                j--;
            else
                i--;
    }
    return stack;
}

void printSolution(int sol, std::stack<int> stack, std::ostream& out)
{
    out << sol << '\n';
    while( !stack.empty() ){
        out << stack.top() << ' ';
        stack.pop();
    }
    out << '\n';
}

void readData(std::vector<int>& a, int& n, std::vector<int>& b,
        int& m, std::istream& in){
    
    int x;
    in >> n >> m;
    
    a.push_back(0);
    b.push_back(0);

    for( int i=0 ; i<n ; i++ ){
        in >> x;
        a.push_back(x);
    }
    for( int j=0 ; j<m ; j++ ){
        in >> x;
        b.push_back(x);
    }
}

int main(void)
{
    int n, m;
    std::vector<int> a,b;
    int d[MaxN][MaxN];

    std::ifstream in("cmlsc.in");
    std::ofstream out("cmlsc.out");
 
    readData(a, n, b, m, in);
    initialize(d, n, m);

    for( int i=1 ; i<=n ; i++ )
        for( int j=1 ; j<=m ; j++)
            if( a[i] == b[j] )
                d[i][j] = d[i-1][j-1]+1;
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
    
    std::stack<int> stack;
    stack = findSubstring(d, a, b);
    printSolution(d[n][m], stack, out);

    out.close();
    in.close();

    return 0;
}


