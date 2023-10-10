# Goal: to calculate the nth fibonacci number using dynamic programming
def fibonacci(n):
    if (n == 1 or n == 2):
        return 1

    answer_array = [0] * (n + 1)
    answer_array[0] = 1
    answer_array[1] = 1

    for i in range(2, n + 1): # we have indexes 0 and 1 filled out so we start at 2
        answer_array[i] = answer_array[i - 1] + answer_array[i - 2]

    return answer_array[n]



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    number = 8
    print(fibonacci(number))

