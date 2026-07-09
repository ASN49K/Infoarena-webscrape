type matrice=array[-1..1027,-1..1027] of integer;
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
  readln;
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
  while (i>0) and (j>0) and (s[i,j]>0) do begin
   while s[i,j]=s[i-1,j] do
    dec(i);
   while s[i,j]=s[i,j-1] do
    dec(j);
   if a[i]=b[j] then begin
   inc(nr);
   d[nr]:=a[i];
  end;
  dec(i); dec(j);
{ until (i=0) or (j=0);}
  end;
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

procedure wr;
var i,j:integer;
begin
assign(output,'cmlsc.out');rewrite(output);
 for i:=1 to n do begin
  write(i:2,': ');
  for j:=1 to m do
   write(s[i,j]:2,' ');
  writeln;
 end;
close(output);
end;

begin
citire;
du;
wr;
if s[n,m]<>0 then begin
 sir(n,m);
 scrie
end else write(0);
end.
