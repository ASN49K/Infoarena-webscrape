use std::fs::{File, OpenOptions};
use std::io::prelude::*;
use std::io::{BufReader, BufWriter};

const INPUT: &'static str = "cmlsc.in";
const OUTPUT: &'static str = "cmlsc.out";

fn main() -> std::io::Result<()> {
    solve(
        BufReader::new(File::open(INPUT)?),
        BufWriter::new(
            OpenOptions::new()
                .create(true)
                .write(true)
                .truncate(true)
                .open(OUTPUT)?,
        ),
    )?;
    Ok(())
}

fn solve<Input: std::io::BufRead, Output: Write>(input: Input, mut output: Output) -> std::io::Result<()> {
    let mut lines = input.lines();
    lines.next();
    let a: Vec<u16> = lines
        .next()
        .unwrap()?
        .split_whitespace()
        .map(|number| number.parse().unwrap())
        .collect();
    let b: Vec<u16> = lines
        .next()
        .unwrap()?
        .split_whitespace()
        .map(|number| number.parse().unwrap())
        .collect();
    let mut m = vec![vec![0; b.len() + 1]; a.len() + 1];

    for (i, a_) in a.iter().enumerate() {
        for (j, b_) in b.iter().enumerate() {
            m[i + 1][j + 1] = std::cmp::max(
                std::cmp::max(m[i][j + 1], m[i + 1][j]),
                m[i][j] + (a_ == b_) as u16,
            )
        }
    }

    writeln!(&mut output, "{}", m[a.len()][b.len()])?;

    let (mut i, mut j) = (a.len(), b.len());

    let mut res = vec![];

    while m[i][j] > 0 {
        if a[i-1] == b[j-1] {
            res.push(a[i-1]);
            i = i - 1;
            j = j - 1;
        } else {
            if m[i - 1][j] > m[i][j - 1] {
                i = i - 1;
            } else {
                j = j - 1;
            }
        }
    }
    res.reverse();
    for i in res {
        write!(&mut output, "{} ", i);
    }
    writeln!(&mut output, "")?;
    Ok(())
}
