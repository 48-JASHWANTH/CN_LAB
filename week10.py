from collections import defaultdict, deque
import sys

def bellman_ford(num_routers, edges, src):
    # Initialize distances and predecessors
    distance = [float('inf')] * num_routers
    predecessor = [-1] * num_routers
    distance[src] = 0

    # Relax edges repeatedly
    for _ in range(num_routers - 1):
        for u, v, d in edges:
            if distance[u] + d < distance[v]:
                distance[v] = distance[u] + d
                predecessor[v] = u

    # Check for negative-weight cycles
    for u, v, d in edges:
        if distance[u] + d < distance[v]:
            raise ValueError("Graph contains a negative-weight cycle")

    return distance, predecessor

def print_routing_table(num_routers, distances):
    for router in range(num_routers):
        print(f"Routing table for router {router}:")
        print("| Destination | Distance | Next Hop |")
        print("|-------------|----------|----------|")
        for dest in range(num_routers):
            next_hop = "-" if distances[router][dest][1] == -1 else distances[router][dest][1]
            dist = distances[router][dest][0]
            print(f"|     {dest}       |    {dist}   |    {next_hop}   |")
        print()

def find_path(predecessor, src, dest):
    path = []
    current = dest
    while current != -1:
        path.append(current)
        current = predecessor[current]
    if path[-1] != src:
        return None  # No path exists
    return path[::-1]

def main():
    # Input number of routers and edges
    num_routers = int(input("Number of routers: "))
    num_edges = int(input("Number of edges: "))
    edges = []

    print("Enter edges in the form (u, v, d):")
    for _ in range(num_edges):
        u, v, d = map(int, input().split())
        edges.append((u, v, d))
        edges.append((v, u, d))  # Assuming undirected graph

    # Calculate routing tables
    distances = {}
    for router in range(num_routers):
        distance, predecessor = bellman_ford(num_routers, edges, router)
        distances[router] = [(distance[i], predecessor[i]) for i in range(num_routers)]

    # Print routing tables
    print_routing_table(num_routers, distances)

    # Shortest path query
    src, dest = map(int, input("Enter source and destination: ").split())
    distance, predecessor = bellman_ford(num_routers, edges, src)
    path = find_path(predecessor, src, dest)
    if path:
        print(f"The distance between {src} and {dest} is {distance[dest]}")
        print(f"Path: {' --> '.join(map(str, path))}")
    else:
        print(f"No path exists between {src} and {dest}")

if __name__ == "__main__":
    main()
