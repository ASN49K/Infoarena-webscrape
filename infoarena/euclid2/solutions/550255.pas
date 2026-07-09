var t, x, y, i:longint;
    f, g:text;

function gcd(a, b:longint):longint;
  begin
  if b = 0 then gcd:=a
           else gcd:=gcd(b, a mod b);
  end;

begin
assign (f, 'euclid2.in'); reset (f);
assign (g, 'euclid2.out'); rewrite (g);
readln (f, t);
for i := 1 to t do
  begin
  readln (f, x, y);
  writeln (g, gcd(x, y));
  end;

close (f); close (g);
end.