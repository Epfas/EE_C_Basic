#include "data_model.h"

void print_welcome_info(); 
void print_help_info();

int eveluate_textparam_to_date_time(char source[], short is_end, int *date, short *time); 

int handle_cmd_args(int argc, char *argv[], Process_Params  *proc_prm);