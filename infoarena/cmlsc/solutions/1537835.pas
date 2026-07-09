program dinamica;
const Nmax = 1030;
type vector = array[1..Nmax] of integer;
     matrice = array[0..Nmax, 0..Nmax] of integer;
var f, g:text;
    n, m, i, j, k:integer;
    a, b, rez:vector;
    x:matrice;
    bufin, bufout:array[1..1 shl 17] of char;
//---------------------------------
procedure dinamica;
var i, j:integer;
begin
   for i := 1 to n do
      for j := 1 to m do
          if a[i] = b[j] then
             x[i, j] := x[i-1,j-1] + 1
          else
          if x[i-1, j] > x[i, j-1] then
             x[i, j] := x[i-1, j]
          else
             x[i, j] := x[i, j-1];

end;
//-------------------------------
begin
   assign(f, 'cmlsc.in'); reset(f);
   assign(g, 'cmlsc.out'); rewrite(g);
   settextbuf(f, bufin); settextbuf(f, bufout);
   readln(f, n, m);
   for i := 1 to n do
      read(f, a[i]);
   readln(f);
   for j := 1 to m do
      read(f, b[j]);
   dinamica();
   k := 0;
   while (i > 0) and (j > 0) do
      if a[i] = b[j] then
         begin
            inc(k);
            rez[k] := a[i];
            dec(i); dec(j);
         end
      else
         if x[i-1, j] < x[i, j-1] then dec(j)
                                  else dec(i);

   writeln(g, k);
   for i := k downto 1 do
      write(g, rez[i],' ');
   close(f); close(g);
end.