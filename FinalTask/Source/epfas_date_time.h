short is_leap_year(short year);
short get_month_days(short year, short month);

short check_date(short year, short month, short day);
short encode_date(short year, short month, short day, int *date);
short decode_date(int date, short *year, short *month, short *day);

short check_time(short hour, short minute);
short encode_time(short hour, short minute, short *time);
short decode_time(short time, short *hour, short *minute);

