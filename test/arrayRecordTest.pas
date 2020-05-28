PROGRAM arrayRecordTest;
CONST
    b = 10;
    c = 2.2;
TYPE
    test = INTEGER;
    rtype = RECORD
        a : INTEGER;
        b,c : REAL;
    END;

VAR
    f : test;
    i : INTEGER;
    j : ARRAY [0..3] OF INTEGER;
    k : rtype;

BEGIN
    FOR i:= 0 TO 2 DO BEGIN
    	j[i] := i * i;
    END;
    f := b;
    WRITELN(f);
    WRITELN(j[1]);
    k.a := j[0] + j[1] * j[2];
    k.b := 1.3;
    WRITELN(k.a);
    WRITELN(k.b);
END.
