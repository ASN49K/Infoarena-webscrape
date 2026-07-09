var t:array[0..1030,0..1030] of integer;
    a,b,x:array[1..1030] of integer;
    n,m,i,j,k:integer;

 function mx(x,y:integer):integer;
  begin
   mx:=x;
   if y>mx then mx:=y
  end;

begin
assign(input,'cmlsc.in'); reset(input);
assign(output,'cmlsc.out'); rewrite(output);
readln(n,m);
for i:=1 to n do read(a[i]);
for i:=1 to m do read(b[i]);
for i:=1 to n do
 for j:=1 to m do
  if a[i]=b[j] then t[i,j]:=1+t[i-1,j-1] else t[i,j]:=mx(t[i-1,j],t[i,j-1]);
while (i>0) and (j>0) do
 begin
  if a[i]=b[j] then
   begin
    inc(k);
    x[k]:=a[i];
    dec(i);
    dec(j)
   end else
  if t[i-1,j]>t[i,j-1] then dec(i) else dec(j)
 end;
writeln(t[n,m]);
for i:=k downto 1 do write(x[i],' ');
close(input);
close(output)
end.
