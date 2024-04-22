#include <stdio.h>

float sinus (float degree) {
    float pi = 3.141592;
    float rad = degree * pi /180.;
    float res = rad;
    float power_x = rad;
    int power = 1;
    float delta;
    long unsigned int fact_x = 1;
    int sign = -1;
    // sin(x) = x - x3/3! + x5/5! - x7/7! + ...
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
    printf("%.3f", sinus(x));

    return 0;
}
