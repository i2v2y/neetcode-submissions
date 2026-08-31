class Node:
    def __init__(self, key: int, val: int):
        self.key, self.val  = key, val
        self.prev = self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.cache = {}
        self.capacity = capacity

        self.head, self.tail = Node(-1, -1), Node(-1, -1)
        self.head.next, self.tail.prev = self.tail, self.head
    
    def insert(self, n: Node):
        self.tail.prev.next, n.prev =  n, self.tail.prev
        n.next, self.tail.prev = self.tail, n
    
    def remove(self, n:Node):
        n.prev.next, n.next.prev =  n.next, n.prev

    def get(self, key: int) -> int:
        if key in self.cache:
            n = self.cache[key]
            self.remove(n)
            self.insert(n)
            return n.val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache) > self.capacity:
            n = self.head.next
            self.remove(n)
            del self.cache[n.key]
