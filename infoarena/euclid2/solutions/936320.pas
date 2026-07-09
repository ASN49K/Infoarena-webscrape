program cmmdc;
type numere=record
      x,y,z:integer;
      end;
     sir=array[1..20] of numere;

var s:sir;
    T,i:integer;
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
     readln(T);
     for i:=1 to T do begin
     read(s[i].x,s[i].y);
     s[i].z:=divizor(s[i].x,s[i].y);
     end;

     for i:=1 to T do
     writeln(s[i].z);
     end.
