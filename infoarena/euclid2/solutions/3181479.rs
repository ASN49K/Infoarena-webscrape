use std::error::Error;
use std::fs::read_to_string;
use std::fs::File;
use std::io::Write;

pub fn solve(a: u64, b: u64) -> u64 {
    if a == 0 {
        b
    } else {
        solve(b % a, a)
    }
}

fn main() -> Result<(), Box<dyn Error>> {
    let mut buffer = File::create("euclid2.out")?;

    let _ = read_to_string("euclid2.in")?.lines().skip(1)
        .map(|line| line.trim().split_once(' ').expect("two numbers"))
        .map(|(xs, ys)| {
            let x = xs.parse::<u64>().unwrap();
            let y = ys.parse::<u64>().unwrap();
            format!("{}\n", solve(x, y))
        })
        .for_each(|s| { let _ = buffer.write(s.as_bytes()); });

    Ok(())
}
