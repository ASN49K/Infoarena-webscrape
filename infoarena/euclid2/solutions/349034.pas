var a,b,c,r:longint;
i,t:1..1000;
f,g:text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f); rewrite(g);
readln(f,t);
for i:=1 to t do begin
    read(f,a);readln(f,b);
if a>b then begin
       c:=b; b:=a; a:=c; end;
if b<>0 then
repeat
      c:=b; b:=a mod b; a:=c;
until b=0;
writeln(g,a);
end;
close(g);close(f); end.
