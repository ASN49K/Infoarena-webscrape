Program Euclid;
var T,i:1..100000;
A,B,C: 2..2000000000{array [1..100000,1..2] of 2..2000000000;};
f,g: text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,T);
for i:=1 to t do begin 
  readln(f,A,B);
  C:= A mod B;
 while C <> 0 do begin
  C:= A mod B;
  A:= B;
  B:= C;
 end;
 writeln(g,B);
end;
{ 
if A[i,1] < A[i,2] then begin
 B:=A[1,1];
 A[1,1]:= A[1,2];
 A[1,2]:= B;
 end;}
 close(f);
 close(g);
end.