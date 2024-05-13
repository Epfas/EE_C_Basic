int compression(int a[], int b[], int N) 
{
    int size = 0;
    int last = 0;
    int cnt = 0;
    
    for (int i = 0; i <= N; i++) 
    {
        if (i == N || last != a[i]) {
            b[size] = cnt;
            size++;
            cnt = 0;
        }

        if (i < N) {
            last = a[i];    
            cnt++;        
        }    
    }
    return size;
}
