var t, n, m, s, i, j, x:longint;
    f, g:text;

begin
assign (f, 'nim.in'); reset (f);
assign (g, 'nim.out'); rewrite (g);

read (f, n);
for i := 1 to n do
  begin
  read (f, m);
  s:=0;
  for j := 1 to m do begin read (f, x); s:= s XOR x; end;
  if s=0 then writeln (g, 'NU') else writeln (g, 'DA');
  end;

close (f); close (g);
end.