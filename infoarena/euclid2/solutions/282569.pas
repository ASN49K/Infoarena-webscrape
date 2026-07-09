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
ok:=false;
end;
if vector[2]=1 then
begin
writeln (output,vector[1]);
ok:=false;
end;
if (vector[1]<vector[2])and ok then
begin
vector[3]:=vector[2];
vector[2]:=vector[1];
vector[1]:=vector[3];
end;
while (vector[2]<>0)and ok do
begin
vector[3]:=vector[1] mod vector[2];
vector[1]:=vector[2];
vector[2]:=vector[3];
end;
if (vector[1]=1)and ok then
writeln (output,1)
else
if ok then
writeln (output,vector[1]);
end;
close (input);
close (output);
end.
