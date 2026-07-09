var f, g: text;
    m : array[0..1024,0..1024] of integer;
    a,b: array[1..1025] of integer;
    i, j, k, c, d : integer;
function Max(x,y:integer):integer;
  begin
    if x>y then
        max:=x
        else
        max:=y;
  end;
begin
 Assign(f,'cmlsc.in');
  reset(f);
  Readln(f,c,d);
  For i:=1 to c do
    Read(f,a[i]);
    Readln(f);
  For i:=1to d do
    Read(f,b[i]);



 for i:=1 to c do
  for j:=1 to d do
    if a[i]=b[j] then
       m[i,j]:=m[i-1,j-1]+1
          else
       m[i,j]:=max(m[i-1,j],m[i,j-1]);



 Assign(g,'cmlsc.out');
 rewrite(g);




writeln(g,m[c,d]);

 for i:=2 to c do
    if m[i,d]<>m[i-1,d] then
     Write(g,a[i],' ');
 close(g);






end.
