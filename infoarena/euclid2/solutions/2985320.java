import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main
{
    static int cmmdc(int a,int b)
    {
        while(b  != 0)
        {
            int r =a%b;
            a=b;
            b=r;
        }
        return a;
    }
    public static void main(String[] args) throws IOException
    {
       FastRead f = new FastRead("euclid2.in");
       OutputStreamWriter g =new OutputStreamWriter(new FileOutputStream("euclid2.out"));
       int n = f.nextInt();
       for(int i=1;i<=n;i++)
       {
        int a,b;
        a = f.nextInt();
        b = f.nextInt();
        String out = cmmdc(a, b)+"\n";
        g.write(out);
       }
       g.close();
    }
    static class FastRead
    {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");
        FastRead()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        FastRead(String s) throws FileNotFoundException
        {
            br = new BufferedReader(new InputStreamReader(new FileInputStream(s)));
        }
        String next()
        {
            while(!st.hasMoreTokens())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }catch(IOException e){}
            }
            return st.nextToken();
        }
        int nextInt()
        {
            return Integer.parseInt(next());
        }
        long nextLong()
        {
            return Long.parseLong(next());
        }
    }
}