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

        List<Integer> ans=new ArrayList<>();
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
                ans.add(arr[i]);
            }
            else dp[i+1][j+1]=Math.max(dp[i][j+1],dp[i+1][j]);
        }
        output.println(dp[n][m]);
        for(int i=0;i<ans.size();i++)output.print(ans.get(i)+" ");
        output.close();
    }
}
