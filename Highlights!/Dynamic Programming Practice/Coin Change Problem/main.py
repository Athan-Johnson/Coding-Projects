
# Goal: Given a set of coin denominations and a target amount, find the minimum number of coins needed to make up
# that amount using dynamic programming!
def change_caluculator(coin_sizes, change_needed):
    if (change_needed <= 0):
        print("You must need at least 1 cent for this to work!")

    min_coins_needed = [0] * (change_needed + 1)
    min_coins_needed[0] = 0

    for cents in range(1, change_needed + 1):
        for coin in coin_sizes:  # we could do this in reverse order and have a break in here, but I wanted to be more readable
            if (cents - coin) == 0:  # the cents we need is the exact size of a coin
                min_coins_needed[cents] = min_coins_needed[cents - coin] + 1
            # the second condition makes sure that we don't fill spaces where no valid coin combo exists with one instead
            elif (cents - coin >= 0 and min_coins_needed[cents - coin] != 0):
                min_coins_needed[cents] = min_coins_needed[cents - coin] + 1

    if (min_coins_needed[change_needed] == 0):
        print("These coins can't make that amount of change!")

    return min_coins_needed[change_needed]

if __name__ == '__main__':
    coins = [5, 11]
    change = 12
    print(change_caluculator(coins, change))

# After checking with chatGPT I was informed that this isn't the optimal solution as I don't handle negative values
# and I could set everthing to max value instead of zero, which is true but given the complete lack of specifications
# here I think presenting the code I created instead of what was generated is totally valid. In a real world scenario on
# a harder problem I would work hand in hand with AI to create the best possible code for the specification given but
# this problem is a bit to short, I can really either be original or just us what the AI game me there's not much in
# between