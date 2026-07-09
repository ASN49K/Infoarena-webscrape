program subsirlung;
var f,g:text;
    v,u:array of byte;
    a:array [0..1024,1..1024] of integer;
    bufin,bufout:array [1..65000] of byte;
    n,m,i,j,lin,col,nr:integer;
    sol:array [1..1024] of byte;

begin
 assign (f,'cmlsc.in'); reset (f);
 assign (g,'cmlsc.out'); rewrite (g);
 settextbuf (f,bufin);
 settextbuf(g,bufout);
 readln (f,m,n);
 setlength (v,m+1);
 setlength (u,n+1);
 for i:=1 to m do
  read (f,v[i]);
 readln (f);
 for j:=1 to n do
  read (f,u[j]);
  nr:=0;
 for i:=1 to m do
  for j:=1 to n do
  begin
   if (j<>1) then
   begin
    lin:=i; col:=j-1
   end
  else
  begin
   lin:=i-1;col:=n;
  end;
  if v[i]=u[j] then
  begin
   a[i,j]:=a[lin,col]+1  ;
   nr:=nr+1; sol[nr]:=v[i];
  end
  else
   a[i,j]:=a[lin,col];
  end;
 writeln (g,nr);
 for i:=1 to nr do
  write (g,sol[i],' ');
 close (f);
 close (g);
end.
