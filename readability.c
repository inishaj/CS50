#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int countLetters(string);
int countWords(string);
int countSentences(string);

int main(void)
{
    int count_letters, count_words, count_sentences;
    float average_letter, average_sentence;
    float index;
    string text = get_string("Text: ");
    
    //Count letters
    count_letters = countLetters(text);
   //printf("Count of letters: %i\n", count_letters);
    count_words = countWords(text);
    //printf("Count of words: %i\n", count_words);
    count_sentences = countSentences(text);
    //printf("Count of Sentences: %i\n", count_sentences);

    average_letter = ((float)count_letters/(float)count_words) * 100;

    average_sentence = ((float)count_sentences/(float)count_words) * 100;
    
    index = round((0.0588 * average_letter) - (0.296 * average_sentence) - 15.8);
   
    //check index outliers
   if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}

int countLetters(string s)
{
    int string_length = strlen(s);
    int count = 0;
    for(int i = 0; i < string_length; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z'))
        {
            count++;
        }
    }
    return count;
}
int countWords(string s)
{
    int count = 0;
    int string_length = strlen(s);
    for(int i = 0; i < string_length; i++)
    {
        if(s[i] == ' ')
        count++;
    }
    return count+1;
}

int countSentences(string s)
{
    int count = 0;
    int string_length = strlen(s);
    for(int i = 0; i < string_length; i++)
    {
        if((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))
        count++;
    }
    return count;
}