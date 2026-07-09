Program P1;
const nmax=1025;
var a,b,r : array[1..nmax] of integer;
    s : array[0..nmax,0..nmax] of integer;
    z,k,n,m,i,j : integer;
    f,g : text;

Function max(a,b : longint) : longint;
begin
if a>=b then exit(a) else exit(b);
end;



Procedure sufix;
begin
fillchar(s,sizeof(s),0);
 for i:=1 to m do
   for j:=1 to n do
 begin
 if a[i]=b[j] then
 s[i,j]:=s[i-1,j-1]+1
 else
 s[i,j]:=max(s[i-1,j],s[i,j-1]);
 if s[i,j]>z then z:=s[i,j];
 end;
end;







begin
assign(f,'cmlsc.in');
reset(f);
k:=1;
readln(f,m,n);
for i:=1 to m do
read(f,a[i]);
readln(f);
for i:=1 to n do
read(f,b[i]);
close(f);
sufix;
i:=m; j:=n;
repeat
  if a[i]=b[j] then
  begin
  r[k]:=a[i];
  inc(k);
  dec(i);
  dec(j);
  end
  else
  if s[i-1,j]>s[i,j-1] then
  dec(i) else dec(j);
until s[i,j]=0;




assign(g,'cmlsc.out');
rewrite(g);
writeln(g,z);
for i:=k-1 downto 1 do
write(g,r[i],' ');

close(g);
end.
