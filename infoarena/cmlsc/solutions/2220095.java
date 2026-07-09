import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.PrintWriter;

import java.util.stream.Stream;
import java.util.List;
import java.util.ArrayList;


public class LCS {
	public static void main(String[] args) {
		FileActions fActions = new FileActions();
	}
}

class FileActions {
	private int[][] values = new int[3][];
	private int[][] arr = null;

	public FileActions() {
		readFrom();
		findLCS(values[0][0], values[0][1]);
	}

	private void readFrom() {
		try {
			Scanner scanner = new Scanner(new File("clmsc.in"));
			for (int i=0;i<3;i++) { 
				values[i] = Stream.of(scanner.nextLine().split("\\s+"))
						.mapToInt(Integer::parseInt).toArray();
			}
			scanner.close();
		} catch (FileNotFoundException e) { e.printStackTrace(); }
	}

	private void writeTo(int[] lcs, int limit) {
		try {
			PrintWriter writer = new PrintWriter("clmsc.out");
			String temp = "";
			for (int k = 0; k <= limit-1;k++) { temp += lcs[k] + " "; }
			writer.println(limit);
			writer.println(temp);
			writer.close();
		} catch (IOException e) { e.printStackTrace(); }
	}

	private void findLCS(int first, int second) {
		arr = new int[first+1][second+1];

		for (int i = 0;i <= first; i++) {
			for (int j = 0;j <= second;j++) {
				if (i == 0 || j == 0) {
					arr[i][j] = 0;
				} else if ( values[1][i-1] == values[2][j-1]) {
					arr[i][j] = arr[i-1][j-1] + 1;
				} else {
					arr[i][j] = Math.max(arr[i-1][j], arr[i][j-1]);
				}
			}
		}

		int idx = arr[first][second];
		int temp = idx;

		int[] lcs = new int[idx+1];

		int i = first, j = second;
		while (i > 0 && j > 0) {
			if (values[1][i-1] == values[2][j-1]) {
				lcs[idx-1] = values[1][i-1];
				i--; j--; idx--;
			} else if (arr[i-1][j] > arr[i][j-1]) {
				i--;
			} else { j--; }
		}
		writeTo(lcs, temp);
	}
}