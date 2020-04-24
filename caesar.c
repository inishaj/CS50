#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define UPPERCASE_A 65
#define UPPERCASE_Z 90
#define LOWERCASE_A 97
#define LOWERCASE_Z 122

bool checkKey(string s);
void convertToCipher(string, int);


int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //check if the key is an integar value
    else if(checkKey(argv[1]))
    {
        //printf("Success\n");
        //printf("%s\n", argv[1]);

        //prompt user to enter a string
        string plaintext = get_string("plaintext: ");
       //convert to ciphertext
        convertToCipher(plaintext, atoi(argv[1]));
    }
    else
    {
       printf("Usage: ./caesar key\n");
       return 1;
    }


    return 0;
}

bool checkKey(string s)
{
    int length = strlen(s);

    for(int i = 1; i < length; i++)
    {
        if(!isdigit(s[i]))
        return 0;
    }
    return 1;
}

void convertToCipher(string text, int key)
{
    int length = strlen(text);
    int delta = 0;

    for(int i = 0; i < length; i++)
    {
        //if the character is upper case
        if((text[i] >= 'A') && (text[i] <='Z'))// && ((text[i]+key) > UPPERCASE_Z))
        {
            //delta = (text[i]+key) - UPPERCASE_Z;
            //text[i] = UPPERCASE_A + delta - 1;

            text[i] = (((text[i] + key) - UPPERCASE_A) % 26) + UPPERCASE_A;
        }
        else if ((text[i] >= 'a') && (text[i] <='z'))// && ((text[i]+key)> LOWERCASE_Z))
        {
            //delta = (text[i]+key) - LOWERCASE_Z;
            //text[i] = LOWERCASE_A + delta - 1;
            text[i] = (((text[i] + key) - LOWERCASE_A) % 26) + LOWERCASE_A;
        }
        //else //if(((text[i] >= 'A') && (text[i] <='Z')) ||((text[i] >= 'a') && (text[i] <='z')))
       // {
         
       // }
    }
    printf("ciphertext: %s\n", text);
}