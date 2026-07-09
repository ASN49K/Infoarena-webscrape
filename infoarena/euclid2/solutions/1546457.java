import java.io.*;
import java.util.Scanner;

/**
 * Created by elizabethkim on 12/8/15.
 */
public class Main {

    public static int gcd(int fst, int snd) {

        if (fst == 0) {
            return snd;
        } else if (snd == 0) {
            return fst;
        }

        return gcd(fst % snd, snd % fst);
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("euclid2.in"));
        int numberOfPairs = 0;

        if(sc.hasNext()) {
            numberOfPairs = Integer.parseInt(sc.next());
        }

        BufferedWriter bw = new BufferedWriter(new FileWriter("euclid2.out"));

        for(int i = 0; i < numberOfPairs; i++) {
            String result = String.valueOf(gcd(Integer.parseInt(sc.next()), Integer.parseInt(sc.next())));
            bw.write(result);
            bw.newLine();
        }

        sc.close();
        bw.close();
    }
}
