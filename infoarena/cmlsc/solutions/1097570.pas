type tab=array[1..1050] of longint;
var a,b:text;
	u,t,s:tab;
	x,y,i,z,mx:longint;

function max(a,b:longint):longint;
begin
if a>b then max:=a else max:=b;
end;

function min(a,b:longint):longint;
begin
if a<b then min:=a else min:=b;
end;

function f(m,n:longint):longint;
begin
if (m>0) and (n>0) then 
if t[m]=u[n] then
begin
	f:=f(m-1,n-1)+1;
	if f>mx then
	begin
		mx:=f;
		s[mx]:=t[m];
	end;
end else
f:=max(f(m-1,n),f(m,n-1)) else
f:=0;
end;

begin
assign(a,'cmlsc.in');
reset(a);
assign(b,'cmlsc.out');
rewrite(b);
readln(a,x,y);
for i:=1 to x do
read(a,t[i]);

for i:=1 to y do
read(a,u[i]);

mx:=0;

z:=f(x,y);

writeln(b,z);
for i:=1 to z do
write(b,s[i],' ');

close(a);
close(b);
end.
