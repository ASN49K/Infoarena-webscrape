/*
Euclid's algorithm
The largest common divisor between two natural numbers a and b is the largest positive natural number d that divides both numbers.

Requirement
Given T pairs of natural numbers (a, b) , calculate the largest common divisor of numbers in each pair.

Input data
The input file euclid2.in contains on the first line the number T of pairs. The following T lines contain two natural numbers a and b .

Release dates
In the output file euclid2.out will be written T lines. The i -line in this file contains the largest common divisor of the numbers in the pair on line i + 1 in the input file.

restrictions
1 ≤ T ≤ 100 000
For each pair, 2 ≤ a, b ≤ 2 * 10 9

Example
euclid2.in
3
12 42
21 7
9 10
euclid2.out
6
7
1
*/

use std::fs::File;
use std::io::{self, BufReader, Error, ErrorKind, Write, BufRead};

fn cmmdc(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }
    a
}

fn read(path: &str) -> Result<Vec<i64>, io::Error> {
    let file = File::open(path)?;
    let br = BufReader::new(file);

    let mut v = Vec::new();
    for line in br.lines() {
        let line = line?;

        for number_as_string in line.split_whitespace() {
            let n = number_as_string
                .parse()
                .map_err(|e| Error::new(ErrorKind::InvalidData, e))?;
            v.push(n);
        }
    }

    Ok(v)
}

fn main() {
    let v = read("euclid2.in");
    let mut fileout = File::create("euclid2.out").expect("Not being able to create file");

    match v {
        Ok(v) => {
//            let iterator = v.iter().skip(1);
//            for slice in iterator.collect::<Vec<&i64>>().chunks(2) {
//                println!("{}, {}", slice[0],slice[1]);

            for slice in v[1..].chunks_exact(2){
                writeln!(fileout, "{}", cmmdc(slice[0], slice[1]));
            }
        }
        Err(err) => { panic!("{}", err); }
    }
}