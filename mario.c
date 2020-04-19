#include <cs50.h>
#include <stdio.h>
int get_pyramidHeight(void);

int main(void)
{
    int height = get_pyramidHeight();
    for(int i = 1; i < height+1; i++)
    {
        for(int j = 0; j < height-i; j++)
        {
            printf(" "); 
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");   
        }
           printf("\n");        
    }

}

int get_pyramidHeight(void)
{
 int i = 0;
 do
 {
    i = get_int("How tall you want the pyramid?\n");
 }while(i<1 || i>8);
 return i;
 }
