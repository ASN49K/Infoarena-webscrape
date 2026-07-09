var t, x, y, i:longint;
    f, g:text;
    Buf1, buf2: array[1..100000] of Char;  { 4K buffer }


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
  while x <> y do
    begin
    if x>y then x:=x-y
           else y:=y-x;
    end;
  writeln (g, x);
  end;

close (f); close (g);
end.