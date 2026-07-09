type vector=array[1..1024] of integer;
var f,g:text;
i,j,a,b:integer;
c,q:array[0..1024,0..1024] of 0..1025;
x,y:array[1..1024] of integer;
procedure lungimecmlsc(x,y:vector);
var i,j:integer;
begin
        for i:=1 to a do
                c[i,0]:=0;
        for j:=0 to b do
                c[0,j]:=0;
        for i:=1 to a do
                for j:=1 to b do
                        if x[i]=y[j] then begin
                                c[i,j]:=c[i-1,j-1]+1;q[i,j]:=1;end
                        else
                                if c[i-1,j]>=c[i,j-1] then
                                        c[i,j]:=c[i-1,j]
                                else
                                        c[i,j]:=c[i,j-1];
end;
begin
        assign(f,'cmlsc.in');assign(g,'cmlsc.out');
        reset(f);rewrite(g);
        read(f,a,b);
        for i:=1 to a do
                read (f,x[i]);
        for i:=1 to b do
                read (f,y[i]);
        lungimecmlsc(x,y);
        writeln (g,c[a,b]);
        for i:=1 to a do
                for j:=1 to b do
                        if q[i,j]=1 then
                                write (g, x[i],' ');
        close(f);close(g);
end.