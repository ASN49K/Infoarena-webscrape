program subsir_comun_de_lungime_maxima;
var f,g:text;
    d:array[0..1024,0..1024] of 0..256;
    a,b,sir:array[0..1024] of 0..256;
    n,m,i,j,bst:integer;

begin
   assign(f,'cmlsc.in');reset(f);
   assign(g,'cmlsc.out');rewrite(g);
   read(f,n,m);
   for i:=1 to n do
      read(f,a[i]);
   for i:=1 to m do
      read(f,b[i]);
   for i:=1 to n do
      for j:=1 to m do
         if a[i]=b[j] then
            d[i,j]:=d[i-1,j-1]+1
         else
            if d[i-1,j]>d[i,j-1] then
               d[i,j]:=d[i-1,j]
            else
               d[i,j]:=d[i,j-1];
   i:=n;j:=m;
   while (i>0)and(j>0) do
      if a[i]=b[j] then
         begin
            bst:=bst+1;
            sir[bst]:=a[i];
            i:=i-1;
            j:=j-1;
         end
      else
         if d[i-1,j]>d[i,j-1] then
            i:=i-1
         else
            j:=j-1;
   writeln(g,bst);
   for i:=bst downto 1 do
      write(g,sir[i],' ');
   close(f);
   close(g);
end.