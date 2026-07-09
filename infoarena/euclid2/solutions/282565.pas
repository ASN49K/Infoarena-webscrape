type intreg=array[1..3] of int64;
var vector:^intreg; i,n:longint;
begin
new (vector);
assign (input,'euclid2.in');
reset (input);
readln (input,n);
assign (output,'euclid2.out');
rewrite (output);
for i:=1 to n do
begin
read (input,vector^[1]);
read (input,vector^[2]);
if vector^[1]=1 then
writeln (output,vector^[2]);
if vector^[2]=1 then
writeln (output,vector^[1]);
if vector^[1]<vector^[2] then
begin
vector^[3]:=vector^[2];
vector^[2]:=vector^[1];
vector^[1]:=vector^[3];
end;
while vector^[2]<>0 do
begin
vector^[3]:=vector^[1] mod vector^[2];
vector^[1]:=vector^[2];
vector^[2]:=vector^[3];
end;
if vector^[1]=1 then
writeln (output,1)
else
writeln (output,vector^[1]);
end;
close (input);
close (output);
dispose (vector);
end.
