import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	private static int SIZE = 1030;

	private static int[] patth1;
	private static int[] patth2;

	private static int din[][] = new int[SIZE][SIZE];

	public static int[] analyze(int[] path1, int[] path2) {
		for (int i = 0; i < path1.length; i++) {
			for (int j = 0; j < path2.length; j++) {
				din[i + 1][j + 1] = path1[i] == path2[j] ? 1 + din[i][j] : Math.max(din[i][j + 1], din[i + 1][j]);

			}
		}

		int x = path1.length - 1;
		int y = path2.length - 1;

		List<Integer> rez = new ArrayList<Integer>();
		while (x >= 0) {
			if (path1[x] == path2[y]) {
				rez.add(path1[x]);
				x--;
				y--;
			} else if (din[x][y + 1] < din[x + 1][y]) {
				y--;
			} else {
				x--;
			}
		}
		int result[] = new int[rez.size()];
		int index = rez.size() - 1;
		for (Integer value : rez) {
			result[index--] = value;
		}
		return result;
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new FileInputStream("cmlsc.in"));
		int nrx = scanner.nextInt();
		int nry = scanner.nextInt();
		patth1 = new int[nrx];
		for (int i = 0; i < nrx; ++i) {
			patth1[i] = scanner.nextInt();

		}
		patth2 = new int[nry];
		for (int i = 0; i < nry; ++i) {
			patth2[i] = scanner.nextInt();

		}

		int rez[] = analyze(patth1, patth2);
		PrintWriter stream = new PrintWriter("cmlsc.out");
		stream.printf("%d\n", rez.length);
		for (int i = 0; i < rez.length; i++) {
			stream.printf("%d ", rez[i]);
		}
		stream.close();

	}

}
