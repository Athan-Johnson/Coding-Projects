/* This program creates two functions, one that converts escape sequences like
 * \n and \t into visible "\n" and "\t" when copying the string t to s, and
 * the other function reverses this process.
 * Author: Athan Johnson
 * Created: 1/28/2025
 * Modified: 1/28/2025
 */

#include <stdio.h>

char* escape(char* s, char* t);
char* escape_reversed(char* s, char* t);

int main()
{
}

char* escape(char* s, char* t)
{
	int t_index = 0;
	int s_index = 0;
	while ((c = t[t_index]) != '\0')
	{
		switch (c) 
		{
			case '\n':
				s[s_index] = '\\';
				s[s_index+1] = 'n';
				s_index += 2;
				break;
			case '\t':
				s[s_index] = '\\';
				s[s_index+1] = 't';
				s_index += 2;
				break;
			case '\a':
				s[s_index] = '\\';
				s[s_index+1] = 'a';
				s_index += 2;
				break;
			case '\b':
				s[s_index] = '\\';
				s[s_index] = 'b';
				s_index += 2;
				break;
			case '\f':
				s[s_index] = '\\';
				s[s_index] = 'f';
				s_index += 2;
				break;
			case '\r':
				s[s_index] = '\\';
				s[s_index] = 'r';
				s_index += 2;
				break;
			case '\v':
				s[s_index] = '\\';
				s[s_index] = 'v';
				s_index += 2;
				break;



		}
	}
}
