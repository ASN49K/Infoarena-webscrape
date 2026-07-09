program Cel_mai_lung_subsir_comun;
var a,b,c:array[1..1024]of byte;
    l:array[0..1024,0..1024]of integer;
    f:text;
    n,m,i,j,k:integer;
begin
assign(f,'cmlsc.in');reset(f);
readln(f,m,n);
for i:=1 to m do read(f,a[i]);
for i:=1 to m do read(f,b[i]);
close(f);
assign(f,'cmlsc.out');rewrite(f);
l[0,0]:=0;l[0,1]:=0;l[1,0]:=0;
for i:=1 to m do
 for j:=1 to n do
  if a[i]=b[j] then l[i,j]:=l[i-1,j-1]+1
               else if l[i-1,j]<l[i,j-1] then l[i,j]:=l[i,j-1]
                                         else l[i,j]:=l[i-1,j];
k:=l[m,n];
writeln(f,k);
for i:=m downto 1 do
 for j:=n downto 1 do
  if (l[i,j]=k)and(a[i]=b[j]) then begin
                                   c[k]:=a[i];
                                   k:=k-1;
                                   end;
for i:=1 to l[m,n] do write(f,c[i],' ');
close(f);
end.