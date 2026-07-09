///CMLSC
#include<fstream>
#include<vector>

using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    short N, M;
    vector<signed char> A, B;
    vector< vector<short> > lcs;
    vector<bool> test;

    fin>>M>>N;

    A.resize(M);
    B.resize(N);
    test.resize(M);

    for(short i=0; i<M; i++)
        fin>>A[i];
    for(short i=0; i<N; i++)
        fin>>B[i];

    vector<signed char>::iterator ita=A.end()-1, itb=B.end()-1;
    short t=M-1;
    short pre=0;
    ///while(*ita==*itb && t>=0)
    ///{
        ///test[t]=true;
        //ita--; itb--;
        ///M--; N--; t--;
        ///pre++;
    ///}

    ///if(M!=0 && N!=0)
    ///{
        lcs.resize(M+1);
        for(short i=0; i<=M; i++)
            lcs[i].resize(N+1);

        for(short i=1; i<=M; i++)
            for(short j=1; j<=N; j++)
            {
                if(A[i-1]==B[j-1])
                {
                    lcs[i][j]=lcs[i-1][j-1]+1;
                    test[i-1]=true;
                }
                else
                    lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
            }

        fout<<lcs[M][N]+pre<<'\n';
        for(short i=0; i<test.size(); i++)
            if(test[i]==true)
                fout<<A[i]<<' ';
    ///}
    ///else
    ///{
       /// fout<<pre<<'\n';
        //for(short i=0; i<test.size(); i++)
          //  if(test[i]==true)
            //    fout<<A[i]<<' ';
    //}

    return 0;
}
