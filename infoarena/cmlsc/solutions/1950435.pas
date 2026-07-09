Program Cmlsc;
type tab = array[0..256,0..256] of 0..256;
vect = array[byte] of 1..1024;
var A,B:vect;
C:tab;
sir,l: string;
n,m,i,j,nr: byte;
f,g:text;
function max (a,b:integer): integer;
 begin
  if a > b then
  max := A
  else
   max:= B;
  end;
{function backtrack (C:tab;X,Y:vect;i,j:byte) : string;
begin
while (i <> 0) and (j<>0) do
begin
if X[i] = Y[j] then begin
  str(X[i],l);
  b := l + ' ' + b;
  i:= i - 1;
  j:= j - 1;
  end
  else
  if C[i,j-1] > C[i-1,j] then
   j:= j - 1
   else
   i:= i - 1;
    if (i = 0) or (j = 0) then
        exit
    else if  X[i] = Y[j] then begin
        backtrack(C, X, Y, i-1, j-1);
        write(g,X[i],' ');
        exit;
        end
    else
        if C[i,j-1] > C[i-1,j] then
            backtrack(C, X, Y, i, j-1)
        else
            backtrack(C, X, Y, i-1, j);
end;}
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
readln(f,n,m);
for i:=1 to n do
 read(f,A[i]);
readln(f);
for i:=1 to m do
 read(f,B[i]);
{
writeln(g,C[n,m],' ');
writeln(g,backtrack(C,A,B,n,m));}
for i:=1 to n do 
 for j:=1 to m do begin
  if A[i] = B[j] then
   C[i,j]:= C[i - 1,j - 1] + 1
   else
   C[i,j]:= max(C[i,j-1],C[i-1,j]);
  end;
j:= m;
i:= n;
while (i > 0) and (j > 0) do begin
 if A[i] = B[j] then begin
 nr:= nr + 1;
 str(A[i],l);
 sir:= sir + l;
 i:= i - 1;
 j:=j - 1;
 end else if (C[i-1][j] < C[i][j-1]) then
            j:=j-1
        else
            i:=i-1;
end;
writeln(g,nr);
for i:= nr downto 1 do
 write(g,sir[i],' ');
close(f);
close(g);
end.
