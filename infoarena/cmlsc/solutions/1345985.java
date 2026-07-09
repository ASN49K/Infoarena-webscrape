import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Cell {

    public boolean left;
    public boolean top;
    public boolean topLeft;
    public int seqLength;

    public Cell(int length, boolean left, boolean top, boolean topLeft) {
        this.seqLength = length;
        this.left = left;
        this.top = top;
        this.topLeft = topLeft;
    }
}

class LCSResult {

    public Cell[][] table;
    public int maxLength;
    public int maxi;
    public int maxj;
    public int aLength;
    public int bLength;

    public LCSResult(int aLength, int bLength) {
        table = new Cell[aLength + 1][bLength + 1];
        maxLength = 0;
        maxi = 0;
        maxj = 0;
        this.aLength = aLength;
        this.bLength = bLength;
    }

    public void viewCell(int seqLength, int i, int j) {
        if (maxLength < seqLength) {
            maxLength = seqLength;
            maxi = i;
            maxj = j;
        }
    }
}

public class Main {

    public static LCSResult lcs(String[] strA, String[] strB) {
        LCSResult result = new LCSResult(strA.length, strB.length);
        for (int index = 0; index <= strA.length; index++) {
            result.table[index][0] = new Cell(0, false, false, false);
        }

        for (int index = 0; index <= strB.length; index++) {
            result.table[0][index] = new Cell(0, false, false, false);
        }

        for (int i = 1; i <= strA.length; i++) {
            for (int j = 1; j <= strB.length; j++) {
                if (strA[i - 1].equals(strB[j - 1])) {
                    result.table[i][j] = new Cell((result.table[i - 1][j - 1].seqLength + 1), false, false, true);
                    result.viewCell(result.table[i][j].seqLength, i, j);
                } else if (result.table[i - 1][j].seqLength > result.table[i][j - 1].seqLength) {
                    result.table[i][j] = new Cell(result.table[i - 1][j].seqLength, true, false, false);
                } else {
                    result.table[i][j] = new Cell(result.table[i][j - 1].seqLength, false, true, false);
                }

            }
        }
        return result;
    }

    public static String getLCSString(LCSResult result, String[] strA) {
        String lcsString = "";
        Cell currentCell = result.table[result.maxi][result.maxj];
        int currenti = result.maxi;
        int currentj = result.maxj;
        while (currentCell.seqLength > 0 && currenti >= 1) {
            if (currentCell.left) {
                currenti--;
            } else if (currentCell.top) {
                currentj--;
            } else if (currentCell.topLeft) {
                lcsString = strA[currenti - 1] + " " + lcsString;
                currenti--;
                currentj--;
            }
            currentCell = result.table[currenti][currentj];
        }

        return lcsString;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        String fin = "cmlsc.in";
        FileInputStream fis = new FileInputStream(fin);
        BufferedReader br = new BufferedReader(new InputStreamReader(fis));

        String line = null;
        if ((line = br.readLine()) != null) {
            PrintWriter pw = new PrintWriter("cmlsc.out", "UTF-8");
            String[] strA = br.readLine().split(" ");
            LCSResult lcsResult = lcs(strA, br.readLine().split(" "));
            pw.println(lcsResult.maxLength);
            pw.println(getLCSString(lcsResult, strA));
            pw.close();
        }
        br.close();
    }

}
