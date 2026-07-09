program cmlsc;

const max=1024;
var l1,l2,sol:array[1..max] of byte;
    v:array[0..max,0..max] of integer;
    fin,fout:text;
    i,j,k,n,m:integer;

begin
assign(fin,'cmlsc.in');
reset(fin);
assign(fout,'cmlsc.out');
rewrite(fout);

readln(fin,m,n);
for i:=1 to m do read(fin,l1[i]);
readln(fin);
for i:=1 to n do read(fin,l2[i]);
close(fin);


for i:=1 to m do
 for j:=1 to n do
  if l1[i]=l2[j] then
     v[i,j]:=v[i-1,j-1]+1
     else
      if v[i-1,j]>v[i,j-1] then v[i,j]:=v[i-1,j]
        else
          v[i,j]:=v[i,j-1];

writeln(fout,v[m,n]);
i:=m; j:=n;
k:=v[m,n];

while k>0 do
begin
if v[i,j]=v[i-1,j-1]+1 then
  begin
   sol[k]:=l1[i]; k:=k-1; i:=i-1; j:=j-1;
   end
  else
    if v[i,j]=v[i-1,j] then i:=i-1
     else  j:=j-1;
end;

for i:=1 to v[m,n] do
write(fout,sol[i],' ');
close(fout);


end.
