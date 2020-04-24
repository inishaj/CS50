#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//MACROS
#define UPPERCASE_A 65
//#define UPPERCASE_Z 90
#define LOWERCASE_A 97
//#define LOWERCASE_Z 122
#define TOTAL_ALPHABETS 26

//Functions declarations
bool checkKey(int, string);
void convertToCipher(string, string);

//main
int main(int argc, string argv[])
{
    //check if key is legitimate
    if(checkKey(argc,argv[1]))
    {
        //printf("key not ok \n");
        return 1;
    }
    else
    {
        //printf("Success\n");
        //prompts user to enter plaintext
        string plaintext = get_string("plaintext: ");
        //convert to ciphertext
        convertToCipher(plaintext, argv[1]);

    }

    return 0;
}
    // check invalid characters in key
    // check duplicate/multiple duplicate characters in key

bool checkKey(int number_arguments, string s) // 1 means key is not OK
{
    int length = strlen(s);
    char c;

    if(number_arguments !=2)
    {
       printf("Usage: ./substitution key\n");
       return 1;
    }
    else if(strlen(s) != 26)
    {
       printf("Key must contain 26 characters.\n");
       return 1;
    }
    else
    {
      for(int i = 0; i < length; i++)
      {
        if(!isalpha(s[i]))
        {
          //  printf("alphabet problem\n");
            return 1;
        }
        else
        {   //check for duplicate
            c = s[i];
            for(int j = i+1; j < length; j++)
            {
               if (c == s[j])
               {
                  //printf("duplicate problem, c:%c, text: %c\n", c, s[i]);
                  return 1;
               }
            }
        }

      }
    }
    return 0;
}

void convertToCipher(string text, string key)
{
    int pos = 0; //character position in the alphabets
    int length = strlen(text);

    //check for case for both text and key

    for(int i = 0; i < length; i++)
    {

    //check if plain text is upper
    if((text[i] >= 'A') && (text[i] <='Z'))
        {
            pos = text[i] - UPPERCASE_A;
            if((key[pos] >= 'A') && (key[pos] <='Z'))
            {
                text[i] = key[pos];
            }
            else
            {
                text[i] = key[pos] - 32;
            }

        }
    else if ((text[i] >= 'a') && (text[i] <='z'))
        {
            pos = text[i] - LOWERCASE_A;
            if((key[pos] >= 'a') && (key[pos] <='z'))
            {
                text[i] = key[pos];
            }
            else
            {
                text[i] = key[pos] + 32;
            }
        }
    }

    printf("ciphertext: %s\n", text);
}
