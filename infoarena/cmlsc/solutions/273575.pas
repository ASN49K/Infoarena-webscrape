var  f:text;
     s1,s2,sol:array[0..1024] of integer;
     a:array[0..1024,0..1024] of integer;
     i,j,n,m,r:integer;
begin
assign(f,'cmlsc.in');
reset(f);
readln(f,n,m);
for i:=1 to n do
 read(f,s1[i]);
readln(f);
for i:=1 to m do
 read(f,s2[i]);
close(f);
for i:=0 to n do
 for j:=0 to m do
  begin
   if (j=0) or (i=0) then
    a[i,j]:=0
    else
   if s1[i]=s2[j] then
    a[i,j]:=a[i-1,j-1]+1
    else
    if a[i-1,j]>=a[i,j-1] then
     a[i,j]:=a[i-1,j]
      else
     a[i,j]:=a[i,j-1];
  end;
r:=0;
assign(f,'cmlsc.out');
rewrite(f);
writeln(f,a[n,m]);
i:=n;
j:=m;
while a[i,j]<>0 do
 begin
  if s1[i]=s2[j] then
   begin
    r:=r+1;
    sol[r]:=s1[i];
    i:=i-1;
    j:=j-1;
   end
  ELSE
   if a[i-1,j]>=a[i,j-1] then
    i:=i-1
     else
    j:=j-1;
 end;
for i:=r downto 1 do
 write(f,sol[i],' ');
close(f);
end.
