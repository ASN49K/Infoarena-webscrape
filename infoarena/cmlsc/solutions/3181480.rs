use std::error::Error;
use std::fs::read_to_string;
use std::fs::File;
use std::io::Write;

fn solve(fst: &[u32], scd: &[u32]) -> Vec<u32> {
    let m = fst.len();
    let n = scd.len();
    let mut dp = vec![vec![0; n]; m];

    for i in 0..m {
        for j in 0..n {
            let same = (fst[i] == scd[j]) as u32;
            if i == 0 || j == 0 {
                dp[i][j] = same;
            } else {
                dp[i][j] = dp[i][j - 1].max(dp[i - 1][j]).max(dp[i - 1][j - 1] + same);
            }
        }
    }

    let (mut ix, mut iy) = (m - 1, n - 1);
    let mut longest = vec![];
    while ix > 0 && iy > 0 {
        if fst[ix] == scd[iy] {
            longest.push(fst[ix]);
            ix -= 1;
            iy -= 1;
        } else if dp[ix][iy - 1] >= dp[ix - 1][iy] {
            iy -= 1;
        } else {
            ix -= 1;
        }
    }
    if fst[ix] == scd[iy] {
        longest.push(fst[ix]);
    }

    longest
}

fn fetch_vec(line: &str) -> Vec<u32> {
    line.trim()
        .split(' ')
        .map(|x| x.parse::<u32>().unwrap())
        .collect()
}

fn main() -> Result<(), Box<dyn Error>> {
    let content = read_to_string("cmlsc.in")?;
    let mut lines = content.lines().skip(1);

    let fst = fetch_vec(lines.next().unwrap());
    let scd = fetch_vec(lines.next().unwrap());

    let mut buffer = File::create("cmlsc.out")?;
    let sol = solve(&fst, &scd);
    let _ = buffer.write(format!("{}\n", sol.len()).as_bytes());
    for x in sol {
        let _ = buffer.write(format!("{} ", x).as_bytes());
    }

    Ok(())
}
