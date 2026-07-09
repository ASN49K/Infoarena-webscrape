use std::fs::{File, OpenOptions};
use std::io::{BufReader, BufWriter};
use std::io::prelude::*;

const INPUT: &'static str = "euclid2.in";
const OUTPUT: &'static str = "euclid2.out"; 

fn main() -> std::io::Result<()> {
    let reader = BufReader::new(File::open(INPUT)?);
    let output = solve(reader.lines());

    let mut writer = BufWriter::new(OpenOptions::new().create(true).write(true).truncate(true).open(OUTPUT)?);

    for line in output {
        writeln!(&mut writer, "{}", line)?;
    }
    Ok(())
}


fn solve<Input: Iterator<Item=std::io::Result<String>>>(input: Input) -> impl Iterator<Item=impl std::fmt::Display> {
    input.skip(1).map(|line: std::io::Result<String>| {
             let line = line.unwrap();
             let mut it = line.split_whitespace();
             let a: usize = it.next().unwrap().parse().unwrap();
             let b: usize = it.next().unwrap().parse().unwrap();
             (a, b)
         }).map(|(a, b)| {
             gcd(a, b)
          })
}

fn gcd(a: usize, b: usize) -> usize {
    let (mut a, mut b) = if a < b { (b, a) } else { (a, b) };
    while b > 0 {
        let r = a % b;
        a = b;
        b = r;
    }
    a
}