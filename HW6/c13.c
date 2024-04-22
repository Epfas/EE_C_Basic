#include <stdio.h>

float cosinus (float degree) 
{
    float pi = 3.141592;
    float rad = degree * pi /180.;
    float res = 1;
    float power_x = 1;
    int power = 0;
    float delta;
    long unsigned int fact_x = 1;
    int sign = -1;
    // cos(x) = 1 - x2/2! + x4/4! - x6/6! + ...
    do 
    {
       power += 2;
       power_x *= rad * rad;
       fact_x *= power * (power -1);
       delta = power_x / fact_x;
       
       if (delta > 0.0005) {
           res += delta * sign;
       }
       sign *= -1;
    }
    while (power < 10 && delta > 0.0005);
    
    return res;
}

int main(void) 
{
    float x; 
    scanf("%f", &x);
    printf("%.3f", cosinus(x));

    return 0;
}
