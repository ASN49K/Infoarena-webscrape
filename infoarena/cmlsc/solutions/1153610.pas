var V:array[0..1030,0..1030] of longint;
    a,b,c:array[0..1034] of longint;
    n,m,i,j,h:longint;
    f,g:text;


function max(x,y:longint):longint;
 begin
  if x>y then max:=x
         else max:=y;
 end;

begin
 assign(f,'cmlsc.in');reset(f);
 assign(g,'cmlsc.out');rewrite(g);
 readln(f,n,m);
 for i:=1 to n do read(f,a[i]);
 readln(f);
 for i:=1 to m do read(f,b[i]);

 for i:=1 to n do
  for j:=1 to m do
   begin
    if a[i]=b[j] then v[i,j]:=v[i-1,j-1]+1
                 else v[i,j]:=max(v[i-1,j],v[i,j-1]);
   end;


i:=n;
j:=m;
h:=v[n,m];
while i>=1 do
 begin
  if (j>1)and(v[i,j-1]=h) then dec(j)
                          else if v[i-1,j]=h then dec(i)
                          else begin
                                c[h]:=a[i];
                                dec(h);
                                dec(i);
                                dec(j);
                               end;
 end;
writeln(g,v[n,m]);
for i:=1 to v[n,m] do
 write(g,c[i],' ');
close(g);
close(f);
end.