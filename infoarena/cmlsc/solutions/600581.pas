Program SubsirComunMaximal;
 var  n, m, k, h:longint;
      x, y, c:array [0..1025] of byte;
      LCS: array[0..1025,0..1025] of integer;
      D: array [0..1025,0..1025] of string[2];
      fo:text;
procedure Citire;
var fin:text; i: integer;
begin
assign (fin, 'cmlsc.in'); reset (fin);
readln (fin, n, m);
for i := 1 to n do read (fin, x[i]);
readln (fin);
for i := 1 to m do read (fin, y[i]);
readln (fin);
close (fin);
end;
procedure Afisare (k, h:integer);
begin
if D[k, h] ='v' then
   begin
   Afisare(k-1, h-1);
   write(fo,x[k],' ');
   end
   else
   if D[k,h]='nv' then
      Afisare (k-1,h)
      else
      if D[k,h] = 'sv' then Afisare (k, h-1);
  end;
begin
 assign(fo,'cmlsc.out');
  rewrite(fo);
Citire;
for k := 1 to n do
    for h := 1 to m do
        if x[k]=y[h] then
           begin
           LCS[k,h]:= 1 + LCS[k - 1, h - 1];
           D [k,h]:='v';
           end
           else
           if LCS[k - 1,h]<LCS[k,h - 1] then
              begin
              LCS[k, h] := LCS [k, h - 1];
              D[k, h] := 'sv';
              end
              else
              begin
              LCS[k,h]:= LCS[k-1,h];
              D[k,h]:='nv';
              end;
writeln(fo,LCS[n,m]);
Afisare (n, m);
close(fo);
end.
