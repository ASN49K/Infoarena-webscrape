program loc;
type tab=array [1..1000,1..1000] of longint;
var s:tab;
    t,a,b,j,i,c,r,h:longint;
	g,f:text;
	
procedure divi (a,b:longint; var s:tab; h:longint);
var i,x,y:longint;
begin
y:=b;
x:=a;
while x>=1 do begin
if a mod x=0 then inc(s[h,x]);
dec(x);
end;
while y>=1 do begin
if b mod y=0 then inc(s[h,y]);
dec(y);
end;
end;
begin
assign(g,'euclid2.in');
assign(f,'euclid2.out');
reset(g);
rewrite(f);
readln(g,t);
for i:=1 to t do begin
h:=i;
r:=0;
readln(g,a,b);
if a<=b then c:=a else c:=b;
divi(a,b,s,h);
for j:=1 to c do
if (s[i,j]=2) and (j>=r) then r:=j;
writeln(r);
end;	
close(g);
close(f);
end.