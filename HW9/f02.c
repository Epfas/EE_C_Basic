void sort_even_odd(int n, int a[]) 
{
    int replaceCount; 
    do 
    {
        replaceCount = 0;
        for (int i = 1; i < n; i++) 
        {
            if ((a[i-1] % 2 != 0) && (a[i] %2 == 0)) {
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                replaceCount++;
            }
        }
    } while (replaceCount);
}
