var
  a, b, c, n, d: longint;
  fout, fin: textfile;

begin
  assign(fin, 'euclid2.in');
  reset(fin);
  assign(fout, 'euclid2.out');
  rewrite(fout);
  readln(fin, n);
  while n + 1 > 1 do
  begin
    read(fin, a, b);
    while a <> b do
    begin
      if a > b then a := a - b;
      if b > a then b := b - a;
    end;
    writeln(fout, a);
    n := n - 1
  end;
  close(fin);
  close(fout);
end.
