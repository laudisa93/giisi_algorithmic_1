#include <stdio.h>
#include <stdlib.h>

int main()
{
    TYPE SOLUCION = ARRAY [1..G-1] OF BOOLEAN;
    PROCEDURE Deprisa(n:CARDINAL;
    VAR d:DISTANCIA;
    VAR sol:SOLUCION);
    VAR i,numkilometros:CARDINAL;
    BEGIN
    FOR i:=1 TO G-1 DO
    sol[i]:=FALSE
    END;
    i:=0;
    numkilometros:=0;
    REPEAT
    REPEAT
    INC(i);
    numkilometros:=numkilometros+d[i];
    UNTIL (numkilometros>n) OR (i=G-1);
    IF numkilometros>n THEN (* si nos hemos pasado... *)DEC(i);
    (* volvemos atras una gasolinera *)
    sol[i]:=TRUE;
    (* y repostamos en ella. *)
    numkilometros:=0;
    (* reset contador *)END
    UNTIL (i=G-1);
    END Deprisa;
}
