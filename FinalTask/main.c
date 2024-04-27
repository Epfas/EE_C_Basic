#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
// #include "data_model.h"
#include "app_argv_handler.h"

int main(int argc, char *argv[]) 
{
    print_welcome_info();
    
    Process_Params proc_prm;
    init_Process_Params(&proc_prm);

    if (!handle_cmd_args(argc, argv, &proc_prm)) {
        return 0;
    } 

    print_Process_Params(&proc_prm);

    if (!load_Data(&proc_prm)) {
        printf("\nERROR: data is not loaded from file.\n");
        return 0;
    }

    print_Data(&proc_prm);

    printf("\n\nDONE!\n");

    return 0;
}