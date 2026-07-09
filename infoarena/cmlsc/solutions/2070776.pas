Program clmsc;
type  ma = 0..2000;
 tab = array [ma,ma] of ma;
 sir = array [ma] of ma;
var a,b,s:sir;
m,n,i,nr:ma;
f,g:text;
function move(a,b:integer):boolean;
begin
 if a <= b then
  move:=false
  else move:=true;
end;
function max(a,b:integer): integer;
begin
 if a >= b then
  max:=a
  else
  max:=b;
end;
Procedure tabulare(a,b:sir; var s:sir; var nr:ma);
var sudoku:tab;
i,j,num:ma;
ba:boolean;
begin
 for i:=1 to m do
 for j:=1 to n do
  if a[i] = b[j] then begin
   if (i>1) and (j>1) then
    sudoku[i,j]:= sudoku[i-1,j] + 1
    else
    sudoku[i,j]:=1;
   end else sudoku[i,j]:=max (sudoku[i-1,j],sudoku[i,j-1]);
   nr:=sudoku[i,j];
   num:=nr;
   {for j:=1 to n do begin
   writeln;
   for i:=1 to m do
    write(sudoku[i,j],' ');
   end;}
 while (i>0)and(j>0) do begin
  ba:=move(sudoku[i,j],sudoku[i-1,j-1]);
   i:=i-1;
   if ba then begin
      j:=j-1;
      s[num]:= a[i+1];
      num:=num-1;
      end;
 end;
end;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
readln(f,m,n);
for i:=1 to m do
 read(f,a[i]);
readln(f);
for i:=1 to n do
 read(f,b[i]);
tabulare(a,b,s,nr);
writeln(g,nr);
for i:=1 to nr do
 write(g,s[i],' ');
close(f);close(g);
end.