var t, x, y, i:longint;
    Buf1, buf2: array[1..100000] of Char;  { 4K buffer }

    f, g:text;

function gcd(a, b:longint):longint;
  begin
  if b = 0 then gcd:=a
           else gcd:=gcd(b, a mod b);
  end;

begin
assign (f, 'euclid2.in');
settextbuf (f, buf1);
reset (f);
assign (g, 'euclid2.out');
settextbuf (g, buf2);
rewrite (g);
readln (f, t);
for i := 1 to t do
  begin
  readln (f, x, y);
  writeln (g, gcd(x, y));
  end;

close (f); close (g);
end.