program euklideszi;
var a,b,T,i,s:longint;
    f,g:text;

begin
assign(f,'euclid2.in');
reset(f);
readln(f,t);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to t do begin
read(f,a);
readln(f,b);
while b>0 do begin
s:=b;
b:=a mod b;
a:=s;
end;
writeln(g,a);
end;
close(f);
close(g);
end.
