program secvcom;
var lcs:array[0..1025,0..1025] of longint;
    d,x,y:array[0..1025]of longint;
    cont,i,j,k,h,n,m:longint;
    t:text;

function max(x,y:longint):longint;
begin
 if x<y then max:=y else max:=x;
end;

begin
 assign(t,'cmlsc.in'); reset(t);
 readln(t,n,m);
 for i:=1 to n do read(t,x[i]);
 readln(t);
 for i:=1 to m do read(t,y[i]);
 close(t);

 for i:=1 to n do
  for j:=1 to m do
   if x[i]=x[j] then lcs[i,j]:=1+lcs[i-1,j-1]
   else lcs[i,j]:=max(lcs[i,j-1],lcs[i-1,j]);

 k:=n;
 h:=m;
 cont:=0;
 repeat
  if x[k]=y[h] then begin
   inc(cont);
   d[cont]:=x[k];
   dec(k);
   dec(h);
  end
  else
  if lcs[k,h]=lcs[k-1,h] then dec(k) else dec(h);
 until cont=lcs[n,m]-1;

 assign(t,'cmlsc.out'); rewrite(t);
 writeln(t,lcs[n,m]);
 for i:=cont downto 1 do begin
  write(t,d[i],' ');
 end;
 close(t);
end.
