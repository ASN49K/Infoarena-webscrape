import java.io.*;
import java.util.Scanner;

/**
 * Created by elizabethkim on 12/8/15.
 */
public class Main {

    public int gcd(int fst, int snd) {

        if (fst == 0) {
            return snd;
        } else if (snd == 0) {
            return fst;
        }

        while(true) {
            return gcd(fst % snd, snd % fst);
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("euclid2.in"));
        int numberOfPairs = 0;

        if(sc.hasNext()) {
            numberOfPairs = Integer.parseInt(sc.next());
        }

        BufferedWriter bw = new BufferedWriter(new FileWriter("euclid2.out"));

        Main eu = new Main();

        for(int i = 0; i < numberOfPairs; i++) {
            String result = String.valueOf(eu.gcd(Integer.parseInt(sc.next()), Integer.parseInt(sc.next())));
            bw.write(result);
            bw.newLine();
        }

        sc.close();
        bw.close();
    }
}
