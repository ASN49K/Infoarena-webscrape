type vector=array[1..100] of integer;
var v1,v2,vc:vector;
f,f1:text;
n,m,i,j,k,s:integer;
begin
k:=0;
assign (f,'cmlsc.in');
assign (f1,'cmlsc.out');
reset (f);
rewrite (f1);
read (f,m);
readln (f,n);
for i:=1 to m-1 do
read (f,v1[i]);
readln (f,v1[i+1]);
for j:=1 to n do
read (f,v2[j]);
for i:=1 to m do
    for j:=1 to n do
        if v1[i]=v2[j] then
        begin
        inc (k);
        vc[k]:=v1[i];
        end;
writeln (f1,k);
for s:=1 to k do
begin
write (f1,vc[s]);
write (f1,' ');
end;
close (f);
close (f1);
end.