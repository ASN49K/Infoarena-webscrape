program pascal;
var f,g:text;
    v:array[0..1024,0..1024]of longint;
    a,b,x:array[1..1024]of longint;
    i,j,k,m,n,max:longint; ok:boolean;


    function maximus(p,q:longint):longint;
    begin
     if p>=q then maximus:=p
             else maximus:=q;
    end;

begin
 assign(f,'cmlsc.in'); reset(f);
 assign(g,'cmlsc.out'); rewrite(g);
 readln(f,m,n);
 for i:=1 to m do
    read(f,a[i]);
 readln(f);
 for i:=1 to n do
    read(f,b[i]);

  for i:=1 to n do
   for j:=1 to m do
    if b[i]=a[j] then v[i,j]:=v[i-1,j-1]+1
                 else v[i,j]:=maximus(v[i-1,j],v[i,j-1]);

 writeln(g,v[n,m]);
 max:=v[n,m];
 i:=n; j:=m; k:=0;
 while max<>0 do
   begin
    if b[i]=a[j] then
     begin
      k:=k+1;
      x[k]:=a[j];
      i:=i-1;
      j:=j-1;
      max:=max-1;
     end
     else
     if (v[i-1,j]=max-1) and (v[i,j-1]=max) then j:=j-1
     else i:=i-1;
    end;
  for i:=k downto 1 do write(g,x[i],' ');
 close(f);
 close(g);
end.












