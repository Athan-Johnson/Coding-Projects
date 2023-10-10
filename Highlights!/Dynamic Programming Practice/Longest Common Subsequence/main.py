# Goal: Given two strings, find the length of their longest common subsequence.
def longest_common_subsequence(string_one, string_two):
    # Check if either of the input strings is empty, in which case the common subsequence is empty.
    if len(string_one) == 0 or len(string_two) == 0:
        return 0

    # get the lengths of the input strings
    m = len(string_one)
    n = len(string_two)

    # Create a 2D array (matrix) to store the lengths of common subsequences.
    sub_str_sizes = [[0] * (n + 1) for _ in range(m + 1)]

    # Fill in the matrix using dynamic programming.
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if string_one[i - 1] == string_two[j - 1]:
                # If the characters match, extend the common subsequence by one.
                sub_str_sizes[i][j] = sub_str_sizes[i - 1][j - 1] + 1
            else:
                # If the characters don't match, take the maximum of the two adjacent cells.
                sub_str_sizes[i][j] = max(sub_str_sizes[i - 1][j], sub_str_sizes[i][j - 1])

    # The value at sub_str_sizes[m][n] contains the length of the longest common subsequence.
    return sub_str_sizes[m][n]

if __name__ == '__main__':
    print(longest_common_subsequence('', ''))

# this code was commented by chatGPT haha