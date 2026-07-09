program asdf;
type mat=array[0..10,0..10] of integer;
        vect=array[1..10] of integer;
var v1,v2,z:vect;
   n,m:integer;
   g:text;
   k,i,j:integer;
   ma:mat;

   f:text;
begin
assign(f,'cmlsc.in');
reset(f);
readln(f,n,m);
write(n);
write(m);

for i:=1 to n do read(f,v1[i]);
for i:=1 to m do read(f,v2[i]);

k:=1;
for i:=1 to n do
   for j:=1 to m do
      if (v1[i]=v2[j]) then  ma[i,j]:=ma[i-1,j-1]+1
      else if (ma[i-1,j]<ma[i,j-1]) then ma[i,j]:=ma[i,j-1]
                                  else ma[i,j]:=ma[i-1,j];

close(f);
i:=n;
j:=m;
while (i>=1 ) and (j>=1) do
   if v1[i]=v2[j] then begin
   z[k]:=v1[i];
   i:=i-1;
   j:=j-1;
   k:=k+1;end
   else
   if ma[i-1,j]>ma[i,j-1] then i:=i-1
   else
   j:=j-1;
assign(g,'cmlsc.out');
rewrite(g);
for i:=k-1 downto 1 do
write(g,z[i],' ');
writeln;
close(g);
end.


