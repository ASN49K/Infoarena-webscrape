var t, a, b: byte;
    f, l: text;

begin
  assign(f, 'euclid2.in');
  reset(f);
  assign(l, 'euclid2.out');
  rewrite(l);

  read(f, t);
  while not eof(f) do
    begin
       read(f, a, b);
       repeat
          if a>b then a:=a-b
                 else b:=b-a;
       until a=b;
       writeln(l, a);
    end;

  close(l);
end.
