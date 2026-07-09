program cel_mai_lung_subsir_comun;
var a:array [1..1024] of integer;
    b:array [1..1024] of integer;
    c:array [1..1024] of integer;
    x,y,z,i,j:0..256;
    f,g:text;
begin
assign (f,'cmlsc.in'); reset (f);
assign (g,'cmlsc.out'); rewrite (g);
read (f,x);
read (f,y);
readln (f);
for i:=1 to x do read (f,a[i]);
readln (f);
for j:=1 to y do read (f,b[j]);
z:=0;
for i:=1 to x do for j:=1 to y do if (a[i]=b[j]) then begin z:=z+1;
                                                            c[z]:=a[i];
                                                            break;
                                                      end;
writeln (g,z);
for i:=1 to z do write (g,c[i],' ');
close (f);
close (g);
end.
