var f,g:text;
a,b,i,n:longint;

function cmmdc(a,b:integer):integer;
begin
while a<>b do
if a>b then a:=a-b else b:=b-a;
cmmdc:=a;
end;

begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
readln(f,n);
for i:=1 to n do begin
readln(f,a,b);
writeln(g,cmmdc(a,b));
       end;
close(g);
close(f);
end.
