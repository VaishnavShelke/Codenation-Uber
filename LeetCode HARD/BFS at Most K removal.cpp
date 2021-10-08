class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        visited = {}
        m = len(grid)
        n = len(grid[0])
        
        q = deque()
            
        if grid[0][0] == 1:
            if k < 1:
                return -1
            q.append((0, 0, 1))
            visited[(0,0)] = 1 
            
        else:
            q.append((0, 0, 0))
            visited[(0,0)] = 0  
        
        if m == 1 and n == 1:
            return 0
            
        step = 0
        while(q):
            # print(step)
            size = len(q)
            for i in range(size):
                x, y, e = q.popleft()
                # if (x, y) in visited and visited[(x, y)] < e:
                #     continue
                # else:
                 
                for (dx, dy) in [(1,0), (0,1), (-1, 0), (0, -1)]:
                    newx = x + dx
                    newy = y + dy
                    if newx > m-1 or newx <0 or newy > n-1 or newy <0:
                        continue
                    if grid[newx][newy] == 0:
                        newE = e
                    else:
                        newE = e + 1
                    if newE > k:
                        continue
                    if (newx, newy) == (m-1, n-1):
                        return step + 1
                    if (newx, newy) not in visited or visited[(newx, newy)] > newE: 
                        visited[(newx, newy)] = newE   
                        q.append((newx, newy, newE))

            step += 1
            
        return -1class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        visited = {}
        m = len(grid)
        n = len(grid[0])
        
        q = deque()
            
        if grid[0][0] == 1:
            if k < 1:
                return -1
            q.append((0, 0, 1))
            visited[(0,0)] = 1 
            
        else:
            q.append((0, 0, 0))
            visited[(0,0)] = 0  
        
        if m == 1 and n == 1:
            return 0
            
        step = 0
        while(q):
            # print(step)
            size = len(q)
            for i in range(size):
                x, y, e = q.popleft()
                # if (x, y) in visited and visited[(x, y)] < e:
                #     continue
                # else:
                 
                for (dx, dy) in [(1,0), (0,1), (-1, 0), (0, -1)]:
                    newx = x + dx
                    newy = y + dy
                    if newx > m-1 or newx <0 or newy > n-1 or newy <0:
                        continue
                    if grid[newx][newy] == 0:
                        newE = e
                    else:
                        newE = e + 1
                    if newE > k:
                        continue
                    if (newx, newy) == (m-1, n-1):
                        return step + 1
                    if (newx, newy) not in visited or visited[(newx, newy)] > newE: 
                        visited[(newx, newy)] = newE   
                        q.append((newx, newy, newE))

            step += 1
            
        return -1
