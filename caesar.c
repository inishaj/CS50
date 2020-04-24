#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define UPPERCASE_A 65
//#define UPPERCASE_Z 90
#define LOWERCASE_A 97
//#define LOWERCASE_Z 122
#define TOTAL_ALPHABETS 26

bool checkKey(string s);
void convertToCipher(string, int);


int main(int argc, string argv[])
{
    //check if there is no key or the key is non-numeric
    if((argc != 2) || (!checkKey(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //prompt user to enter plain text
        string plaintext = get_string("plaintext: ");
       //convert to ciphertext
        convertToCipher(plaintext, atoi(argv[1]));
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

    for(int i = 0; i < length; i++)
    {
        //if the character is upper case
        if((text[i] >= 'A') && (text[i] <='Z'))
        {
            text[i] = (((text[i] + key) - UPPERCASE_A) % TOTAL_ALPHABETS) + UPPERCASE_A;
        }
        else if ((text[i] >= 'a') && (text[i] <='z'))
        {
            text[i] = (((text[i] + key) - LOWERCASE_A) % TOTAL_ALPHABETS) + LOWERCASE_A;
        }

    }
    printf("ciphertext: %s\n", text);
}