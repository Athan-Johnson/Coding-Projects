/* the goal of this program is to convert a string of hexadecimal digits into the equivalent integer value
 * current iteration only works on positive inputs
 * Example input: 	"0x1aD" or "fF" or "0X111"
 * Output: 		the corresponding integer value
 * Author: Athan Johnson
 * Created: 1/19/2025
 * Modified:
 */

#include <stdio.h>
#include <ctype.h>
// tolower(c): converts a char into a lower case char
// isdigit(c): returns if a char is a digit or not

// this tells us where we are in the prefix. If it doesn't start with one we go straight to
// end so we know to ignore that logic, but if we see a zero then we go to x, then if we see
// an x we go to end. This helps to make sure that an x anywhere else in the string correctly
// returns an error
enum prefix { zero, x, end };
// declare a global variable here
enum prefix pre = zero;

int htoi(int num, char chr);

int main()
{
	// decalre variables
	int ans = 0;
	char c = ' ';

	// go through the input one by one
	while ((c = getchar()) != EOF)
	{
		if ((ans = htoi(ans, c)) > -1) // if this is false then we either errored or encountered \n or \0
		{				// otherwise ans is already assigned in the if statement
		}
		else if (c == '\n' || c == '\0') // input over, print answer and end
		{
			printf("%d\n", ans);
			return 0;
		}
		else // there must have been an error in the input
		{
			return 0;
		}
	}

	printf("%d\n", ans);
	return 0;
}


// takes in the current number we're working with, and the next 
// letter, then outputs the addition of the two
// right now this only works on positive inputs, an output of -2 means the string is over and -1 means an error
int htoi(int num, char chr)
{
	// the input is over, just return the answer we were given
	if (chr == '\n' || chr == '\0')
	{
		return num;
	}
	// we are at the start of the string and it starts with zero. then we move onto
	// the next stage of the prefix and do nothing else. otherwise we jump to the end
	// and begin reading the string
	if (pre == zero && chr == '0')
	{
		pre = x;
	}
	// in this case we are at the x part of the prefix and make sure that we don't
	// have a digit and the letter really is an x. in that case we now move to the
	// end and have sucessfully gotten past the prefix without throwing an error
	// or reading it as part of the hexadecimal string
	else if (pre == x && !isdigit(chr) && tolower(chr) == 'x')
	{
		pre = end;
	}
	// we make sure to set the prefix to end and see if it's a digit, if it is we
	// multiply what we already have by sixteen and add the digit, if not we still
	// multiply what we already have by sixteen and now we calculate what it is
	// between a and f and add that
	else
	{
		pre = end;
		if (isdigit(chr)) // c is a digit represented as a char
		{
			num = num*16 + chr - '0';
		}
		else // chr is either a through f or somethine else that we should throw
		     // an error about
		{
			chr = tolower(chr);
			if (chr < 'a' || chr > 'f') // this is outside the accetable range
			{
				printf("Error! The hexadecimal string has an "
						"unrecognized character inside!\n");
				return -1;
			}
			else
			{
				num = num*16 + chr - 'a' + 10;
			}
		}
	}
}
