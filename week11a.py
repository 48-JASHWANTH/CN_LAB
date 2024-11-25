import heapq

def dij(mat, st, n):
    q = [(0, st)]
    dis = {st: 0}
    pn = {st: None}
    
    while q:
        curdis, curn = heapq.heappop(q)
        if curdis > dis.get(curn, float('inf')):
            continue
        for neigh in range(n):
            if mat[curn][neigh] != 0:  
                w = mat[curn][neigh]
                d = curdis + w
                if d < dis.get(neigh, float('inf')):
                    dis[neigh] = d
                    pn[neigh] = curn
                    heapq.heappush(q, (d, neigh))
    
    return dis, pn

def gsp(pn, target):
    path = []
    while target is not None:
        path.append(target)
        target = pn[target]
    return path[::-1]

def matin():
    n = int(input("Enter the number of nodes: "))
    print("Enter the adjacency mat (use 0 for no edge and positive integers for edge weights):")
    mat = []
    for i in range(n):
        row = list(map(int, input(f"Enter row {i + 1}: ").split()))
        mat.append(row)
    return mat, n

def main():
    mat, n = matin()
    sn = int(input("Enter the st node (0-indexed): "))
    tn = int(input("Enter the target node (0-indexed): "))
    
    dis, pn = dij(mat, sn, n)
    sp = gsp(pn, tn)
    
    print(f"Shortest path from node {sn} to node {tn}: {sp}")
    print(f"Distances from node {sn}: {dis}")

# Run the main function
if __name__ == "__main__":
    main()
