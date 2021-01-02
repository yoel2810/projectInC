#include <stdio.h>
#include "question2.h"

#define LINE 256
#define WORD 30

int getline1(char s[])
{
    int counter = 0;
    int i = 0;
    while (*(s + i) != '\n' && *(s + i) != '\0' && i < LINE)
    {
        counter++;
        i++;
    }
    return counter;
}

int getword(char w[])
{
    int i = 0;
    while (*(w + i) != 13 && *(w + i) != '\n' && *(w + i) != '\t' && *(w + i) != ' ' && *(w + i) != '\0' && i < WORD)
    {
        i++;
    }
    return i;
}

int containsWord (char* str1, char* str2)
{
    
    int len1 = getword(str1);
    int len2 = getword(str2);

    if (len2 > len1)
    {
        return 0;
    }

int j = 0;
    for (int i = 0; i < len1; i++)
    {
        if (*(str1+i) == *(str2+j))
        {
            j++;
        }
        else
        {
            j = 0;
        }
        if (j==len2)
        {
            return 1;
        }
           
    }
    return 0;
}

int substring(char* str1, char* str2)
{
    int len1 = getword(str1);
    int len2 = getword(str2);

    if (len2 > len1)
    {
        return 0;
    }
    
    for (int i = 0, j = 0; i < len1; i++)
    {
        
        if (*(str1 + i) == *(str2 + j))
        {
            j++;
        }
        
        if (j == len2)
        {
            return 1;
        }
    }
    return 0;
}

int similar(char* s, char* t, int n)
{
    if (substring(s, t) == 0)
    {
        return 0;
    }

    /*if (s[0]=='c'&&s[3]=='s')
    {
        printf("%d + %d = %d\n",getword(t), n, getword(s));
        printW(s);

    }*/
    

    return (getword(t) + n == getword(s));
}

char* printW(char w[])
{
    int i =0;
    while (w[i] != ' ' && w[i] != '\t' && w[i] != '\n' && w[i] != '\0')
    {
        printf("%c",w[i]);
        i++;
    }
    printf("\n");
    return w;

}

void printL(char w[])
{
    int i = 0;
    while (w[i] != '\n' && w[i] != '\0')
    {
        printf("%c",w[i]);
        i++;
    }
    printf("\n");
}

void print_lines(char* str)
{
    char c;
    scanf("%c", &c);
    char text[LINE];// = "this is a text file\nlooking for the word cat\nthe program should print alse cats\nand crat but it shouldn't\nprint the word caats";

    fgets(text, LINE, stdin);
    
    //for (int i = 0; *(text + i) != '\0' && i < 250 * LINE; i = 1 + i + getline1((text + i)))
    for (int x = scanf("%[^\n]%*c", text); x != -1; x = scanf("%[^\n]%*c", text))
    {
        
        int flag = 0;
        int len = getline1(text);

        for (int j = 0; j < LINE && j < len; j = 1 + j + getword(text + j))
        {
            if (containsWord(text + j, str))
            {
                flag = 1;
            }
        }
        if (flag)
        {
            printf("%s\n", text);
        }
    }
}

void print_similar_words(char* str)
{
    char c;
    scanf("%c", &c);
    char text[LINE];// = "this is a text file\nlooking for the word cat\nthe program should print alse cats\nand crat but it shouldn't\nprint the word caats";

    fgets(text, LINE, stdin);
    
    //for (int i = 0; *(text + i) != '\0' && i < 250 * LINE; i = 1 + i + getline1((text + i)))
    for (int x = scanf("%[^\n]%*c", text); x != -1; x = scanf("%[^\n]%*c", text))
    {
        int len = getline1(text);
        for (int j = 0; j < LINE && j < len; j = 1 + j + getword((text + j)))
        {
            //printW(text + i + j);
            if (similar(text + j, str, 0) || similar((text + j), str, 1))
            {
                printW(text + j);
            }
        }
    }
}

int main()
{
    char w [WORD];// = {'c','a','t'};
    scanf("%s", w);
    char c;
    scanf("%c", &c);
    scanf("%c", &c);
    
    if (c=='a')
    {
        print_lines(w);   
    }
    else
    {
        print_similar_words(w);
    }
}