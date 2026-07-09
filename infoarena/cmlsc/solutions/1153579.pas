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

 h:=0;
 for i:=1 to n do
  for j:=1 to m do
   begin
    if a[i]=b[j] then begin
                       inc(h);
                       c[h]:=a[i]; // sau b[j]
                       v[i,j]:=v[i-1,j-1]+1;
                      end
                 else v[i,j]:=max(v[i-1,j],v[i,j-1]);
   end;

 writeln(g,h);
 for i:=1 to h do write(g,c[i],' ');
close(g);
close(f);
end.