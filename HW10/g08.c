#include <stdio.h>
#include <string.h>

int get_num(int from_pos, int to_pos, char str[]) 
{
    int res = 0;
    int mult = 1;

    for (int i = to_pos; i >= from_pos; i--) 
    {
        res += mult * (str[i] - '0');
        mult *= 10;
    }
    if (from_pos > 0 && str[from_pos-1] == '-')
        res *= -1;
        
    return res;
}

int main() 
{
    char str_arr[1000];
    int num_arr[1000];
    int size = 0;

    FILE *f_in = fopen("input.txt", "r");
    if (f_in == NULL) 
        return 1;
    fscanf(f_in, "%[^\n]", &str_arr);
    fclose(f_in);

    int start_pos = -1;
    int end_pos = -1;
    int len = strlen(str_arr);
    for ( int i = 0; i < len; i++) 
    {
        if (str_arr[i] >= '0' && str_arr[i] <= '9') {
            if (start_pos == -1)
                start_pos = i;
            end_pos = i;
        } else {
            if (start_pos >= 0) {
                num_arr[size++] = get_num(start_pos, end_pos, str_arr);
                start_pos = -1;
                end_pos = -1; 
            }
        }
    }
    if (start_pos >= 0) {
        num_arr[size++] = get_num(start_pos, end_pos, str_arr);
    }
    
    if (size) {
        for (int i = 0; i < size; i++) 
        {
            int is_replaced = 0;
            for (int j = 1; j < size -i; j++) 
            {
                if (num_arr[j] < num_arr[j-1] ) {
                    int x = num_arr[j];
                    num_arr[j] = num_arr[j-1];
                    num_arr[j-1] = x;
                    is_replaced = 1;
                }
            }
            if (!is_replaced)
                break;
        }
    }


    FILE *f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
        return 2;
    if (size) {
        for (int i = 0; i < size; i++) 
        {
           fprintf(f_out, " %d", num_arr[i]);        
        }
    }
    fclose(f_out);

    return 0;
}
