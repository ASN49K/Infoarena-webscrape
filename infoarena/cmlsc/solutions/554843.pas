uses crt;
type
 kl=array[0..1024] of longint;
 op=array[0..1024,0..1024] of integer;
var
 a,b,c,i,j,m,n,max,h:longint;
 f,g:text;
 x,y,v,d,d2:kl;
 r:op;
 csel:boolean;
begin
 assign(f,'cmlsc.in');
 reset(f);
 assign(g,'clmsc.out');
 rewrite(g);
 readln(f,n,m);
 for i:=1 to n do
  read(f,x[i]);
 for i:=1 to m do
  read(f,y[i]);
 for i:=1 to m do
  begin
   csel:=false;
   for j:=1 to n do
    begin
     if y[i]=x[j]
      then
       begin
         d[j]:=v[j-1]+1;
         r[i,j]:=d[j];
         csel:=true;
       end;

    end;
   if csel then begin
   max:=d[1];
   for j:=2 to n do
    if max<d[j] then max:=d[j]
    else d[j]:=max;
   v:=d;             end;
  end;
 max:=v[1]; c:=1; h:=1;
 for i:=2 to n do
  if v[i]>max then begin c:=i;max:=v[i];end;
 i:=m;
 while r[i,c]<>max do
   dec(i);
 d2[1]:=y[i];  a:=max-1; b:=i-1;c:=c-1;
 while   a<>0 do
  begin
    i:=b;
    while (i>=a )and(r[i,j]<>a) do
      begin
        j:=c;
        while (j>=a) and (r[i,j]<>a) do
             dec(j);
        if r[i,j]<>a then
           dec(i);
      end;
    inc(h);
    d2[h]:=x[j];
    dec(a);
    c:=i-1;
    b:=j-1;
  end;
 for i:=h downto 1 do
   write(g,d2[i],' ');
 close(f);
 close(g);
end.
