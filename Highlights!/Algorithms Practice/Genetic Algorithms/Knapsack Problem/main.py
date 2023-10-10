import random

# this will make a random knapsack for us
# it takes in the number of items we want made, as well as the smallest and largest possible weights
def make_knapsack_items(num_items, min_weight, max_weight, min_value, max_value):
    knapsack_items = [[0] * num_items for _ in range(2)]

    for _ in range(num_items): # assign the weights
        knapsack_items[0][_] = random.randint(min_weight, max_weight)

    for _ in range(num_items): # assign how much it's worth
        knapsack_items[1][_] = random.randint(min_value, max_value)

    return knapsack_items

def evaluate_fitness(knapsack_items, individual, knapsack_size):

    # find out if the sum of the weights the individual has are too big for the knapsack
    weight_sum = 0
    value_sum = 0
    for item_index in range(len(individual)):
        if individual[item_index] == '1':
            weight_sum += knapsack_items[0][item_index]
            value_sum += knapsack_items[1][item_index]

    if weight_sum > knapsack_size:
        return 0
    else:
        return value_sum

# here is where we try and make our genetic algorithms
# knapsack_items is a 2D array. The first row is the weight and the second row is the value
# the generation size is how big we want each generation to be
# the iterations cap is how many iterations we are willing to run
# the mutation rate is how often mutations occur
# knapsack size is how much weight our knapsack can hold
def genetic_algorithms(knapsack_items, population_size, iterations_cap, mutation_rate, knapsack_size):

    # first we make the array of strings in the population
    population = []
    for _ in range(population_size):
        # Generate a random binary string of the specified length
        individual = ''.join(random.choice('01') for _ in range(len(knapsack_items[0])))
        population.append(individual)

    # run through many populations. In our case we assume finding the optimal solution is near impossible,
    # as those kinds of problems are what I will be testing, so we just run for the max number of iterations
    for generation_index in range(iterations_cap):
        population_fitness = []

        # evaluate the fitness of each member of the population
        for individual_index in range(len(population)):
            population_fitness[individual_index] = evaluate_fitness(knapsack_items, population[individual_index], knapsack_size)

        # make the next generation
        

if __name__ == '__main__':
    knapsack_items = make_knapsack_items(10, 0, 20, 2, 5)
    genetic_algorithms(knapsack_items, 100, 1000, 0.05, 50)
