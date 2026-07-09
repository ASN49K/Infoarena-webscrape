{sa se determine subsirul comun al 2 siruri date}
program subsir_comun;
type vector=array[1..100] of word;
     matrice=array[0..100,0..100] of word;
var  x,y:vector;
     c:matrice;
     i,j,n,m,max1:word;
     f,g:text;

function max(x,y:word):word;
begin
max:=y;
if x>y then max:=x;
end;

procedure tipar(x,y:vector;c:matrice;i,j:word);
begin
if (i<>0)and(j<>0)then
    if(x[i]=y[j]) then
                  begin
                  tipar(x,y,c,i-1,j-1);
                  write(g,x[i],' ')
                  end
                  else
                      if(c[i-1,j]>c[i,j-1]) then tipar(x,y,c,i-1,j)
                                            else tipar(x,y,c,i,j-1);
end;
begin
assign(f,'subsirc.in');reset(f);
assign(g,'subsirc.out');rewrite(g);
readln(f,m,n); max1:=0;
for i:=1 to m do read(f,x[i]);readln(f);
for i:=1 to n do read(f,y[i]);
for i:=0 to 100 do begin c[0,i]:=0;c[i,0]:=0;end;
for i:=1 to m do
 for j:=1 to n do if x[i]=y[j] then c[i,j]:=c[i-1,j-1]+1
                               else c[i,j]:=max(c[i-1,j],c[i,j-1]);
for i:=1 to m do
 for j:=1 to n do if c[i,j]>max1 then max1:=c[i,j];
writeln(g,max1);
for i:=1 to m do
begin
 for j:=1 to n do write(g,c[i,j]:3);
 writeln(g);
 end;
tipar(x,y,c,n,m);
close(f);close(g);
end.
