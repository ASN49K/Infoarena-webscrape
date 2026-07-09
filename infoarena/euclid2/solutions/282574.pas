type intreg=array[1..3] of int64;
var vector:intreg; ok:boolean;
begin
assign (input,'euclid2.in');
reset (input);
readln (input);
assign (output,'euclid2.out');
rewrite (output);
while not seekeof(input) do
begin
ok:=true;
read (input,vector[1]);
read (input,vector[2]);
if vector[1]=1 then
begin
writeln (output,vector[2]);
readln (input,vector[1],vector[2]);
end;
if vector[2]=1 then
begin
writeln (output,vector[1]);
readln (input,vector[1],vector[2]);
end;
if vector[1]<vector[2] then
while vector[2]<>0 do
begin
vector[3]:=vector[1] mod vector[2];
vector[1]:=vector[2];
vector[2]:=vector[3];
end
else
while vector[1]<>0 do
begin
vector[3]:=vector[2] mod vector[1];
vector[2]:=vector[1];
vector[1]:=vector[3];
end;
if vector[1]=1 then
writeln (output,1)
else
if vector[1]=0 then
writeln (output,vector[2])
else
writeln (output,vector[1]);
end;
close (input);
close (output);
end.
