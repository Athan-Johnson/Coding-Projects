import random


# this will make a random knapsack for us
# it takes in the number of items we want made, as well as the smallest and largest possible weights
def make_knapsack_items(num_items, min_weight, max_weight, min_value, max_value):
    knapsack_items = [[0] * num_items for _ in range(2)]

    for _ in range(num_items):  # assign the weights
        knapsack_items[0][_] = random.randint(min_weight, max_weight)

    for _ in range(num_items):  # assign how much it's worth
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
    # Initialize the population
    population = [''.join(random.choice('01') for _ in range(len(knapsack_items[0]))) for _ in range(population_size)]

    # Define a function to perform mutation
    def mutate(individual):
        mutated_individual = ''
        for gene in individual:
            if random.random() < mutation_rate:
                mutated_individual += '0' if gene == '1' else '1'
            else:
                mutated_individual += gene
        return mutated_individual


    # run through many populations. In our case we assume finding the optimal solution is near impossible,
    # as those kinds of problems are what I will be testing, so we just run for the max number of iterations
    for generation_index in range(iterations_cap):
        # Evaluate the fitness of each individual
        population_fitness = [evaluate_fitness(knapsack_items, individual, knapsack_size) for individual in population]

        # make the next generation
        # we are going to do roulette selection, I won't bother with elites this time
        total_fitness = sum(population_fitness)
        next_generation = []

        # fill the roulette wheel
        roulette_wheel = [sum(population_fitness[:i + 1]) / total_fitness for i in range(len(population))]

        # assemble the next generation
        for next_gen_index in range(population_size):
            random_number = random.random()
            selected_individual = None

            for individual, cumulative_fitness in enumerate(roulette_wheel):
                cumulative_fitness += roulette_wheel[individual]
                if random_number <= cumulative_fitness:
                    selected_individual = population[individual]
                    break

            # mutation
            mutated_individual = mutate(selected_individual)
            next_generation.append(mutated_individual)

        population = next_generation

    best_fitness = 0
    for individual in population:
        fitness = evaluate_fitness(knapsack_items, individual, knapsack_size)
        if fitness > best_fitness:
            best_fitness = fitness
            best_individual = individual

    return best_individual


if __name__ == '__main__':
    # knapsack_items = make_knapsack_items(10, 0, 20, 2, 5)

    min_weight = 1
    max_weight = 20
    min_value = 10
    max_value = 100


    names = ['Laptop', 'Smartphone', 'Wallet', 'Tablet', 'Sunglasses', 'Water Bottle', 'Passport', 'Headphones', 'Camera', 'Charger', 'Umbrella', 'Notebook', 'Power Bank', 'Keys', 'Snacks', 'Towel', 'Sunscreen', 'Book', 'Toothbrush', 'Toothpaste', 'First Aid Kit', 'Maps', 'Multi-tool', 'Hat', 'Jacket', 'Sunglasses Case', 'Flashlight', 'Raincoat', 'Wallet', 'Identification', 'Hand Sanitizer', 'Tissues', 'Earplugs', 'Hairbrush', 'Comb', 'Sun Hat', 'Insect Repellent', 'Travel Pillow', 'Earbuds', 'Handheld Fan', 'Portable Speaker', 'Notepad', 'Pen', 'Cash', 'Band-Aids', 'Swiss Army Knife', 'Poncho', 'Travel Adapter', 'Face Mask', 'Travel Guides', 'Glasses']
    knapsack_items = [[5, 0.2, 0.1, 2, 0.05, 0.3, 0.1, 0.2, 1, 0.1, 0.3, 0.2, 0.3, 0.05, 0.2, 0.5, 0.1, 0.5, 0.05, 0.05, 0.5, 0.2, 0.3, 0.1, 0.7, 0.05, 0.1, 0.5, 0.1, 0.05, 0.1, 0.05, 0.01, 0.1, 0.05, 0.1, 0.05, 0.3, 0.02, 0.2, 0.3, 0.2, 0.01, 0.01, 0.05, 0.1, 0.3, 0.1, 0.02, 0.5, 0.2],
                      [1000, 500, 50, 300, 2000, 30, 100, 200, 300, 50, 30, 10, 50, 10, 20, 30, 20, 10, 5, 5, 50, 10, 20, 10, 100, 5, 10, 10, 30, 50, 10, 5, 5, 10, 5, 5, 10, 5, 10, 10, 30, 10, 30, 20, 10, 5, 5, 20, 10, 50, 1000]]
    optimal_items = genetic_algorithms(knapsack_items, 200, 1000, 0.15, 50)

    for _ in range(len(names)):
        if optimal_items[_] == '1':
            print(names[_] + '!')
