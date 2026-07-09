Program CMLSC;
type nl = 0..1024;
vect = array[nl] of char;
tab = array[nl,nl] of nl;
var a1,a2:vect;
n,m,i,s:nl;
b:tab;
f,g:text;
function max(a,b:nl):nl;
begin
if a<b then max:=b
else max:=a;
end;
procedure dp;
var i,j:nl;
begin
 for i:=1 to n do
  for j:=1 to m do begin
   if a1[i] = a2[j] then
     b[i,j]:=b[i-1,j-1]+1
    else b[i,j]:=max(b[i-1,j],b[i,j-1]);
   end;
end;
procedure scriere;
var i,j:nl;
sol:vect;
begin
i:=n;
j:=m;
while (i>0) and (j>0) and (s>0) do begin
 if b[i-1,j] = b[i,j-1] then begin
  sol[s]:=a1[i];
  dec(i);
  dec(j);
  dec(s);
 end else if b[i-1,j]>b[i,j-1] then
  dec(i)
  else dec(j);
 end;
for i:=1 to b[n,m] do
 write(g,sol[i]);
end;
begin
assign(f,'clmsc.in');
assign(g,'clmsc.out');
reset(f);
rewrite(g);
readln(f,n,m);
for i:=1 to n do read(f,a1[i]);
readln;
for i:=1 to m do read(f,a2[i]);
dp;
s:=b[n,m];
writeln(g,s);
scriere;
close(f);
close(g);
end.