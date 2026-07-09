type tomb=array[1..1024] of byte;
var i,j,m,n,h:integer;a,b,c:tomb;f,g:text;
begin
        assign(f,'cmlsc.in');assign(g,'cmlsc.out');reset(f);
        read(f,m,n);
        for i:=1 to m do
                read(f,a[i]);
        for i:=1 to n do
        begin
                read(f,b[i]);
                for j:=1 to m do
                        if b[i]=a[j] then
                                c[j]:=b[i];
        end;close(f);rewrite(g);
        for i:=1 to m+n do
                if c[i]<>0 then
                begin
                        h:=h+1;
                        c[h]:=c[i];
                end;
        writeln(g,h);
        for i:=1 to h do
                write(g,c[i],' ');
        close(g);
end.
