#!/bin/sh


PROG=./calc
FAILS=0
SUCCS=0

declare -a OPERATORS
OPERATORS[0]="+"
OPERATORS[1]="-"
OPERATORS[2]="x"
OPERATORS[3]="/"
OPERATORS[4]="%"


test_expr()
{
    EXPR=$1
    EXPECTED=$2
    EXPECTED_RETURN=$3
    
    RESULT=$( ${PROG} 2>/dev/null ${1})
    RETURN=$?
    
    echo -n "Testing '$EXPR' ";
    if [ "$EXPECTED_RETURN" != "0" ]
    then
        if [ "$EXPECTED_RETURN" != "$RETURN" ]
        then
            echo "unexpected return value (expected:'$EXPECTED_RETURN' actual '$RETURN') FAIL"
            FAILS=$(( $FAILS + 1 ))
            return 1
        fi
    else
        if [ "$RETURN" != "0" ]
        then
            echo "  return value ($RETURN)  faulty] FAIL"
            FAILS=$(( $FAILS + 1 ))
            return 1
        fi
    fi


    if [ "$RESULT" != "$EXPECTED" ] && [ "$EXPECTED_RETURN" = "0" ]
    then
        echo -n "    expected: $EXPECTED"
        echo -n "    actual:   $RESULT"
        echo "FAIL"
        FAILS=$(( $FAILS + 1 ))
        return 1
    fi ;
    echo " [ $RESULT / $RETURN ]:  OK"
    SUCCS=$((SUCCS + 1 ))
}

test_random()
{
    OP_NR=$(( $RANDOM % 5 ))
    OP=${OPERATORS[$OP_NR]}
    OP1=$(( $RANDOM % 100000 + 1 ))
    OP2=$(( $RANDOM % 100000 + 1 ))

    EXPR="$OP1 $OP $OP2"
    EXP=$(echo $EXPR | sed 's,x,*,' | bc)
#    echo "--> RANDOM $EXPR $EXP"
    test_expr_ok "$EXPR" "$EXP"
 #   echo "<-- RANDOM"
}

test_expr_ok()
{
    test_expr "$1" $2 0
}


echo
echo "Positive tests"
echo "--------------------"
test_expr_ok "1 + 1"     2
test_expr_ok "1 + 100"   101
test_expr_ok "1 - 100"  -99
test_expr_ok "100 - 1"   99
test_expr_ok "17 / 3"    5
test_expr_ok "18 / 3"    6
test_expr_ok "19 / 3"    6
test_expr_ok "17 % 3"    2
test_expr_ok "18 % 3"    0
test_expr_ok "19 % 3"    1

echo
echo "Negative tests"
echo "--------------------"
test_expr "19 "  ""  2
test_expr "liverpool "  ""  2
test_expr "19 + "  ""  2
test_expr "19 + a "  ""  1
test_expr "a + 1 "  ""  1
test_expr " "  ""  2



echo
echo "Random tests"
echo "--------------------"
LIMIT=10
CNT=0
while [ $CNT -le $LIMIT ]
do
    test_random
    CNT=$(( $CNT + 1 ))
done

echo
echo "Boundary tests (64 bit computer)"
echo "--------------------"
test_expr_ok "2147483647 + 0" 2147483647
test_expr_ok "2147483646 + 1" 2147483647
test_expr "2147483647 + 1"  0 1 
test_expr "947483647 x 9"  0 1 
test_expr "-2147483647 - 1" -2147483648 0  
test_expr "-2147483647 - 2" 0 1
test_expr "-2147483647 / 1" -2147483648 0  
test_expr "-2147483647 / 0" 0 1  
test_expr "-2147483647 % 0" 0 1  



echo 
echo "Tests: $(( $SUCCS  + $FAILS ))"
echo " failures:  $FAILS"
echo " successes: $SUCCS"

