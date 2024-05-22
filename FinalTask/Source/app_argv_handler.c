#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "data_model.h"
#include "epfas_date_time.h"


void print_welcome_info() 
{
    printf("\nThis program is final task of study course 'Basic Programing in C' (www.EasyEmbedded.ru). \n");
    printf("Student: Alexey Smolyakov aka EPFAS (IUS1, started at 2024-03).\n\n");
    printf("This program shows average, minimal and maximal temperature values per requested period and grouping level.\n");
    printf("Data source is external .csv file.\n\n");
}

void print_help_info() 
{
    printf("\nProgram parameters:\n");
    printf("  -h                                          Help\n");
    printf("  -f filename                                 File name to load (mandatory)\n");
    printf("  -s year[-month][-day][-hour][-minute]       Starting period\n");
    printf("  -e year[-month][-day][-hour][-minute]       Ending period\n");
    printf("  -g value                                    Grouping level. Possibles values:\n");
    printf("                                                Y - per year\n");
    printf("                                                M - per month\n");
    printf("                                                D - per day\n");
    printf("                                                H - per hour (default)\n");
    printf("                                                A - per minute (all)\n\n\n");
}

int eveluate_text_to_int(char source[], int *res) {
    *res = 0;
    if (!source[0])
        return 0;
    
    int len = strlen(source);
    int k = 1;
    for (int i = len -1; i >= 0; i--) {
        if (source[i] >= '0' || source[i] <= '9') {
            *res += (source[i] - '0') * k;
            k *= 10;
        } else
            return 0;
    }
    return 1;
}

int eveluate_textparam_to_date_time(char source[], short is_end, int *date, short *time) 
{
    if (!source[0])
        return 0;
    
    short year = 1;
    short month = 1;
    short day = 1;
    short hour = 0;
    short minute = 0;

    char param_value[5] = {0};
    short param_no = 0;
    short param_len = 0;

    int len = strlen(source);
    for (int i = 0; i < len; i++ ) {
        if ((source[i] < '0' || source[i] >'9') && source[i] != '-')
            return 0;

        if (source[i] >= '0' && source[i] <= '9') { 
            if (param_len > 3 || param_no && param_len > 1) 
                return 0;
            param_value[param_len] = source[i];
            param_len++;
        }; 
            
        if (source[i] == '-' || i == len-1) {
            if (!param_len) 
                return 0;
            int x;    
            if (!eveluate_text_to_int(param_value, &x))
                return 0;

            param_no++;
            switch (param_no) {
                case 1: 
                    year = x;
                    break;
                case 2: 
                    month = x;
                    break;
                case 3: 
                    day = x;
                    break;
                case 4: 
                    hour = x;
                    break;
                case 5: 
                    minute = x;
                    break;        
                default:
                    return 0;
            }
            
            for (int j = 0; j <5; j++) {
                param_value[j] = 0;
            }
            param_len = 0;
        }
    }

    if (param_no < 5 && is_end) {
        minute = 59;
    }

    if (param_no < 4 && is_end) {
        minute = 23;
    }

    if (param_no < 2 && is_end) {
        month = 12;
    }

    if (month < 1 || month > 12 || year < 0 || year > 3000)
        return 0;

    if (param_no < 3 && is_end) {
        day = get_month_days(year, month);
    }

    if (encode_date(year, month, day, date))
        return 0;
    if (encode_time(hour, minute, time))
        return 0;

    return 1;
}

int handle_cmd_args(int argc, char *argv[], Process_Params *proc_prm)
{
    /*
    for (int i=0; i < argc; i++) {
        printf("argc = %d, argv = %s\n", i, argv[i]);
    } */

    opterr = 0;  // hide incapsulated errors of getopt
    int param = 0;
    while ((param = getopt(argc,argv,"hf:s:e:g:")) != -1) {
        switch (param) {
            case 'h': 
                print_help_info();
                return 0;
                break;

            case 'f': 
                strcpy(proc_prm->filename, optarg);
                break;

            case 's': 
                if (!eveluate_textparam_to_date_time(optarg, 0, &(proc_prm->start_date), &(proc_prm->start_time))) {
                    printf("Invalid value \"%s\" of parameter \"%c\". See help.\n", optarg, optopt);
                    print_help_info();
                    return 0;
                }
                break;

            case 'e': 
                if (!eveluate_textparam_to_date_time(optarg, 1, &(proc_prm->end_date), &(proc_prm->end_time))) {
                    printf("Invalid value \"%s\" of parameter \"%c\". See help.\n", optarg, optopt);
                    print_help_info();
                    return 0;
                }
                break;

            case 'g': 
                if (strcmp(optarg, "Y") == 0)
                    proc_prm->group_by = 1;
                if (strcmp(optarg, "M") == 0)
                    proc_prm->group_by = 2;    
                if (strcmp(optarg, "D") == 0)
                    proc_prm->group_by = 3;   
                if (strcmp(optarg, "H") == 0)
                    proc_prm->group_by = 4;        
                if (strcmp(optarg, "A") == 0)
                    proc_prm->group_by = 5;     
                if (proc_prm->group_by == 0) {
                    printf("Invalid value \"%s\" of parameter \"%c\". See help.\n", optarg, optopt);
                    print_help_info();
                    return 0;
                }   
                break;

            case '?': 
                if (optopt == 'f' || optopt == 's' || optopt == 'e' || optopt == 'g') {
                    printf("Invalid or empty value of parameter \"%c\". See help.\n", optopt);
                } else { 
                    printf("Unexpected parameter \"%c\". See help.\n", optopt);
                }
                print_help_info();
                return 0;
                break;
        };
    };

    if (!proc_prm->group_by)
        proc_prm->group_by = 4;

    return 1;
}