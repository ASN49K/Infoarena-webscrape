use std::error::Error;
use std::fs::File;
use std::io::{BufRead, BufReader, Write};

fn main() -> Result<(), Box<dyn Error> > {
    let mut fin = BufReader::new(File::open("euclid2.in")?);
    let mut fout = File::create("euclid2.out")?;


    let mut ib = String::new();
    
    fin.read_line(&mut ib)?;
    let t = ib.trim().parse::<usize>()?;

    for _i in 0..t {
        ib.clear();
        fin.read_line(&mut ib)?;
        let mut input = ib.split_whitespace();
        let mut a = input.next().unwrap().parse::<i32>().unwrap();
        let mut b = input.next().unwrap().parse::<i32>().unwrap();

        while b != 0 {
            let r = a % b;
            a = b;
            b = r;
        }
        fout.write_fmt(format_args!("{}\n", a))?;
    }

    Ok(())
}
