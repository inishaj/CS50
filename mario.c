#include <cs50.h>
#include <stdio.h>
int getPyramidHeight(void);

int main(void)
{
    int height = getPyramidHeight();
    int n = 1;
    //for nth line, print space (height - n) times and then hash n times,2 spaces, hash for    // n times 
    while(n < height+1)
    {
        //print first set of spaces
        for(int i = 0; i < (height - n); i++)
        {
            printf(" ");
        }
        //print set of hashes
        for(int j = 0; j < n; j++)
        {
            printf("#");
        }
        //print two spaces in between
        printf("  ");
        for(int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
        n++;
    }

}

int getPyramidHeight(void)
{
    int i = 0;
    do
    {
        i = get_int("How tall you the pyramid to be? "); 
    }
    while (i < 1 || i > 8); 
    return i;
}
