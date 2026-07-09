use std::fs;
use std::error::Error;
use std::fs::read_to_string;

pub fn solve(a: u64, b: u64) -> u64 {
    if a == 0 {
        b
    } else {
        solve(b % a, a)
    }
}

fn main() -> Result<(), Box<dyn Error>> {
    let result: Vec<String> = read_to_string("euclid2.in")?.lines().skip(1)
        .map(|line| line.trim().split_once(' ').expect("two numbers"))
        .map(|(xs, ys)| {
            let x = xs.parse::<u64>().unwrap();
            let y = ys.parse::<u64>().unwrap();
            format!("{}", solve(x, y))
        })
        .collect();
    let _ = fs::write("euclid2.out", result.join("\n"));

    Ok(())
}
