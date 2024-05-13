int sum_between_ab(int from, int to, int size, int a[])
{   
    int sum = 0;
    if (from > to) {
        int x = from;
        from = to;
        to = x;
    }
    
    for (int i = 0; i < size; i++) 
    {
        if (a[i] >= from && a[i] <= to)
            sum += a[i];
    }
    return sum;
}
