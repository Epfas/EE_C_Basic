int count_bigger_abs(int n, int a[]) 
{   
    int max;
    for (int i = 0; i < n; i++) 
    {
        if (i==0 || max < a[i]) 
            max = a[i];
    }
    max *= -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) 
    {
        if (max > a[i]) 
            cnt++;
    }
    return cnt;
}
