import csv


class node:
	def __init__(self, key):
		self.par = None
		self.left = None
		self.right = None
		self.key = key


class min_heap:
	def __init__(self, A, s):
		self.root = None
		self.array = A
		self.size = s
	
	# this is a function to find the index of the left node, assuming that this was built on top of an array
	def left(self, index):
		index = index + 1
		index = index*2
		index = index - 1
		return index
	
	# the same function as above but for the right node
	def right(self, index):
		index = index + 1
		index = index*2
		return index
	
	def parent(self, index):
		return int(index / 2)
	
	def min_heapify(self, start):
		l = self.left(start)
		r = self.right(start)
		smallest = start

		if l < self.size:
			if self.array[l] < self.array[start]:
				smallest = l

		if r < self.size:
			if self.array[r] < self.array[smallest]:
				smallest = r
		if smallest != start:
			temp = self.array[start]
			self.array[start] = self.array[smallest]
			self.array[smallest] = temp
			self.min_heapify(smallest)
	
	def build_min_heap(self, s):
		self.size = s
		if self.size < 1:
			print("Error: nothing in min heap")
			return
		for i in range(int((len(self.array)/2)), 1, -1):
			self.min_heapify(i)
	
	def heap_extract_min(self):
		if self.size < 1:
			print("Heap underflow")
			return
		min = self.array[0]
		self.array[0] = self.array[self.size - 1]
		self.size = self.size - 1
		self.array[self.size] = self.array[0]
		self.min_heapify(0)
		return min
	
	def heap_decrease_key(self, index, key):
		p = self.parent(index)
		if key > self.array[index]:
			print("new key is bigger than current key")
			return
		self.array[index] = key
		while (index >= 0) & (self.array[p] > self.array[index]):
			temp = self.array[index]
			self.array[index] = self.array[p]
			self.array[p] = temp
			index = p
			p = int(self.parent(index))

	def min_heap_insert(self, key):
		self.size = self.size + 1
		self.array.append(key)
		self.heap_decrease_key(self.size - 1, key)

	def is_empty(self):
		if self.size < 1:
			return True


class pqueue:
	def __init__(self):
		array = []
		self.min_heap = min_heap(array, 0)
		self.size = 0

	def pop(self):
		return self.min_heap.heap_extract_min()

	def insert(self, key):
		self.size = self.size + 1
		self.min_heap.min_heap_insert(key)

	def decrease_key(self, oldkey, newkey):
		i = 0
		while oldkey != self.min_heap.array[i]:
			i = i + 1
		self.min_heap.heap_decrease_key(i, newkey)
	

class adjnode:
	def __init__(self, c, d, pi, k):
		self.color = c
		self.dist = d
		self.Pi = pi
		self.key = k
		self.next = None


class adjacency_list:
	def __init__(self, array):
		self.array = []
		for i in range(len(array)):
			self.array.append(adjnode(None, None, None, array[i]))
	
	# you should pass it the keys here, not the index
	def insert(self, f_val, s_val):
		first = adjnode("white", 1000000, None, f_val)
		second = adjnode("white", 1000000, None, s_val)
		i = 0
		while (self.array[i].key != first.key) & (i < len(self.array)):
			i = i + 1
		if i >= len(self.array):
			print("Error: the node you are trying to insert doesn't start from a valid location (insert)")
			return

		j = 0
		while (self.array[j].key != second.key) & (j < len(self.array)):
			j = j + 1
		if j >= len(self.array):
			print("Error: the node you are trying to insert doesn't start from a valid location (insert)")
			return

		first.next = self.array[j].next
		self.array[j].next = first

		second.next = self.array[i].next
		self.array[i].next = second

	# here again you are passing it the key, not the index
	def get_edges(self, start):
		i = 0
		while (self.array[i].key != start) & (i < len(self.array)):
			i = i + 1
		if i >= len(self.array):
			print("Error: the node you are trying to insert doesn't start from a valid location (get_edge)")
			return
		return self.array[i]

	def print(self):
		for i in range(len(self.array)):
			curr_node = self.array[i]
			output = ""
			output += curr_node.key
			output += ": "
			curr_node = curr_node.next
			while curr_node is not None:
				output += curr_node.key
				output += ", "
				curr_node = curr_node.next
			print(output)


def print_path(array, start, end):
	j = 0
	while array[j].key != end:
		j = j + 1
	if start == end:
		print(start)
	elif array[j].Pi == None:
		print("no path from " + start + " to " + end + " exists")
	else:
		print_path(array, start, array[j].Pi.key)
		print(end + ", ")


# here you pass this search the list you are searching through, the key you are starting from, and the key
# you are ending with
def breadth_first_search(adjList, start, end):
	i = 0
	while (adjList.array[i].key != start) & (i < len(adjList.array)):
		i = i + 1
	if i >= len(adjList.array):
		print("Error: the node you are trying to insert doesn't start from a valid location (breadth first search)")
		return

	# 1. initialize all verticies
	for index in range(len(adjList.array)):
		adjList.array[index].color = "white"
		adjList.array[index].dist = 1000000
		adjList.array[index].Pi = None

	
	# 2. Q = empty
	queue = []

	# 3. Set source node color = grey, d = 0, pi = none
	adjList.array[i].color = "grey"
	adjList.array[i].dist = 0
	adjList.array[i].Pi = None
	queue.append(adjList.array[i])

	# 4. While Q isn’t empty:
	#	1. Dequeue from Q, set to be called u
	#	2. Get all nodes adjacent to u
	#	3. If node is white, color it grey, d = u.d + 1, pi = u, then enqueue it
	#	4. Color u black, then move on
	while queue:
		u = queue.pop(0)
		if u.color != "black":
			curr_node = adjList.get_edges(u.key)
			while curr_node is not None:
				k = 0
				while (curr_node.key != adjList.array[k].key) & (k < len(adjList.array)):
					k = k + 1
				if adjList.array[k].color == "white":
					adjList.array[k].color = "grey"
					adjList.array[k].dist = u.dist + 1
					adjList.array[k].Pi = u
					queue.append(adjList.array[k])
					k = k + 1
				curr_node = curr_node.next
			u.color = "black"

	# 5. Find the distance value the end node has gotten
	j = 0
	while (adjList.array[j].key != end) & (j < len(adjList.array)):
		j = j + 1
	if j >= len(adjList.array):
		print("Error: the node you are trying to insert doesn't start from a valid location (insert)")
		return
	return adjList.array[j].dist


def initialize_single_source(graph, source):
	for vertex in graph:
		graph[vertex].dist = 1000000
		graph[vertex].Pi = None
	source.dist = 0


def relax(pqu, vertex1, vertex2, weight):
	if vertex2.dist > vertex1.dist + weight:
		temp = vertex2
		temp.dist = vertex1.dist + weight
		pqu.decrease_key(vertex2, temp)
		vertex2.Pi = vertex1


class dnode:
	def __init__(self, c):
		self.city = c
		self.dist = 1000000
		self.Pi = None

	def __lt__(self, other):
		if self.dist < other.dist:
			return True
		else:
			return False

	def __gt__(self, other):
		if self.dist > other.dist:
			return True
		else:
			return False


def dijkstra(graph, start, end):

	def print_path_dj(data, s, e):
		if s == e:
			print(s)
		elif data[e].Pi is None:
			print("No path from " + s + " to " + e + " exists")
		else:
			print_path_dj(data, s, data[e].Pi.city)
			print(e + ", ")

	cities = {}
	for city in graph:
		cities[city] = dnode(city)

	initialize_single_source(cities, cities[start])
	solved = []
	pq = pqueue()
	for city in cities:
		pq.insert(cities[city])
	while pq.min_heap.is_empty() is not True:
		u = pq.pop()
		if u not in solved:
			solved.append(u.city)
			for city2 in graph[u.city]:
				relax(pq, u, cities[city2], graph[u.city][city2])

	print_path_dj(cities, start, end)


def main():
	# EDIT THE PATH HERE: (Edges)
	with open('/Users/athanjohnson/Documents/CS 315/Data3/RomaniaEdges.txt', newline='') as file:
		edges = file.readlines()
		edges = [s.rstrip() for s in edges]

	# EDIT THE PATH HERE: (Vertices)
	with open('/Users/athanjohnson/Documents/CS 315/Data3/RomaniaVertices.txt', newline='') as file:
		reader = csv.reader(file)
		vertices = [vertices[0] for vertices in reader]

	cities = adjacency_list(vertices)
	for i in range(len(edges)):
		edges[i] = edges[i].rstrip("\n")
		edges[i] = edges[i].split(",")

	for i in range(len(edges)):
		cities.insert(edges[i][0], edges[i][1])

	print("Breadth first sreach's paths:")
	breadth_first_search(cities, "Arad", "Bucharest")
	print("\nPath from Arad to Sibiu:")
	print_path(cities.array, "Arad", "Sibiu")
	print("\nPath from Arad to Craiova:")
	print_path(cities.array, "Arad", "Craiova")
	print("\nPath from Arad to Bucharest:")
	print_path(cities.array, "Arad", "Bucharest")
	print("")

	data = {}
	for city in vertices:
		data[city] = {}
	for index in range(len(edges)):
		data[edges[index][0]][edges[index][1]] = int(edges[index][2])
		data[edges[index][1]][edges[index][0]] = int(edges[index][2])

	print("Dijkstra's path from Arad to Bucharest:")
	dijkstra(data, "Arad", "Bucharest")


if __name__ == "__main__":
	main()
