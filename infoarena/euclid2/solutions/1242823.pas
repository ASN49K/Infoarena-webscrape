program Euclid;

var
  fi, fo: text;
  a, b, i, j, n: longint;

begin
  assign(fi, 'euclid2.in'); reset(fi);
  assign(fo, 'euclid2.out'); rewrite(fo);
  readln(fi, n);
  for i := 1 to n do
  begin
    readln(fi, a, b);
    while b <> 0 do
    begin
      j := a mod b;
      a := b;
      b := j;
    end;
    writeln(fo, a);
  end;
  close(fi);
  close(fo);
end.
