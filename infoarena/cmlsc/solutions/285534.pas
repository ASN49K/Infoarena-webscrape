{cel mai lung subsir comun a doua subsiruri}

var a,b:array[1..1024] of byte;
    m,n:integer;
    f,g:text;
    c:array[0..1024,0..1024] of integer;

procedure citire;
var i:integer;
begin
assign(f,'cmlsc.in'); reset(f);
readln(f,m,n);
for i:=1 to m do read(f,a[i]);
for i:=1 to n do read(f,b[i]);
close(f);
end;

function maxim(x,y:integer):integer;
var max:integer;
begin
max:=x;
if y>max then max:=y;
maxim:=max;
end;


procedure afisare(i,j:integer);
begin
while a[i]<>b[j] do
      if c[i,j-1]<c[i-1,j] then dec(i)
                           else dec(j);
if c[i-1,j-1]>0 then afisare(i-1,j-1);
write(g,a[i],' ');
end;

procedure rezolvare;
var i,j:integer;
begin
assign(g,'cmlsc.out'); rewrite(g);

for i:=1 to m do
    for j:=1 to n do c[i,j]:=0;

for i:=1 to m do
    for j:=1 to n do
        if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
                     else c[i,j]:=maxim(c[i-1,j],c[i,j-1]);

writeln(g,c[m,n]);
afisare(m,n);
close(g);
end;

begin
citire;
rezolvare;
end.