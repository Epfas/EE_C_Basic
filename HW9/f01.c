void sort_array(int size, int a[]) {
    int replaceCount; 
    do 
    {
        replaceCount = 0;
        for (int i = 1; i < size; i++) 
        {
            if (a[i-1] > a[i]) {
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                replaceCount++;
            }
        }
    } while (replaceCount);
}
