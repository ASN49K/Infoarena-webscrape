program cmmdc;


var x,y:longint;
    T,i:longint;
    f,g:text;
    function divizor(a,b:longint):integer;
    var r,divz:integer;
        divi:boolean;
    begin
    if a>b then r:=b
           else r:=a;
    divi:=false;
     repeat
     if (a mod r=0) and (b mod r=0) then begin divi:=true;
                                           divz:=r;
                                           end
                                     else r:=r-1;
                                     until divi=true;

                             divizor:=divz;
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
