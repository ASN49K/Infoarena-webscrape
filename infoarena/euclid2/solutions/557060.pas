var
	fi, fo : text;
	d, r, i, t, j, a, b : longint;
begin
	assign (fi, 'euclid2.in'); reset (fi);
  assign (fo, 'euclid2.out'); rewrite (fo);
  readln (fi, t);
  for j := 1 to t do
    begin
		  readln (fi, d, i);
		  repeat
        r := d mod i;
			  d := i; i := r;
  	  until r = 0;
      repeat
      	b := a mod i;
        a := i; i := b;
      until b = 0;
  	  writeln (fo, b);
    end;
  close (fi); close (fo);
end.