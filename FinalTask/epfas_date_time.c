#include "epfas_date_time.h"

short is_leap_year(short year)
{
    if (year > 0 && year % 4 == 0)  {
        if (year % 100 || year % 400 == 0) {
            return 1;
	}
    }
    return 0;
}

short get_month_days(short year, short month)
{
    if (year < 1 || month < 1 || month > 12)
        return 0;
    
    if (month == 2) {
        if (is_leap_year(year)) 
            return 29;
        return 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) 
        return 30;

    return 31;
}

short check_date(short year, short month, short day)
{
    if (year < 1 || year > 3000) 
        return 1;
    if (month < 1 || month > 12)
        return 2;
    if (day < 1 || day > get_month_days(year, month)) 
        return 3;
    return 0;
}

short encode_date(short year, short month, short day, int *date)
{
    *date = 0;

    short check_result = check_date(year, month, day);
    if (check_result)
        return check_result;

    year--;
    int count400 = year / 400;
    year = year % 400;

    int count100 = year / 100;
    year = year % 100;

    int count4 = year / 4;
    year = year % 4; 

    *date = count400 * 146097 + count100 * 36524 + count4 * 1461 + year * 365 + day;
    year++;
    
    for (int i = 1; i < month; i++) 
    {
        *date += get_month_days(year, i);
    }

    return 0;
}

short decode_date(int date, short *year, short *month, short *day)
{
    *year = 0;
    *month = 1;
    *day = 0;

    int count400 = date / 146097;
    date = date % 146097;
    
    int count100 = date / 36524;
    date = date % 36524;

    int count4 = date / 1461;
    date = date % 1461;

    *year = 400 * count400 + 100 * count100 + 4 * count4 + date / 365;
    
    date = date % 365;
    if (date) {
        (*year)++;
        while (date)
        {
            short month_days = get_month_days(*year, *month); 

            if (date > month_days) {
                (*month)++;
                date -= month_days;
            }  else {
                *day = date;
                date = 0;
            }
        }
    } else {
        *month = 12;
        *day = 31;
    }

    return 0;
}

short check_time(short hour, short minute)
{
    if (hour < 0 || hour > 23) 
        return 1;
    if (minute < 0 || minute > 59)
        return 2;
    return 0;
}

short encode_time(short hour, short minute, short *time)
{
    *time = 0;

    short check_result = check_time(hour, minute);
    if (check_result)
        return check_result;
    
    *time = hour * 60 + minute;
    return 0;
}

short decode_time(short time, short *hour, short *minute)
{
    *hour = 0;
    *minute = 0;

    if (time <0 || time >= 1440)
        return 1;

    *hour = time / 60;
    *minute = time % 60;
    return 0;
}