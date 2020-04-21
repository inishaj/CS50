#include<stdio.h>
#include<cs50.h>
#include<math.h>

float getChange(void);

int main(void)
{
    int count = 0;
    int cents = 0;
    float change = getChange();
    cents = round(change *100);
    count = cents/25;
    //printf("count after 25: %i\n", count);
    //printf("cents after 25: %i\n", cents);
    if((cents %=25) > 0)
    {
        count += cents/10;
        //printf("count after 10: %i\n", count);
        //printf("cents after 10: %i\n", cents);
    }
    if((cents %=10) > 0)
    {
        count += cents/5;
        //printf("count after 5: %i\n", count);
        //printf("cents after 5: %i\n", cents);
    }
    if((cents %= 5) > 0)
    {
        count += cents;
        //printf("count after 1: %i\n", count);
        //printf("cents after 1: %i\n", cents);
    }
    printf("the count is: %i\n", count);
}
float getChange(void)
{
    float input = 0;
    do
    {
        input = get_float("Amount of change required :");
        
    }while (input <= 0);
    printf("the change required is: %.2f\n", input);
    return input;
}
