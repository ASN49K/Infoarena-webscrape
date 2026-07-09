Program cmlsc;
var a,b,r : array[1..2000] of integer;
    n,m,rz,k : integer;
   s : array[0..2000,0..2000] of integer;
   fout : text;
Function max(x,y : integer) : integer;
begin
if x>y then max:=x else max:=y;
end;


Procedure citire;
var fin : text;
    i : integer;

begin
assign(fin,'cmlsc.in');
reset(fin);
readln(fin,n,m);
for i:=1 to n do
read(fin,a[i]); readln(fin);
for i:=1 to m do
read(fin,b[i]);
close(fin);
end;

Procedure suf;
var i,j : integer;

begin
{fillchar(s,sizeof(s),0);  }
rz:=0;
for i:=1 to n do
 for j:=1 to m do
   begin
   if a[i]=b[j] then s[i,j]:=s[i-1,j-1]+1 else
   s[i,j]:=max(s[i-1,j],s[i,j-1]);
   if s[i,j]>rz then rz:=s[i,j];
   end;
i:=n; j:=m;
k:=1;
repeat
 if a[i]=b[j] then
    begin
    r[k]:=a[i];
    inc(k);
    dec(i); dec(j);
    end
    else
 if s[i-1,j]>s[i,j-1] then dec(i) else dec(j);
until s[i,j]=0;
dec(k);
assign(fout,'cmlsc.out');
rewrite(fout);
writeln(fout,rz);
for i:=k downto 1 do write(fout,r[i],' ');
close(fout);
end;



begin

citire;
suf;

end.
