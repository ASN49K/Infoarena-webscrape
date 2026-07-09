type vector=array[1..1024]of byte;
     matrice=array[0..1024,0..1024]of integer;
const max:integer=0;
var m,n,i,j:integer;
    a,b,c:vector;
    d:matrice;

function maxim(a:integer):integer;
var b:integer;
begin
maxim:=0;
for b:=1 to a do if d[i-1,b]>maxim then maxim:=d[i-1,b];
end;

begin
assign(input,'cmlsc.in');
reset(input);
assign(output,'cmlsc.out');
rewrite(output);
readln(m,n);
for i:=1 to m do read(a[i]);
for i:=1 to n do read(b[i]);
for i:=1 to m do
  for j:=1 to n do
    if a[i]=b[j] then d[i,j]:=maxim(j-1)+1
                 else d[i,j]:=d[i-1,j];
for i:=n downto 1 do if d[m,i]>max then begin
                                        max:=d[m,i];
                                        j:=i;
                                        end;
writeln(max);
i:=max;
repeat
if d[m,j]=i then begin
                 c[i]:=b[j];
                 dec(i);
                 end;
dec(j);
until i=0;
for i:=1 to max do write(c[i],' ');
close(input);
close(output);
end.
