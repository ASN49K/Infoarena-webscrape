var maxv,st,c1,c2,v1,v2:array[1..1024] of integer;
    k,i,n,m,max:integer;
    f,g:text;
procedure load;
begin
assign(f,'cmlsc2.in');
reset(f);
readln(f,n,m);
for i:=1 to n do
read(f,v1[i]);
readln(f);
for i:=1 to m do
read(f,v2[i]);
closE(f);
assign(g,'cmlsc2.out');
rewrite(g);
end;
procedure init_st;
var i:integer;
begin
for i:=1 to 1024 do
st[i]:=0;
k:=0;
end;

BEGIN
load;
init_st;
for i:=1 to n do
c1[v1[i]]:=1;

for i:=1 to m do
c2[v2[i]]:=1;
max:=-1;
i:=1;
while i<=256 do
begin
if (c1[i]=c2[i]) and (c2[i]=1) and (c1[i]=1) then
begin
init_st;
while (c1[i]=1) and (c2[i]=1) do
begin
 k:=k+1;
 st[k]:=i;
 i:=i+1;
 if max<k then
 begin
 max:=k;
 maxv:=st;
 end;
end;
end;
i:=i+1;
end;
write(g,k);
writeln(g);
for i:=1 to k do
write(g,st[i],' ');
close(g);
END.