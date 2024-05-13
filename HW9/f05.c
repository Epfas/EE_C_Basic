int find_max_array(int size, int a[]) 
{
    int max_value; 
    
    for (int i = 0; i < size; i++) 
    {
        if (!i || a[i] > max_value) {
            max_value = a[i];
        }
    }
    return max_value;
}
