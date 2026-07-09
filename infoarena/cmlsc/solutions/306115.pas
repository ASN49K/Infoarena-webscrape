type vector=array[1..1024]of byte;
     matrice=array[0..1024,0..1024]of integer;
const max:integer=0;
var m,n,i,j:integer;
    a,b,c:vector;
    d:matrice;

function maxim(a,b:integer):integer;
begin
if a>b then maxim:=a
       else maxim:=b;
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
    if a[i]=b[j] then d[i,j]:=d[i-1,j-1]+1
                 else if d[i-1,j]>d[i,j-1]then d[i,j]:=d[i-1,j]
                                          else d[i,j]:=d[i,j-1];
i:=m;
j:=n;
m:=0;
repeat
if a[i]=b[j] then begin
                  inc(m);
                  c[m]:=a[i];
                  dec(i);
                  dec(j);
                  end
             else if d[i-1,j]<d[i,j-1]then dec(j)
                                      else dec(i);

until i*j=0;
writeln(m);
for i:=m downto 1 do write(c[i],' ');
close(input);
close(output);
end.
