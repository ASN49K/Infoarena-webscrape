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
    if(( a <= 2) or (b <= 2)) then break;

    while (b <> 0) do begin
      c := a mod b;
      a := b;
      b := c;
    end;
    if( a <> 0) then writeln(g, a)
    else writeln(g, 1);

  end;
  close(f);
  close(g);
end.