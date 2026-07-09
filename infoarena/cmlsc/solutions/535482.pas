type matrice=array[0..1025,0..1025] of integer;
     vector=array[0..1025] of byte;

var s:matrice;
    a,b,d:vector;
    n,m,nr:integer;

procedure citire;
var i:integer;
begin
assign(input,'cmlsc.in');reset(input);
 readln(n,m);
 for i:=1 to n do
  read(a[i]);
 for i:=1 to m do
  read(b[i]);
close(input);
end;

procedure du;
var i,j:integer;
begin
 for i:=1 to n do
  for j:=1 to m do
   if a[i]=b[j] then s[i,j]:=s[i-1,j-1]+1
                else begin
                 if s[i-1,j]> s[i,j-1] then s[i,j]:=s[i-1,j]
                                       else s[i,j]:=s[i,j-1]
                end;
end;

procedure sir(i,j:integer);
begin
nr:=0;
 repeat
  while s[i,j]=s[i-1,j] do
   dec(i);
  while s[i,j]=s[i,j-1] do
   dec(j);
  if a[i]=b[j] then begin
   inc(nr);
   d[nr]:=a[i];
  end;
  dec(i); dec(j);
 until (i=0) or (j=0);
end;

procedure scrie;
var i,j:integer;
begin
assign(output,'cmlsc.out');rewrite(output);
writeln(s[n,m]);
 for i:=nr downto 1 do
  write(d[i],' ');
close(output);
end;

begin
citire;
du;
sir(n,m);
scrie;
end.
