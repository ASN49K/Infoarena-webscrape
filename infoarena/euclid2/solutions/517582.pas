var
	fi, fo : text;
	d, r, i, t, j : integer;
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
  	writeln (fo, d);
    end;
  close (fi); close (fo);
end.