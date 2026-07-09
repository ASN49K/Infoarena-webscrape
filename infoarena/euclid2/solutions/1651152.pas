var a,b,s,n,i,t,j:longint;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
reset(input);
rewrite(output);
read(t);
while t>0 do begin
read(a,b);
s:=0;
if a<=b then n:=a else n:=b;
for j:=1 to n do
if (a mod j=0)and(b mod j=0)then s:=j;
writeln(s);
t:=t-1;
end;
end. 