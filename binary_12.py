import random

class Node:
    def __init__(self, val, name, salary):
        self.val = val
        self.name = name
        self.salary  = salary
        self.left = None
        self.right = None

class BT:
    def __init__(self):
        self.root = None
    
    def insert(self, val, name, salary):
        if not self.root:
            self.root = Node(val, name, salary)
            return
        q = []
        q.append(self.root)
        while len(q):
            a = random.randint(0,1)
            if(a):
                temp = q[0]
                q.pop(0)
                if not temp.left:
                    temp.left = Node(val, name, salary)
                    break
                q.append(temp.left)
            else:
                temp = q[0]
                q.pop(0)
                if not temp.right:
                    temp.right = Node(val, name, salary)
                    break
                q.append(temp.right)


list_of_names = ["Agarwal", "Shrivastava", "Kandoi", "Yadav", "Sethia", "Nagori", "Nguyen", "Hill", "Labib", "Ahlawat", "Khurana", "Kashedikar", "Raj", "Ahi","Agrawal","Arora"]

def randBT(count:int = 1):
    bt = BT()
    for _ in range(1,count+1):
        rval = _
        salary = (random.randint(100,1000))
        name = random.choice(list_of_names)
        bt.insert(rval, name ,salary)
    return bt.root


def inorder(temp, l):
    if (not temp):
        print(-1,end = " ")
        l.append(-1)
        return
    print(temp.val,temp.name,temp.salary, end = " ")
    l.append(temp.val)
    inorder(temp.left, l)
    inorder(temp.right, l)
    return


a = random.randint(32,128)

headRand = randBT(a)
x = []
inorder(headRand,x)
y = x.copy()
try:
    while True:
        y.remove(-1)
except Exception as excess:
    print()
    
list_of_commands = ["get_first_common_boss", "same_last_names", "get_average_salary", "get_all_bosses"]

n = (1000) # Number of commands
print(n)
for i in range(n):
    k = random.randint(0,3)
    j = list_of_commands[k]
    if k == 0:
        num_1 = random.choice(y)
        num_2 = random.choice(y)
        print(j,num_1,num_2)
    else:
        random_num = random.choice(y)
        print(j,random_num)
