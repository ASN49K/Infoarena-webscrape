type matrice=array [0..1025,0..1025]of integer;
     tablou=array [1..1025]of integer;
var t,a,rez:tablou;
    c:matrice;
    i,j,k,m,n,max:integer;
    f,g:text;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
read(f,n,m);
for i:=1 to n do
 read(f,t[i]);
for i:=1 to m do
 read(f,a[i]);
for i:=1 to n do
 c[i,0]:=0;
for i:=1 to m do
 c[0,i]:=0;
k:=1;
for i:=1 to n do
 for j:=1 to m do
  begin
   if t[i]=a[j] then begin
                     c[i,j]:=c[i-1,j-1]+1;
                     if c[i,j]=k then begin
                                      rez[k]:=j;
                                      k:=k+1;
                                      end;
                     end
   else if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j]
           else c[i,j]:=c[i,j-1];
  end;
writeln(g,k-1);
for i:=1 to k-1 do
 write(g,a[rez[i]],' ');
close(f);
close(g);
end.