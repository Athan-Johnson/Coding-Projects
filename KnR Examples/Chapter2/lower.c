/* this is a simple toy example of the function that converts an upper case ascii letter to a lower case
 * Author: Athan Johnson
 * Created: 1/19/2025
 * Modified:
 */

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
