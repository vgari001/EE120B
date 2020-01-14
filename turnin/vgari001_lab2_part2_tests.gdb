echo ======================================================\n
echo Running all tests..."\n\n


test “PINA: 0x01  PORTC: 3”
setPINA 0x01
continue 2
expectPORTC 0x03
checkResult

test “PINA: x03, PORTC: 2”
setPINA 0x03
continue 2
expectPORTC 0x02
checkResult

test “PINA: x07, PORTC:1 ”
setPINA 0x07
continue 2
expectPORTC 0x01
checkResult

test “PINA: x0F, PORTC: 0”
setPINA 0x0F
continue 2
expectPORTC  0x00
checkResult

test “PINA: 0x00, PORTC: 4”
setPINA 0x00
continue 2
expectPORTC  0x04
checkResult






set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
