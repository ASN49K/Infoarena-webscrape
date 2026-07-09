program subisrialh;
var f,g:text;
    n,m,i,j,k:integer;
    c:array[0..1024,0..1024] of integer;
    x,y:array[1..1024] of byte;
    retine:array[1..1024] of byte;
    bufin,bufout:array[1..65000] of byte;
 
function max (a,b:integer):integer;
begin
 if a>b then max:=a
 else max:=b;
end;
 
begin
 assign (f,'cmlsc.in'); reset (f);
 assign (g,'cmlsc.out'); rewrite (g);
 settextbuf (f,bufin);
 settextbuf (g,bufout);
 readln (f,n,m);
 for i:=1 to n do read (f,x[i]);
 for i:=1 to m do read (f,y[i]);
 for i:=1 to n do
  for j:=1 to m do
   if x[i]=y[j] then c[i,j]:=1+c[i-1,j-1]
  else
   c[i,j]:=max(c[i-1,j], c[i,j-1]);
   writeln (g,c[n,m]);
   i:=n; j:=m;
   for k:=1 to c[n,m] do
   begin
   while c[i,j]=c[i-1,j] do dec(i);
   while c[i,j]=c[i,j-1] do dec(j);
   retine[k]:=x[i];
   dec(i);
   end;
   for i:=c[n,m] downto 1  do write (g,retine[i],' ');
   close (f); close (G);
end.