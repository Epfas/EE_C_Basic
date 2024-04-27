struct Temperature_Data
{
    long sum;
    int count;
    short period_type;
    short period_value;
    short value;
    short min_value;
    short max_value;
};
typedef struct Temperature_Data Temperature_Data;

struct List_Item
{
    Temperature_Data data;
    struct List_Item *next;
    struct List_Item *sub_list;
};
typedef struct List_Item List_Item;


struct Process_Params
{
    int start_date;
    short start_time;
    int end_date;
    short end_time;
    int group_by;
    char filename[250];

    int lines_total;
    int lines_error;
    int lines_skip;

    List_Item *start_item;
    List_Item *curr_item;
};
typedef struct Process_Params Process_Params;

void init_Process_Params(Process_Params *proc_prm);
void print_Process_Params(Process_Params *proc_prm); 

int load_Data(Process_Params *proc_prm);

int push_Data(Process_Params *proc_prm, int date, short time, short temp);

short get_List_Item(short period_type, short period_value, List_Item **start_item, List_Item **res_item);
short insert_List_Item(short period_type, short period_value, List_Item **start_item, List_Item **res_item);

void init_Item_Data(List_Item *item, short period_type, short period_value) ;
void update_Item_Data(List_Item *item, short new_value); 

void print_Data(Process_Params *proc_prm);