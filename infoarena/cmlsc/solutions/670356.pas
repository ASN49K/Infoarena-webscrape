{ ... Leghosszabb kozos reszsorozat ... }

var x,y:array[1..1030] of longint;
    c:array[0..1030,0..1030] of longint;
    n,m,i:longint;
    f:text;

function szamol(n,m:longint):longint;
var i,j:longint;
begin
 for i:=1 to n do
  c[i,0]:=0;
 for j:=1 to m do
  c[0,j]:=0;
 for i:=1 to n do
  for j:=1 to m do
   if (x[i]=y[j]) then c[i,j]:=c[i-1,j-1]+1
   else if (c[i,j-1]>c[i-1,j]) then c[i,j]:=c[i,j-1]
        else c[i,j]:=c[i-1,j];
 szamol:=c[n,m];
end;

procedure keres(i,j:longint);
begin
 if (i<>0) and (j<>0) then begin
  if (x[i]=y[j]) then begin
   keres(i-1,j-1);
   write(f,x[i],' ');
  end
  else if (c[i,j-1]>c[i-1,j]) then keres(i,j-1)
       else keres(i-1,j);
 end;
end;

begin
assign(f,'cmlsc.in');
reset(f);
readln(f,n,m);
for i:=1 to n do
 read(f,x[i]);
readln(f);
for i:=1 to m do
 read(f,y[i]);
close(f);

assign(f,'cmlsc.out');
rewrite(f);
writeln(f,szamol(n,m));
keres(n,m);
close(f);
end.