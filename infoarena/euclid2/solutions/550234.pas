var t, x, y, i:longint;
    f, g:text;

begin
assign (f, 'euclid2.in'); reset (f);
assign (g, 'euclid2.out'); rewrite (g);
readln (f, t);
for i := 1 to t do
  begin
  readln (f, x, y);
  while x <> y do
    begin
    if x>y then x:=x-y
           else y:=y-x;
    end;
  writeln (g, x);
  end;

close (f); close (g);
end.