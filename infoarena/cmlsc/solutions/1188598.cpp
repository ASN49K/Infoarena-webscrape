// CEL MAI LUNG SUBSOL COMUN

    # include <cstdio>
      using namespace std;

      int a,b;
      short SOL[1026];

      short A[1030][1030];
      short M[1030];
      short N[1030];

      int main()
      {

          FILE * f = fopen ("cmlsc.in","r");
          FILE * g = fopen ("cmlsc.out","w");

          fscanf (f, "%d %d", &a, &b);

          for(int i=1;i<=a;++i) fscanf(f, "%hd", &M[i]);
          for(int i=1;i<=b;++i) fscanf(f, "%hd", &N[i]);

          int T=0;

          for(int i=1;i<=a;++i)
          {

            for(int j=1;j<=b;++j)
            {
              if(M[i] == N[j])
                  A[i][j]=A[i-1][j-1]+1;
              else
                if (A[i-1][j] > A[i][j-1])
                      A[i][j]=A[i-1][j];

                else A[i][j]=A[i][j-1];

            }
          }

          T=0;

          for(int i=a,j=b;i;)
            if(M[i]==N[j])
                SOL[++T]=M[i], --i, --j;
            else
                if(A[i-1][j] < A[i][j-1]) --j;
            else
                --i;
          fprintf(g, "%d \n",T);

          for(int i=1;i<=T;++i) fprintf(g, "%hd ", SOL[i]);

      }
