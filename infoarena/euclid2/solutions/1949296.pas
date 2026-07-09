Program Euclid;
var T,i:1..100000;
j:1..2;
A: array [1..100000,1..2] of 2..2000000000;
b:2..2000000000;
f,g: text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,T);
for i:=1 to t do begin
 for j:=1 to 2 do 
  read(f,A[i,j]);
 readln(f);
end;
{ 
if A[i,1] < A[i,2] then begin
 B:=A[1,1];
 A[1,1]:= A[1,2];
 A[1,2]:= B;
 end;}
 for i:=1 to t do begin
  while A[i,1] mod A[i,2] <> 0 do begin
  B:= A[i,1] mod A[i,2];
  A[i,1]:= A[i,2];
  A[i,2]:= B;
 end;
 writeln(g,A[i,2]);
 end;
 close(f);
 close(g);
end.