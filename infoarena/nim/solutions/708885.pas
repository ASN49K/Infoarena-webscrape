Program nim_game;
var fi,fo : text;
    i,n,j,k,s,nr : longint;

begin
    assign(fi,'nim.in'); reset(fi); readln(fi,k);
    assign(fo,'nim.out'); rewrite(fo);

    for j:=1 to k do begin
                     readln(fi,n); s:=0;
                     for i:=1 to n do begin
                                      read(fi,nr);
                                      s:=s xor nr;
                                      end;
                     if s=0 then writeln(fo,'NU')
                            else writeln(fo,'DA');
                     readln(fi);
                     end;

    close(fi); close(fo);
end.