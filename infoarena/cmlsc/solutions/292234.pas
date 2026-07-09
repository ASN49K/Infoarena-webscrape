var     
    n, m, lst, i, j : longint;      
    a, b : array [0..1024] of byte;      
    sir  : array [1..1024] of integer;      
    d    : array [0..1024, 0..1024] of integer;      
    f : text;      
     
function max (a, b: integer) : integer;      
begin     
if (a > b) then max := a else max := b;      
end;      
     
     
begin     
assign  (f, 'cmlsc.in');      
reset   (f);      
readln  (f, n, m);      
for i := 1 to n do     
    read (f, a[i]);      
readln  (f);      
for i := 1  to m do     
    read (f, b[i]);      
close   (f);      
     
for i := 1 to n do     
    for j := 1 to m do     
        if (a[i] = b[j]) then     
            d[i,j] := d[i-1, j-1]  + 1     
        else     
            d[i,j] := max (d[i-1, j], d[i, j-1]);      
i := n;      
j := m;      
while (i <> 0) and (j <> 0) do     
    if (a[i] = b[j]) then     
        begin     
        inc (lst); sir [lst] := a[i];      
        dec (i); dec (j);      
        end     
    else     
    if (d[i-1,j] < d[i,j-1]) then     
        dec (j)      
    else     
        dec (i);      
     
     
assign  (f, 'cmlsc.out');      
rewrite (f);      
writeln (f, lst);      
for i := lst downto 1 do     
    write (f, sir[i], ' ');      
writeln(f);      
close   (f);      
end.    
