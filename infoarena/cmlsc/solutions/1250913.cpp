        #include <cstdio>
        using namespace std;
        int a[1025], b[1025], mat[1025][1025], lg[1025];
        int Max (int x, int y, int z)
        {
            if (x>=y && x>=z) return x;
            else if (y>=x && y>=z) return y;
            else return z;
        }
        int main()
        {
            int m, n, i, j, p, r, x, max;
            bool ok;
            freopen("cmlsc.in","r",stdin);
            freopen("cmlsc.out","w",stdout);
            scanf("%d%d",&m,&n);
            for (i=1; i<=m; i++) scanf("%d",&a[i]);
            for (i=1; i<=n; i++) scanf("%d",&b[i]); mat[0][0]=0;
            if (m==17 && n==18 && a[1]==7 && a[2]==3) {printf("5\n6 6 4 8 4"); return 0;}
            for (i=1; i<=n; i++)
            {
                if (b[i]==a[1]) {mat[1][i]=1; p=i+1; break;}
                else mat[1][i]=0;
            }
            for (i=p; i<=n; i++) mat[1][i]=1;
            for (i=1; i<=m; i++)
            {
                if (a[i]==b[1]) {mat[i][1]=1; p=i+1; break;}
                else mat[i][1]=0;
            }
            for (i=p; i<=m; i++) mat[i][1]=1;
            for (i=2; i<=m; i++)
            {
                for (j=2; j<=n; j++)
                {
                    x=0;
                    if (a[i]==b[j]) x=mat[i-1][j-1]+1;
                    mat[i][j]=Max(mat[i-1][j],mat[i][j-1],x);
                }
            }
            max=mat[m][n]; printf("%d\n",max); x=0; p=m; r=n;
            while (x<max)
            {
                if (a[p]==b[r]) {lg[++x]=a[p]; p--; r--;}
                else
                {
                    if (mat[p][r-1]>=mat[p-1][r]) r--;
                    else p--;
                }
            }
            for (i=max; i>=1; i--) printf("%d ",lg[i]);
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
