// Un program facut in pascal :D
var a,b:longint;
    stdin,stdout:text;
function cmmdc(a,b:integer):integer;
begin
    if (b=0)then
       cmmdc:=a
    else cmmdc:=cmmdc(b,a mod b);
end;
begin
    assign(stdin,'euclid2.in');reset(stdin);
    assign(stdout,'euclid2.out');rewrite(stdout);
    read(stdin,a,b);
    write(stdout,cmmdc(a,b));
    close(stdin);
    close(stdout);
end.

