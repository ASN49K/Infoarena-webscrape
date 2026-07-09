    var T, i : integer ;
        A, B : longint ;

    function ggt ( a , b : longint ) : longint;
        begin
            while a <> b do
                if a > b then a := a - b
                else b := b - a ;
            ggt := a
        end ;

    begin
        assign ( input, 'euclid2.in' ) ; reset ( input ) ;
        assign ( output, 'euclid2.out' ) ; rewrite ( output ) ;

        readln ( T ) ;

        for i := 1 to T do
            begin
                readln ( A, B ) ;
                writeln ( ggt ( A, B ) ) ;
            end ;
        close ( input ) ; close ( output ) ;
    end .
