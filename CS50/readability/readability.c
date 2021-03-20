#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string t, int s);
int count_words(string t, int s);
int count_sentences(string t, int s);

int main(void)
{
    //preparation
    string texts = get_string("Text: ");
    int n = strlen(texts);
    
    //letters' counter -printf("%i letter(s)\n", l);
    int l = count_letters(texts, n);
    
    //words' counter - printf("%i word(s)\n", w);
    int w = count_words(texts, n);
    
    //sentences' counter - printf("%i sentence(s)\n", c);
    int c = count_sentences(texts, n);

    //formula's implementation
    //average number of letters per 100 words
    float L = (100 * l) / w;
    
    //average number of sentences per 100 words
    float C = (100 * c) / w;
    
    float index = (0.0588 * L) - (0.296 * C) - 15.8;
    index = roundf(index);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", (int) index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}









// letters' counter function
int count_letters(string t, int s)
{
    int sum = 0;
    for (int i = 0; i < s; i++)
    {
        if (t[i] >= 'a' && t[i] <= 'z')
        {
            sum++;
        }
        else if (t[i] >= 'A' && t[i] <= 'Z')
        {
            sum++;
        }
    }
    return sum;
}

//words' counter function
int count_words(string t, int s)
{
    int sum = 0;
    
    for (int i = 0; i <= s; i++)
    {
        if (t[i] == ' ' || t[i] == '\0')
        {
            sum++;
        }
    }
    return sum;
}

//sentences' counter function
int count_sentences(string t, int s)
{
    int sum = 0;
    
    for (int i = 0; i < s; i++)
    {
        if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            sum++;
        }
    }
    return sum;
}
