import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("cmlsc.in"));
        PrintWriter output = new PrintWriter("cmlsc.out");

        int n = input.nextInt();
        int m = input.nextInt();
        int[] arr=new int[n];
        int[] brr=new int[m];
        for (int i = 0; i < n; i++)arr[i]=input.nextInt();
        for(int j=0;j<m;j++)brr[j]=input.nextInt();

        int[][]dp=new int[n+1][m+1];
        for(int i=0;i<n;i++)dp[i][0]=0;
        for(int i=0;i<m;i++)dp[0][i]=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(arr[i]==brr[j]){
                dp[i+1][j+1]=Math.max(Math.max(dp[i][j+1],dp[i+1][j]),dp[i][j]+1);
            }
            else dp[i+1][j+1]=Math.max(dp[i][j+1],dp[i+1][j]);
        }
        int[]ans=new int[dp[n][m]];int k=dp[n][m]-1;
        for(int i=n,j=m;i>=1 &&j>=1;i--,j--){
            if(dp[i][j]==dp[i-1][j-1]+1){
                ans[k]=arr[i-1];k--;
            }
        }
        output.println(dp[n][m]);
        for(int i=0;i<ans.length;i++)output.print(ans[i]+" ");
        output.close();
    }
}
