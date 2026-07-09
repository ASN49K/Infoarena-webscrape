Program AE2;
var t1,t2 : text;
    a : array[0..256,0..256] of byte;
    s1,s2,sf : array[1..256] of integer;
    i,j,l1,l2,max,cont : integer;

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

if s1[i]=s2[j] then a[i,j]:=max+1 else a[i,j]:=max;

end;

cont:=1;
for i:=1 to l1 do
for j:=1 to l2 do

if a[i,j]=cont then begin
                    sf[cont]:=s1[i];
                    cont:=cont+1;
                    end;
cont:=cont-1;

assign(t2,'cmlsc.out');
rewrite(t2);
writeln(t2,cont);
for i:=1 to cont do write(t2,sf[i],' ');
close(t2);
end.