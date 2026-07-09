program euklideszi;
var a,b,T,i:longint;
    f,g:text;

function euklideszi(a,b:longint):longint;

begin
while a<>b do begin
if a>b then a:=a-b
       else if a<b then b:=b-a;
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
