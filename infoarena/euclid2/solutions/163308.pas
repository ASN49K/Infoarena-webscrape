// Un program facut in pascal :D
var a,b,t,i:longint;
    stdin,stdout:text;
function cmmdc(a,b:longint):longint;
begin
    if (b=0)then
       cmmdc:=a
    else cmmdc:=cmmdc(b,a mod b);
end;
begin
    assign(stdin,'euclid2.in');reset(stdin);
    assign(stdout,'euclid2.out');rewrite(stdout);
    readln(stdin,t);
    for i:=1 to t do begin
        readln(stdin,a,b);
        write(stdout,cmmdc(a,b));
    end;
    close(stdin);
    close(stdout);
end.

