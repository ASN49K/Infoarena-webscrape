Program AE2;
var t1,t2 : text;
    a : array[0..1000,0..1000] of byte;
    s1,s2,sf : array[1..1000] of integer;
    i,j,l1,l2,max,cont,k : integer;

begin
assign(t1,'cmlsc.in');
reset(t1);
read(t1,l2);
read(t1,l1);

for i:=1 to l2 do read(t1,s2[i]);
for i:=1 to l1 do read(t1,s1[i]);

close(t1);

for i:=0 to l1 do
for j:=0 to l2 do
a[i,j]:=0;

for i:=1 to l1 do
for j:=1 to l2 do
begin

if a[i-1,j]>a[i,j-1] then max:=a[i-1,j] else max:=a[i,j-1];

if s1[i]=s2[j] then a[i,j]:=a[i-1,j-1]+1 else a[i,j]:=max;

end;



 i:=l1; j:=l2; k:=0;
 while a[i,j]>0 do
  begin
   while s1[i]<>s2[j] do
    begin
     if a[i,j-1]<a[i-1,j] then dec(i) else dec(j);
    end;
   inc(k);
   sf[k]:=s1[i];
   dec(i); dec(j);
  end;




assign(t2,'cmlsc.out');
rewrite(t2);
writeln(t2,a[l1,l2]);
 for i:=k downto 1 do write(t2,sf[i],' ');
close(t2);
end.