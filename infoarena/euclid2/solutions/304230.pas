var a, b, c: longint;
    t, i: longint;
    f, g: text;
begin
  assign(f, 'euclid.in');
  assign(g, 'euclid.out');
  reset(f);
  rewrite(g);
  readln(f, t);
  for i := 1 to t do begin
    readln(f, a, b);
    while (b <> 0) do begin
      c := a mod b;
      a := b;
      b := c;
    end;
    writeln(g, a);
  end;
  close(f);
  close(g);
end.