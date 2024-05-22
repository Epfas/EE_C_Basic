#include <stdio.h>
#include <stdlib.h>
#include "data_model.h"
#include "epfas_date_time.h"

void init_Process_Params(Process_Params *proc_prm)
{
    proc_prm->filename[0] = 0;
    proc_prm->start_date = 0;
    proc_prm->start_time = 0;
    proc_prm->end_date = 0;
    proc_prm->end_time = 0;
    proc_prm->group_by = 0;  
    
    proc_prm->lines_total = 0;
    proc_prm->lines_error = 0;
    proc_prm->lines_skip = 0; 

    proc_prm->start_item = NULL;
    proc_prm->curr_item = NULL;
}

void print_Process_Params(Process_Params *proc_prm) 
{
    short year, month, day, hour, minute;
 
    printf("\nProcess parameters:\n");
    printf("  Data file:   %s\n", proc_prm->filename);
    if (proc_prm->start_date) {
        decode_date(proc_prm->start_date, &year, &month, &day);
        decode_time(proc_prm->start_time, &hour, &minute);
        printf("  From period: %4d.%2d.%2d  %2d:%2d\n", year, month, day, hour, minute);
    }

    if (proc_prm->end_date) {
        decode_date(proc_prm->end_date, &year, &month, &day);
        decode_time(proc_prm->end_time, &hour, &minute);
        printf("  To period:   %4d.%2d.%2d  %2d:%2d\n", year, month, day, hour, minute);
    }

    if (proc_prm->group_by) {
        printf("  Group level: ");
        switch (proc_prm->group_by)
        {
            case 1:
                printf("per Year\n");
                break;
            case 2:
                printf("per Month\n");
                break;
            case 3:
                printf("per Day\n");
                break;
            case 4:
                printf("per Hour\n");
                break;
            case 5:
                printf("per Minute\n");
                break;    
            default:
                printf("???\n");
                break;
        }
    }   
    printf(" \n");
}

int load_Data(Process_Params *proc_prm)
{
    if (proc_prm->filename == 0) 
        return 0;

    printf("Loading data...\n");

    FILE *f_in = fopen(proc_prm->filename, "r");
    if (f_in == NULL) 
        return 0;

    short fatal_error = 0;
    int a;
    int year, month, day, hour, minute, temp;
    while( (a = (fscanf(f_in, "%d;%d;%d;%d;%d;%d", &year, &month, &day, &hour, &minute, &temp)))!= EOF) 
    {   
        proc_prm->lines_total++;
        if (a != 6) {
            char error[100] = {0};
            fscanf(f_in,"%[^\n]",error);
            printf("  Line %8d | Error: %s\n", proc_prm->lines_total, error);
            proc_prm->lines_error++;
            continue;   
        } 
        
        int date = 0;
        if (encode_date(year, month, day, &date)) {
            printf("  Line %8d | Error: Incorrect date\n", proc_prm->lines_total);
            proc_prm->lines_error++;
            continue;
        }

        short time = 0;
        if (encode_time(hour, minute, &time)) {
            printf("  Line %8d | Error: Incorrect time\n", proc_prm->lines_total);
            proc_prm->lines_error++;
            continue;
        }

        if (proc_prm->start_date && (date < proc_prm->start_date || date == proc_prm->start_date && time < proc_prm->start_time) ||
            proc_prm->end_date && (date > proc_prm->end_date || date == proc_prm->end_date && time > proc_prm->end_time))
        {
            printf("  Line %8d | Skip:  Out of period range\n", proc_prm->lines_total);
            proc_prm->lines_skip++;
            continue;
        }

        if (temp < -99 || temp > 99) {
            printf("  Line %8d | Skip:  Out of temperature range\n", proc_prm->lines_total);
            proc_prm->lines_skip++;
            continue;
        }

        if (!push_Data(proc_prm, date, time, temp)) {
            printf("  Line %8d | Skip:  Not included in list\n", proc_prm->lines_total);
            proc_prm->lines_skip++;
            fatal_error = 1;
            break;
        }
    }
    fclose(f_in);

    if (fatal_error) {
        printf("Data load has been INTERUPTED:\n");
    } else {
        printf("Data is loaded:\n");
    }
    
    printf("  Loaded:  %8d\n", proc_prm->lines_total - proc_prm->lines_error - proc_prm->lines_skip);
    printf("  Errors:  %8d\n", proc_prm->lines_error);
    printf("  Skipped: %8d\n", proc_prm->lines_skip);
    printf("  Total:   %8d\n\n", proc_prm->lines_total);
    return 1 - fatal_error;
}

int push_Data(Process_Params *proc_prm, int date, short time, short temp)
{
    short arr[5] = {0};
    if (decode_date(date, &arr[0], &arr[1], &arr[2])) 
        return 0;
    if (decode_time(time, &arr[3], &arr[4])) 
        return 0;        
    short year = arr[0];        
    
    List_Item *item_year = proc_prm->curr_item;
    
    if (!get_List_Item(1, year, &(proc_prm->start_item), &item_year)) {
        if (!insert_List_Item(1, year, &(proc_prm->start_item), &item_year)) {
            return 0;
        }
    } 
    proc_prm->curr_item = item_year;
    update_Item_Data(item_year, temp);
    
    List_Item *up_list_item = item_year;
    List_Item *start_item;
    List_Item *new_item;
    for (size_t i = 2; i <= proc_prm->group_by; i++) 
    {
        start_item = up_list_item->sub_list;
        new_item = NULL;
        if (!get_List_Item(i, arr[i-1], &start_item , &new_item)) {
            if (!insert_List_Item(i, arr[i-1], &start_item , &new_item)) {
                return 0;
            }
            up_list_item->sub_list = start_item;
        }

        update_Item_Data(new_item, temp);
        up_list_item = new_item;
    }

    return 1;
}

short get_List_Item(short period_type, short period_value, List_Item **start_item, List_Item **res_item)
{
    List_Item *start = *start_item;
    List_Item *curr = *res_item;
    List_Item *prev = NULL;

    if (start == NULL || start->data.period_type != period_type) {
        *res_item = NULL;    
        return 0;   
    }

    if (curr != NULL && curr->data.period_value == period_value) {
        return 1;
    }

    if (curr == NULL) {
        curr = start;
    } else {
        if (curr->data.period_value > period_value) {
            curr = start;
        }
    }

    while (curr != NULL) 
    {
        if (curr->data.period_value == period_value) {
            *res_item = curr;
            return 1;
        } 

        if (curr->data.period_value > period_value) {
            *res_item = prev;
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }

    return 0;
}

short insert_List_Item(short period_type, short period_value, List_Item **start_item, List_Item **res_item)
{
    List_Item *res = NULL;
    List_Item *start = *start_item;
    List_Item *curr = NULL;
    List_Item *prev = NULL;

    if (start != NULL && start->data.period_type != period_type) {
        *res_item = NULL;
        printf("Incorrect type %d-%d\n", period_type, period_value);
        return 0;
    }

    curr = start;
    while (curr != NULL) {
        if (curr->data.period_value == period_value) {
            *res_item = curr;
            return 1;
        }

        if (curr->data.period_value > period_value) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    res = malloc(sizeof(List_Item));
    init_Item_Data(res, period_type, period_value);
    res->next = curr;
    res->sub_list = NULL;

    if (prev == NULL) {
        *start_item = res;
    } else {
        prev->next = res;
    }
    *res_item = res;

    return 1;
}

void init_Item_Data(List_Item *item, short period_type, short period_value) 
{
    if (item == NULL)
        return;
    item->data.period_type = period_type;
    item->data.period_value = period_value;
    item->data.count = 0;
    item->data.sum = 0;
    item->data.value = 0;
    item->data.min_value = 0;
    item->data.max_value = 0;
}


void update_Item_Data(List_Item *item, short new_value) 
{
    if (item == NULL)
        return;

    item->data.count++;
    item->data.sum += new_value;
    item->data.value = new_value;
    if (item->data.count == 1 || item->data.min_value > new_value)
        item->data.min_value = new_value;
    if (item->data.count == 1 || item->data.max_value < new_value)
        item->data.max_value = new_value;
}

void print_Line(short len, short incl_new_line) 
{
    for (size_t i = 0; i < len; i++) 
    {
        printf("-");
    }
    if (incl_new_line) 
        printf("\n");
}

short get_Column_Width(short col_no)
{
    switch (col_no)
    {
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 3;
        case 4:
            return 4; 
        case 5:
            return 6;  
        case 6:
            return 8;  
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 3;
    }
    return 0;
}

void print_Column_Caption(short col_no)
{
    switch (col_no)
    {
        case 1:
            printf("Year");
            break;
        case 2:
            printf("Month");
            break;
        case 3:
            printf("Day");
            break;
        case 4:
            printf("Hour");
            break;
        case 5:
            printf("Minute");
            break; 
        case 6:
            printf("   Count");
            break;  
        case 7:
            printf("MIN");
            break; 
        case 8:
            printf("Average");
            break; 
        case 9:
            printf("MAX");
            break; 
    }
}

short get_Line_Length(short max_level)
{
    short len = 0;
    for (size_t i = 1; i <= max_level; i++) 
    {
        len += get_Column_Width(i) + 2;
    }
    for (size_t i = 6; i <= 9; i++) 
    {
        len += get_Column_Width(i) + 2;
    }    
    return len -2;
}

void print_Data_Header(short max_level)
{
    short len = get_Line_Length(max_level);

    print_Line(len, 1);
    for (size_t i = 1; i <= max_level; i++) 
    {
        print_Column_Caption(i);    
        printf("  ");
    }

    for (size_t i = 6; i <= 9; i++) 
    {
        print_Column_Caption(i);    
        printf("  ");
    }
    printf("\n");
    print_Line(len, 1);
}

void print_Data_Line(short level, short max_level, short period[], List_Item *start_item) 
{
    if (level > max_level || start_item == NULL)
        return;

    short local_period[5] = {0};
    for (size_t i = 0; i < level-1; i++) {
        local_period[i] = period[i];
    }

    List_Item *curr_item = start_item;
    while (curr_item != NULL) 
    {
        local_period[level-1] = curr_item->data.period_value;
        printf("%4d", local_period[0]);
        for (size_t i = 2; i <= level; i++) {
            if (i==2)
                printf("  %5d", local_period[i-1]);
            if (i==3)
                printf("  %3d", local_period[i-1]);
            if (i==4)
                printf("  %4d", local_period[i-1]);
            if (i==5)
                printf("  %6d", local_period[i-1]);
        }

        for (size_t i = level +1; i <= max_level; i++) {
            printf("  ");
            print_Line(get_Column_Width(i), 0);
        }

        printf("  %8d  %3d  %7.2f  %3d\n", 
                    curr_item->data.count, 
                    curr_item->data.min_value, 
                    1.0 * curr_item->data.sum / curr_item->data.count,
                    curr_item->data.max_value);

        print_Data_Line(level + 1, max_level, local_period, curr_item->sub_list);
        curr_item = curr_item->next;
    }
}

void print_Data(Process_Params *proc_prm)
{
    print_Data_Header(proc_prm->group_by);    
    
    short period[5] = {0};
    print_Data_Line(1, proc_prm->group_by, period, proc_prm->start_item); 

    print_Line(get_Line_Length(proc_prm->group_by), 1);
}

int save_to_file(char fileName[])
{    
    FILE *f_out = fopen(fileName, "w");
    if (f_out == NULL) 
        return 2;
    fprintf(f_out, "%s", "text to save");
    fclose(f_out);
}
