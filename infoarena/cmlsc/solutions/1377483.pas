var a:array[0..10000] of byte;
    n,k:byte;
    f,g:text;
procedure kiir;
        var i:integer;
        begin
         for i:=1 to k do write(g,a[i],' ');
         writeln();
        end;
procedure komb(n,l:byte);
        var i:integer;
        begin
        if l=0 then kiir
               else begin
                     for i:=a[k-l]+1 to n do
                          begin
                              a[k-l+1]:=i;
                              komb(n,l-1);
                            end;
                    end;

        end;
begin
 assign(f,'combinari.in'); reset(f);
 assign(g,'combinari.out'); rewrite(g);
 readln(n,k);
 a[0]:=0;
 komb(n,k);
end.