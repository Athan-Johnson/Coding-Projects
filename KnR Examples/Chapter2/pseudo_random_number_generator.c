/* This is a toy example of how to make a pseudo-random number generator. Although it does use globals
 * if I was to try and implement this in practice this could be avoided somehow that I'll figure out
 * then if I ever come to that
 * Author: Athan Johnson
 * Created: 1/19/2025
 * Modified:
 */

unsigned long int next = 1;

/* rand:  return pseudo-random integer on 0 to 32767 */
int rand(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536) % 32768;
}

/* srand:  set seed for rand() */
void srand(unsigned int seed)
{
	next = seed;
}
