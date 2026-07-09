use std::fs::File;
use std::io::{*};

fn solve_test_case(input : &mut BufReader<File>) -> String {
    let mut line = String::new();
    input.read_line(&mut line).unwrap();
    let _n : usize = line.trim().parse().unwrap();

    let mut line = String::new();
    input.read_line(&mut line).unwrap();
    let answer : i32 = line.trim().split(" ").map(|x| x.parse::<i32>().unwrap()).fold(0, |acc, x| acc ^ x);

    if answer != 0 {
        "DA".to_string()
    }
    else {
        "NU".to_string()
    }
}

fn main() {
    let mut input = BufReader::new(File::open("nim.in").unwrap());
    let mut output = BufWriter::new(File::create("nim.out").unwrap());

    let mut line = String::new();
    input.read_line(&mut line).unwrap();
    let testcases : usize = line.trim().parse().unwrap();

    for _i in 0..testcases {
        writeln!(output, "{}", solve_test_case(&mut input)).unwrap();
    }
}
