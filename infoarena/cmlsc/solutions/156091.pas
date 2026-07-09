program cmlsc;
var x,y:array[1..1024]of integer;
    c,b:array[0..1024,0..1024]of integer;
    n,m,i,j:integer;
    g:text;
procedure citire;
var f:text;
begin
assign(f,'cmlsc.in');reset(f);
read(f,n,m);
for i:=1 to n do read(f,x[i]);
for i:=1 to m do read(f,y[i]);
close(f);
end;
procedure scrie(i,j:integer);
begin
if (i<>0)and(j<>0) then
    if x[i]=y[j] then
                begin
                scrie(i-1,j-1);
                write(g,x[i],' ');
                end
                else if c[i-1,j]>c[i,j-1] then scrie(i-1,j)
                                           else scrie(i,j-1);
end;
begin {pp}
citire;
for i:=1 to n do
 for j:=1 to m do
  if x[i]=y[j] then begin
                    if (i=1)or(j=1) then inc(c[i,j])
                                    else c[i,j]:=c[i-1,j-1]+1;
                    end
               else
                 if c[i,j-1]>c[i-1,j] then c[i,j]:=c[i,j-1]
                                      else c[i,j]:=c[i-1,j];


assign(g,'cmlsc.out'); rewrite(g);
writeln(g,c[n,m]);
scrie(n,m);
close(g);
end.