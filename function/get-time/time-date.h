/**
 * @file time-date.h
 * @brief Some functions for students
 *
 * @author Henrik Sandklef & Rikard Fröberg
 *
 * @date 2016-11-04
*/


/** 
 * Returns the current month as an integer value. 
 * January - 1
 * ...
 * December 12
 *
 * Example Usage:
 * @code
 *    int month = current_month();
 * @endcode
 */
int current_month(void);

/** 
 * Returns the current day (in the urrent month) as an integer value.
 *
 * Example Usage:
 * @code
 *    int day = current_day();
 * @endcode
 */
int current_day(void);

/** 
 * Returns the current year as an integer value.
 *
 * Example Usage:
 * @code
 *    int day = current_year();
 * @endcode
 */
int current_year(void);


/** 
 * Returns the current second (in this minute, hour etc) as an integer value.
 *
 * Example Usage:
 * @code
 *    int sec = current_sec();
 * @endcode
 */
int current_sec(void);


/** 
 * Returns the current hour (in this day) as an integer value.
 *
 * Example Usage:
 * @code
 *    int hour = current_hour();
 * @endcode
 */
int current_hour(void);


/** 
 * Returns the current minute (in this hour) as an integer value.
 *
 * Example Usage:
 * @code
 *    int minute = current_min();
 * @endcode
 */
int current_min(void);

/** 
 * Prints (to stdout) the current date
 *
 * Example Usage:
 * @code
 *    print_current_month();
 * @endcode
 */
void print_current_date();

/** 
 * Returns the current month as a string. The function allocates no memory.
 *
 * Example Usage:
 * @code
 *    char* mont_name = current_month_name();
 * @endcode
 */
char * current_month_name();

/** 
 * Returns the month name of a month number supplied by the caller.
 *
 * @param [in] month the month (number) to get the name for
 *
 * Example Usage:
 * @code
 *    char* mont_name = month_name(12);
 * @endcode
 */
char * month_name(unsigned char month);

/** 
 * Prints (to stdout) the name of the current month
 *
 * Example Usage:
 * @code
 *    print_month_month();
 * @endcode
 */
void print_month_name(unsigned char month);
