/* This is a toy example that shows the difference between j++ and ++j
 * In this example we are writing a function to squeeze all instances of a letter out
 * of a string, and if we were to use ++j it would increment j too early, before the 
 * operation carries out
 * Author: Athan Johnson
 * Created: 1/20/2025
 * Modified: 
 */

/* squeeze:  delete all c from s */
void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s [i] != '\0'; i++)
	{
		if (s[i] != c)
		{
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

// the logic here is equivelent to:
// 	if (s[i] != c)
// 	{
// 		s[j] = s[i];
// 		j++;
// 	}
