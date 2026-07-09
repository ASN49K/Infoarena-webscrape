Program P1;
var a,b,r : array[1..1500] of longint;
    s : array[0..1500,0..1500] of longint;
    z,k,n,m,i,j : integer;
    f,g : text;

Function max(a,b : longint) : longint;
begin
if a>=b then exit(a) else exit(b);
end;



Procedure sufix;
begin
z:=0;
fillchar(s,sizeof(s),0);
k:=1;
for i:=1 to m do
 for j:=1 to n do
 begin
 if a[i]=b[j] then
 begin
 s[i,j]:=s[i-1,j-1]+1;
 r[k]:=a[i];
 inc(k);
 end
 else
 s[i,j]:=max(s[i-1,j],s[i,j-1]);
 if s[i,j]>z then begin z:=s[i,j]; end;
 end;
end;







begin
assign(f,'cmlsc.in');
reset(f);
readln(f,m,n);
for i:=1 to m do
read(f,a[i]);
readln(f);
for i:=1 to n do
read(f,b[i]);
close(f);
sufix;
assign(g,'cmlsc.out');
rewrite(g);
writeln(g,z);
for i:=1 to k-1 do
write(g,r[i],' ');
end.
