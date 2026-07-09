program euklideszi;
var a,b,T,i,s:longint;
    f,g:text;

function euklideszi(a,b:longint):longint;

begin
while b>0 do begin
s:=b;
b:=a mod b;
a:=s;
end;
euklideszi:=a;
end;

begin
assign(f,'euclid2.in');
reset(f);
readln(f,t);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to t do begin
read(f,a);
readln(f,b);
writeln(g,euklideszi(a,b));
end;
close(f);
close(g);
end.
