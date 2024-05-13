void change_max_min(int size, int a[])
{
    int min_pos = -1;
    int max_pos = -1;
    
    for (int i = 0; i < size; i++) {
        if (min_pos == -1 || a[i] < a[min_pos]) 
            min_pos = i;
        if (max_pos == -1 || a[i] > a[max_pos]) 
            max_pos = i;
    }
    
    if (min_pos != max_pos) {
        int x = a[min_pos];
        a[min_pos] = a[max_pos];
        a[max_pos] = x;
    }
}
