# we are finding the longest common substring between two given strings. A
# substring means that it must be consecutive
# We will move through the two strings using i and j, and compare
def lc_sub_str(string1, string2):
    lengths = [[0] * (len(string2) + 1) for _ in range(len(string1) + 1)]  # make an array of all zeros
    max_len = 0
    end_pos = 0

    for i in range(1, len(string1) + 1):  # we start these indices at one because the first row and
        for j in range(1, len(string2) + 1):  # column of the array is zeros no matter what
            if string1[i - 1] == string2[j - 1]:
                lengths[i][j] = lengths[i - 1][j - 1] + 1
                if lengths[i][j] > max_len:  # if we found a substr that's bigger
                    max_len = lengths[i][j]  # then record that length
                    end_pos = i  # and mark its position

    return string1[end_pos - max_len:end_pos]


# Max Sum Increasing Subsequence Problem.
# Find a subsequence of a given sequence such that the subsequence
# sum is as high as possible, and the subsequence’s elements are
# sorted in ascending order.
def max_sum_incr_subseq(numbers):
    # first start by incrementing through numbers from 0 to i instead of from 0 to n
    # then we will find the answer at i in terms of the answers that came before
    #   -this requires us to check each that came before in this case

    sums = [0 for _ in range(len(numbers))]
    max_sum = 0
    max_sum_index = 0

    # we have to check both that this is a positive
    # number, and that the number is larger than the last
    # (negative numbers can be immediately ruled out as they
    # only make the sum smaller, and an array of all negative
    # elements can be ruled out because a subsequence of zero
    # elements would be larger)
    for i in range(len(numbers)):
        if numbers[i] > 0:
            curr_max_sum = 0
            curr_max_index = -1
            for j in range(0, i):
                if ((numbers[j] > 0)
                        and (numbers[j] < numbers[i])
                        and (curr_max_sum < sums[j] + numbers[i])):
                    curr_max_sum = sums[j] + numbers[i]
                    curr_max_index = j

            if curr_max_index < 0:  # meaning this number is smaller than all the last
                sums[i] = numbers[i]
            else:
                sums[i] = sums[curr_max_index] + numbers[i]
                if sums[i] > max_sum:
                    max_sum = sums[i]
                    max_sum_index = i
        else:
            sums[i] = 0

    ans = ""
    for i in range(max_sum_index, -1, -1):  # this includes the zeroth index
        if (sums[i] == max_sum) and (max_sum > 0):
            ans = str(numbers[i]) + ", " + ans
            max_sum = max_sum - numbers[i]

    return ans


# we want to find the number of times a subsequence appears in a string
# for details consult the assignment
def subseq_in_str(string, sub_str):
    matches = [[0] * (len(string) + 1) for _ in range(len(sub_str) + 1)]
    for _ in range(len(string) + 1):
        matches[0][_] = 1

    for i in range(1, len(sub_str) + 1):
        for j in range(1, len(string) + 1):
            if string[j - 1] == sub_str[i - 1]:
                matches[i][j] = matches[i][j - 1] + matches[i - 1][j - 1]
            else:
                matches[i][j] = matches[i][j - 1]

    return matches[len(sub_str)][len(string)]


# given two similar strings, efficiently list out all the differences between them
def diff_utility(string1, string2):
    # the first step here is to implement LCSsubseq
    lengths = [[0] * (len(string2) + 1) for _ in range(len(string1) + 1)]  # make an array of all zeros
    for i in range(1, len(string1) + 1):
        for j in range(1, len(string2) + 1):
            if string1[i-1] == string2[j-1]:
                lengths[i][j] = lengths[i-1][j-1] + 1
            else:
                lengths[i][j] = max(lengths[i-1][j], lengths[i][j-1])

    max_len = lengths[len(string1)][len(string2)]
    index_i = len(string1)
    index_j = len(string2)
    longest_common_subseq = ""
    while max_len > 0:
        if string1[index_i - 1] == string2[index_j - 1]:
            longest_common_subseq = string1[index_i - 1] + longest_common_subseq
            max_len = max_len - 1
            index_i = index_i - 1
            index_j = index_j - 1
        else:
            if lengths[index_i - 1][index_j] > lengths[index_i][index_j - 1]:
                index_i = index_i - 1
            else:
                index_j = index_j - 1

    index_i = 0
    index_j = 0
    index_lcs = 0
    ans = ""

    # the weird looking min(index, length of string - 1) that you're seeing in this loop is to
    # prevent out of bounds errors. Basically if one of the strings gets fully indexed before the
    # others then it's indexer will end at the length of the string...and since counting starts
    # at zero this means it's out of bounds. So grabbing the minimum between the indexer and the
    # length of the string was the easiest way I knew of solving this. Hey I don't like how it
    # looks either, if you have a better way then please tell me
    while (index_i < len(string1)) or (index_j < len(string2)):
        if (longest_common_subseq[min(index_lcs, len(longest_common_subseq) - 1)]
                is string1[min(index_i, len(string1) - 1)]
                is string2[min(index_j, len(string2) - 1)]):
            ans += longest_common_subseq[index_lcs] + " "
            index_lcs += 1  # i just learned i can do += haha
            index_i += 1
            index_j += 1
        elif (longest_common_subseq[min(index_lcs, len(longest_common_subseq) - 1)]
              is string1[min(index_i, len(string1) - 1)]):  # there is a char that was inserted in string 2
            ans += "+" + string2[index_j] + " "
            index_j += 1
        else:  # there is a character in string 1 that isn't in string 2
            ans += "-" + string1[index_i] + " "
            index_i += 1

    return ans


if __name__ == '__main__':

    # Question 1 inputs here
    first_string = "Every cloud has a silver lining."
    second_string = "Actions speak louder than words."

    # Question 2 input here
    test_arr = [732, -143, 586, -276, 451, -825, 374, -617, -299, 925]

    # Question 3 input here
    example_string = "The complexity of this algorithm is O(n^2)"
    example_substr = "th"

    # Question 4 inputs here
    first_string_2 = "asdfasfcds"
    second_string_2 = "sdfscssds"

    print("The longest common substring is:")
    print(lc_sub_str(first_string, second_string))
    print("The complexity of this algorithm is O(n^2)")

    print("\nThe max sum of increasing numbers is:")
    print(max_sum_incr_subseq(test_arr))
    print("The complexity of this algorithm is O(n^2)")

    print("\nThe number of times the pattern \"" + example_substr + "\" appears in the word \"" + example_string + "\" is:")
    print(subseq_in_str(example_string, example_substr))
    print("The complexity of this algorithm is O(n^2)")

    print("\nThe differences between the two strings \"" + first_string_2 + "\" and \"" + second_string_2 + "\" are:")
    print(diff_utility(first_string_2, second_string_2))
