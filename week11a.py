import heapq

def dijkstra(graph, start, n):
    # Initialize the distance table with infinity values, except for the start node
    distances = {i: float('inf') for i in range(n)}
    distances[start] = 0
    
    # Priority queue to explore nodes based on their shortest known distance
    pq = [(0, start)]  # (distance, node)
    
    while pq:
        # Get the node with the smallest distance
        current_distance, current_node = heapq.heappop(pq)
        
        # Skip if the current distance is outdated
        if current_distance > distances[current_node]:
            continue
        
        # Explore the neighbors of the current node
        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            
            # If a shorter path to the neighbor is found
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    
    return distances

# Get user input for the graph
def input_graph():
    n = int(input("Enter the number of nodes: "))
    m = int(input("Enter the number of edges: "))
    
    graph = {i: [] for i in range(n)}
    print("Enter the edges (format: source destination weight):")
    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))
        graph[v].append((u, w))  # Uncomment this line if the graph is undirected
    
    return graph, n

# Main program
if __name__ == "__main__":
    graph, n = input_graph()
    start_node = int(input("Enter the start node: "))
    distances = dijkstra(graph, start_node, n)
    print("Shortest distances from node", start_node, ":")
    for node, distance in distances.items():
        print(f"Node {node}: {distance}")
