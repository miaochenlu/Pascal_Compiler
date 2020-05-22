PROGRAM stmtTest;
CONST
    a = 1;
VAR
    b, c, d : INTEGER;

BEGIN
    b := 1;
    c := 0;
    IF a = 1 THEN BEGIN
        FOR d:=1 TO 10 DO BEGIN 
            c := c + 1;
            WHILE C <= 5 DO BEGIN 
                d := 0;
                d := 0;
            END;

            REPEAT 
                d := 0;
            UNTIL C > 5;
        END;
    END  
    ELSE 
    BEGIN 
        d := 0;
    END;

    CASE d + 1 OF 
		0: BEGIN str := 'A1'; c := 1; END;
		1: str := 'B2';
		2: str := 'C3';
		3: str := 'D4';
	END;

    WRITE(d);
    WRITELN(d);
END.






j[1] := 1;
    j[2] := 2;
    j[3] := 3;
    e := j[0] + j[1] * j[2];
    k.a := j[0] + b - c * 4 DIV 3 * 3 + test(j[0]);



    PROGRAM arrayRecord;
CONST
    a = FALSE;
    b = 10;
    c = 2.2;
    d = 't';
    e = 'str';
TYPE
    rtype = RECORD
        a : INTEGER;
        b : INTEGER;
    END;

VAR
    e : INTEGER;
    f : REAL;
    h : STRING;
    i : BOOLEAN;
    j : ARRAY [0..3] OF INTEGER;
    k : rtype;

FUNCTION test(a:INTEGER) : INTEGER;
BEGIN
    test := a;
END;

BEGIN
    h := 'string';
    j[0] := 0 + 1 + 2;
END.




PROGRAM procTest;
{routine head}

{const part}
CONST
	cn = 2;
	dn = 123.23;
{var part}
VAR	
	k : integer;

{routine part}
PROCEDURE outer;
{subroutine var part}
VAR 
	res : integer;
	added : integer;
{subroutine routine part}
FUNCTION inner1(a , b : INTEGER) : INTEGER;
BEGIN
	inner1 := a + b;
END;

PROCEDURE inner2(aa : INTEGER; b :INTEGER);
BEGIN
	aa := inner1(aa , b);
	k := k + 10;
END;

BEGIN
	k := 0;
	inner2(k , 10);
END;

{routine body}
BEGIN
	outer;
END.
