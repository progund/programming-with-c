#!/bin/bash

# Params:
#   $1 - return value
#   $2 - msg
exit_on_error()
{
    if [ $1 -ne 0 ]
    then
        echo "*** ERROR ***"
        echo "  $2  ($1)"
        exit 2
    fi
    
}

dload()
{
    if [ ! -f $2 ]
    then
        echo -n "Dowloading $1: "
        curl -s $1 -o $2
        exit_on_error $?
        echo "OK"
    fi
}

xlstocsv()
{
    if [ ! -f $2 ]
    then
        echo -n "Converting $1: " 
        ssconvert $1 $2
        exit_on_error $?
        echo "OK"
        
        echo -n "Removing \" from $2: "

        sed -i 's,",,g' $2
        exit_on_error $?
        echo "OK"
    fi
}

FILES_DIR=files
if [ ! -d ${FILES_DIR} ]
then
    mkdir ${FILES_DIR}
fi

dload https://www.systembolaget.se/api/assortment/products/xls ${FILES_DIR}/products.xls 
dload https://www.systembolaget.se/api/assortment/products/xml ${FILES_DIR}/products.xml

xlstocsv ${FILES_DIR}/products.xls ${FILES_DIR}/products.csv 
