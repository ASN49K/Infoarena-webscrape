package arhivaEducationala;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

 class Cmlsc {

	private int m;
	private int n;
	private int[] a;
	private int[] b;
	private List<Integer> maxims;

	public void initializeData(String fileName) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File(
					fileName)));
			String firstLine = br.readLine();
			String secondLine = br.readLine();
			String thirdLine = br.readLine();
			String[] nos = firstLine.split(" ");
			m = Integer.parseInt(nos[0]);
			n = Integer.parseInt(nos[1]);
			a = new int[m];
			b = new int[n];
			String[] as = secondLine.split(" ");
			String[] bs = thirdLine.split(" ");
			for (int i = 0; i < as.length; i++) {
				a[i] = Integer.parseInt(as[i]);
			}
			for (int i = 0; i < bs.length; i++) {
				b[i] = Integer.parseInt(bs[i]);
			}
			maxims = new ArrayList<>();
			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public List<Integer> lcs(int i, int j) {
		if (i == -1 || j == -1) {
			return null;
		} else if (a[i] == b[j]) {
			List<Integer> previousResult = lcs(i - 1, j - 1);
			if(previousResult != null)
				previousResult.add(a[i]);
			else{
				previousResult = new ArrayList<>();
				previousResult.add(a[i]);
			}
				
			return previousResult;
		} else {
			List<Integer> result1 = lcs(i - 1, j);
			List<Integer> result2 = lcs(i, j - 1);
			if (result1 != null) {
				if(result2 == null || result2.size() < result1.size())
				return result1;
				return result2;
			} else
				return result2;
		}
	}

	public void processInformation() {
		initializeData("cmlsc.in");
		maxims = lcs(m - 1, n - 1);
		writeResult("cmlsc.out");
	}

	public void writeResult(String fileName) {
		PrintWriter pw = null;
		try {
			pw = new PrintWriter(new File(fileName));
			pw.println(maxims.size());
			for(int i : maxims){
				pw.print(i + " ");
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} finally {
			pw.close();
		}

	}

	public static void main(String[] args) {
		Cmlsc c = new Cmlsc();
		c.processInformation();
	}
}
