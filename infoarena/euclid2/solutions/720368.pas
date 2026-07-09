var f,g:text;a,m,b:real;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f);
while not eof(f) do begin
readln(f,a,b);
if a<b then begin m:=a; a:=b; b:=m;end;
while frac(a / b) <> 0 do
b:=b / 2;
if trunc(b)<>0 then
writeln(g,trunc(b))  else write(g,1);
end;
close(f);close(g);
end.
