program cmmdc;


var x,y:longint;
    T,i:longint;
    f,g:text;
    function divizor(a,b:longint):longint;
    var r:longint;

    begin
    while b>0 do begin
    r:=a mod b;
    a:=b;
    b:=r;
    end;
    divizor:=a;
                            end;



    begin
    assign(f,'euclid2.in');
    reset(f);
    assign(g,'euclid2.out');
    rewrite(g);

     readln(f,T);
     for i:=1 to T do begin
     readln(f,x,y);
     writeln(g,divizor(x,y));
     end;
     close(f);
     close(g);
     end.
