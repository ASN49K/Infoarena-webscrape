use std::fs;

fn euclid(a: i32, b: i32) -> i32 {
    if b == 0 {
        a
    }
    else {
        euclid(b, a % b)
    }
}

fn main() {
    let input = fs::read_to_string("euclid2.in").unwrap();
    let mut output = String::new();

    let mut it = input.split("\n");

    let n = it.next().unwrap().trim().parse::<i32>().unwrap();
    for _ in 0 .. n {
        let mut nit = it.next().unwrap().split(' ');
        let a = nit.next().unwrap().trim().parse::<i32>().unwrap();
        let b = nit.next().unwrap().trim().parse::<i32>().unwrap();
        output.push_str(&euclid(a, b).to_string());
        output.push('\n');
    }    

    _ = fs::write("euclid2.out", output);
}
