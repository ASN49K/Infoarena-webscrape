program cmmdc;
type numere=record
      x,y,z:integer;
      end;
     sir=array[1..20] of numere;

var s:sir;
    T,i:integer;
    f,g:text;
    function divizor(a,b:integer):integer;
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
     read(f,s[i].x,s[i].y);
     s[i].z:=divizor(s[i].x,s[i].y);
     end;

     for i:=1 to T do
     writeln(g,s[i].z);
     close(f);
     close(g);
     end.
