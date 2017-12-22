# CSV and C

We've gotten some questions from students how to parse a CSV file in
C. We've also gotten a few questions in another course (Java) on how
to do it in C. Ok let's give an example which we can use in a lab
we've written (Exposing data over
http)[http://wiki.juneday.se/mediawiki/index.php/Assignment:Exposing_data_over_http]. In
this lab the students get a CSV parse written in Java and should
expose and consume the data using JSON.

The original lab/assignment is about fixing the so called "Open API"
offered by Systembolaget, a government-owned chain of liquor stores in
Sweden. The "Open API" is actually a static XML file. Ok, it's updated
daily but it's not an API. The students should download the XML file,
put the products in a database and expose the products using JSON.

In this directory you'll find a solution on how to:

* download XLS file

* convert XLS to CSV

* read the CSV and store the products in a list

* print SQL statements given the list above

* pipe the SQL printouts to SQLIte to store the products in a database

# About the solution

## Data

The data from Systembolaget is downloaded using either a script:
```
$ ./bin/download.sh
```

or using the Makefile
```
$ make download
```
which invokes the script above. The script uses (curl)[https://curl.haxx.se/] to download.

## Converting to CSV

We're using a program called ```ssconvert``` (part of (Gnumeric)[http://www.gnumeric.org/]). If it is available under Windows or MacOS we don't know. But we have provided the data files (XML, XLS and CSV) for you.

## dealing with '

The ' in the csv file are replaced by ''. This is done using sed.

## dealing with "

The " in the csv file are removed . This is done using sed.

## strtok - quite unusable

From the strok manual:
```From  the  above description, it follows that a sequence of two or more contiguous delimiter bytes in the parsed string is considered
   to be a single delimiter, and that delimiter bytes at the start or end of the string  are  ignored.   Put  another  way:  the  tokens
   returned by strtok() are always nonempty strings.  Thus, for example, given the string "aaa;;bbb,", successive calls to strtok() that
   specify the delimiter string ";," would return the strings "aaa" and "bbb", and then a null pointer.
```

Parsing a csv file with one field missing will be impossible. So let's skip that.

We're using ```strsep``` instead.

# Software requirements

* (curl)[https://curl.haxx.se/] - if you want to download the XML, XLS files instead of using the provided

* (SQLite)[https://www.sqlite.org/] - if you want to store the data in a database

* (Valgrind)[http://valgrind.org/] - if you want to run the memory checks

