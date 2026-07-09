var a : array[1..10, 1..10 ] of integer;

  i, j : integer;


begin
for i:=1 to 10 do
for j:=1 to 6  do
a[i,j]:=0;

for i:=1 to 10 do a[i,2]:=5;

for i:=1 to 10 do
begin
for j:=1 to 6 do
write(a[i,j],' ');
writeln;
end;

readln;
end.