void print_digit(char s[]) 
{
    int arr[10]={0,0,0,0,0,0,0,0,0,0};
    int pos = 0;
    while (s[pos]) 
    {
        if (s[pos]>='0' && s[pos]<='9') {
            arr[s[pos] - '0']++;
        }
        pos++;
    }
    
    for (int i=0; i<10; i++) 
    {
        if (arr[i])
            printf("%d %d\n", i, arr[i]);
    }
}
