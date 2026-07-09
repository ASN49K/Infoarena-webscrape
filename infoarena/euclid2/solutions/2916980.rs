use std::fs;
use std::fs::File;
use std::io::prelude::*;

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn main() {
    println!("In file {}", "euclid2.in");
    let contents = fs::read_to_string("euclid2.in").expect("Something went wrong reading the file");

    let numbers: Vec<usize> = contents
        .split_whitespace()
        .collect::<Vec<&str>>()
        .iter()
        .map(|x| x.parse::<usize>().unwrap())
        .collect();

    let n = numbers[0];
    let mut f = File::create("euclid2.out").expect("Unable to create file");

    for i in 0..n {
        let gcd = gcd(numbers[i * 2 + 1], numbers[i * 2 + 2]);

        let data = gcd.to_string() + "\n";

        f.write_all(data.as_bytes()).expect("Unable to write data");
    }
}
