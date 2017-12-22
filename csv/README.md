# CSV and C

We've gotten some questions from students how to parse a CSV file in
C. We've also gotten a few questions in another course (Java) on how
to do it in C. Ok let's give an example which we can use in a lab
we've written (Exposing data over
http)[http://wiki.juneday.se/mediawiki/index.php/Assignment:Exposing_data_over_http]. In
this lab the students get a CSV parse written in Java and should
expose and consume the data using JSON.

# About the solution

## strtok - quite unusable

From the manual:
```From  the  above description, it follows that a sequence of two or more contiguous delimiter bytes in the parsed string is considered
   to be a single delimiter, and that delimiter bytes at the start or end of the string  are  ignored.   Put  another  way:  the  tokens
   returned by strtok() are always nonempty strings.  Thus, for example, given the string "aaa;;bbb,", successive calls to strtok() that
   specify the delimiter string ";," would return the strings "aaa" and "bbb", and then a null pointer.```

Parsing a csv file with one field missing will be impossible. So let's skip that.


