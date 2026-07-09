{Program Euclid;
var A,B,C,i,t: Longint;
f,g: text;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,T);
if A < B then begin
 C:= A;
 A:= B;
 B:= C;
 end;
for i:=1 to t do begin
 read(f,A,B);
 while B <> 0 do begin
  C:= A mod B;
  A:= B;
  B:= C;
  end;
 writeln(g,A);
end;
 close(f);
 close(g);
end.
var f,g:text;
    n,a,b,i:longint;

function cmmdc(a,b:longint):longint;
var cm,k: integer;
Begin
 cm:= b;
  while (a mod b) <> 0 do begin
  k:= a mod b;
  a:= b; cmmdc(b,a mod b);
  b:= k;
  cm:= b;
  end;
cmmdc:= cm;
end;
Begin
Assign(f,'euclid2.in');Reset(f);
Assign(g,'euclid2.out');Rewrite(g);
Readln(f,n);
For i:=1 to n do
 Begin
  Readln(f,a,b);
  Writeln(g,cmmdc(a,b));
 end;
Close(f);
Close(g);
end.}
Program Euclid;
type max = 0..2000000000;
var i,n,a,b,r : max;
f,g :text;
function cmmdc(var a,b : max): max;//Cel mai mare divizor comun
begin
r := a mod b;
while (b mod r) <> 0 do begin
  a:= b;
  b:= r;
  r:= a mod b;
 end;
cmmdc:= r;
end;
begin
Assign(f,'euclid2.in');Reset(f);
Assign(g,'euclid2.out');Rewrite(g);
readln(f,n);
for i := 1 to n do begin
 readln(f,A,B);
 writeln(g,cmmdc(a,b));
 end;
Close(f);
Close(g);
end.
