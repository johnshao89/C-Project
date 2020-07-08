#include<stdio.h>
#include<string.h>
#define MAX 81
char *string_in(char *source, char *target);
char *s_gets(char *st, int n);
int main(void)
{
    char input[MAX];
    char search[MAX];
    char *output=string_in(input, search);
    while((output=string_in(input, search))!=NULL)
    puts(output);
    puts("Done!");
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i=0;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while(st[i]!='\n' && st[i]!='\0')
        i++;
        if(st[i]=='\n')
        st[i]='\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}
char *string_in(char *string, char *sub_string)
{
    //char to_serach[MAX], to_be_searched[MAX];
    puts("Enter a string to be searched:");
    s_gets(string, MAX);
    puts("Enter what you want to search:");
    s_gets(sub_string, MAX);
    int i;
    while(*string!='\0')
    {
        int i=0;
        while(*(string+i) == *(sub_string+i))
        {
            i++;
            if(*(sub_string+i)=='\0')
            return string;
        }
        string++;

    }
    return NULL;
}

/*Reference:
#include <stdio.h>

#define LIMIT 50

char * string_in(char *string, char *substring);
char * get(char *string, int n);

int main(void)
{
	// test string_in()

	char string[LIMIT];
	char substring[LIMIT];

	char *substr_loc;

	printf("Enter a string: ");
	get(string, LIMIT);
	while (string[0] != '\0')
	{
		printf("Enter a substring to look for: ");
		get(substring, LIMIT);

		substr_loc = string_in(string, substring);

		if (substr_loc == NULL)
			printf("%s not in %s\n", substring, string);
		else
			printf("%s found in %s at index %lu\n",
				   substring, string, substr_loc - string);

		printf("Enter a string (empty line to quit): ");
		get(string, LIMIT);
	}

	puts("Bye");

	return 0;
}

char * string_in(char *string, char *substring)
{
	// checks if substring is in string
	// returns pointer to first location of substring
	// in string or NULL if substring not in string

	int i;

	while (*string != '\0')
	{
		i = 0;

		// check for substring at current location
		while (*(string + i) == *(substring + i))
		{
			i++;

			// if next char in substring is null, then match
			// is found. return current location
			if (*(substring + i) == '\0')
				return string;
		}

		string++;
	}

	// no match
	return NULL;
}


char * get(char *string, int n)
{
	// wrapper for fgets that replaces first newline with null

	char *return_value = fgets(string, n, stdin);

	while (*string != '\0')
	{
		if (*string == '\n')
		{
			*string = '\0';
			break;
		}

		string++;
	}

	return return_value;
}
*/