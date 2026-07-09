program cmmdc;
type numere=record
      x,y,z:longint;
      end;
     sir=array[1..10000] of numere;

var s:sir;
    T,i:longint;
    f,g:text;
    function divizor(a,b:longint):longint;
    var r,divz:longint;
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
     if (s[i].x=0) or (s[i].y=0) then s[i].z:=0;
     s[i].z:=divizor(s[i].x,s[i].y);
     end;

     for i:=1 to T do
     if s[i].z=0 then writeln('Eroare 0') else
     writeln(g,s[i].z);
     close(f);
     close(g);
     end.
