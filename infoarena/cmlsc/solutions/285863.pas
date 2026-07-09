program Comun;
uses
  Crt;
var
  fl:text;
  n,tot,i,j,k,m,l:integer;
  d,c:array[0..1025,0..1025] of integer;
  a,b,p,z,s:array[1..1025] of integer;
begin
   ClrScr;
   assign(fl,'cmlsc.in');
   reset(fl);
   readln(fl,n,m);
   for i := 1 to n do
      read(fl,a[i]);
   for i := 1 to m do
      read(fl,b[i]);
   close(fl);
   d[0,0] := 0;
   d[1,0] := 0;
   d[0,1] := 0;
   for i := 1 to n do
     for j := 1 to m do
        if a[i] = b[j] then
          begin
             d[i,j] := d[i-1,j-1]+1;
             l := l+1;
             c[i,j] := d[i,j];
          end
        else
          if d[i-1,j]>d[i,j-1] then
             d[i,j] := d[i-1,j]
          else
            d[i,j] := d[i,j-1];


   i := n;
   j := m;
   tot := 0;
   k:=0;
   repeat
      if a[i]=b[j] then
         begin
            k := k+1;
            s[k] := a[i];
            i := i-1;
            j := j-1;
            d[n,m] := d[n,m]-1
         end
         else
           if d[i-1,j] > d[i,j-1] then
             i := i-1
          else
            j := j-1;
   until (i<=0) or (j<=0) or (d[n,m]=0);

   assign(fl,'cmlsc.out');
   rewrite(fl);
   writeln(fl,k);
   for i := k downto 1 do
      write(fl,s[i],' ');
   close(fl);
end.
