# Test file for "Lab3_bitman"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test “PORTA:0x30,  PORTC: 0xC0”
setPINA 0x30
continue 2
expectPORTC 0xC0
checkResult

test “PORTA:0x4C,  PORTC:0x3E  ”
setPINA 0x02
continue 2
expectPORTC 0x3E
checkResult 

test “PORTA:0x71, PORTC: 0x20”
setPINA 0x71
continue 2
expectPORTC 0x20
checkResult


test “PORTA:0x33, PORTC 0xB0C”
setPINA 0x08
continue 2
expectPORTC 0xB0
checkResult


set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
