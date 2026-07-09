var a,b,n,i:byte;
    f,g:text;
function cmmdc(a,b:byte):byte;
  var t: byte;
  begin
        while b<>0 do
        begin
                t:=b;
                b:=a mod b;
                a:=t;
        end;
        cmmdc:=a;
  end;


BEGIN
        assign(f,'euclid2.in');
        reset(f);
        assign(g,'euclid2.out');
        rewrite(g);
        readln(f,n);

        for i := 1 to n do
        begin
                read(f,a); readln(f,b);
                writeln(g,cmmdc(a,b));
        end;
        close(g);
        end.
