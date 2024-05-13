void swap_negmax_last(int size, int a[])
{
    int pos = -1;
    int max = 0;
    for (int i=0; i<size; i++) 
    {
        if (a[i] <0 && (pos == -1 || max < a[i])) {
            pos = i;
            max = a[i];
        }    
    }
    
    if (pos >= 0) {
        int x = a[size -1];
        a[size-1] = a[pos];
        a[pos] = x;
    }
}
