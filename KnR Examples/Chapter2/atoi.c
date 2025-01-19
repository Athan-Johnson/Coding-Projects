/* This program is a simple copying of the example atoi function in KnR to understand how it works by writing it out
 * Author: Athan Johnson
 * Created: 1/19/2025
 * Modified:
 */

/* atoi:  convert s to integer */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
