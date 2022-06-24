import os
import sys
import time


a = time.time()
for i in range(1,1001):
        os.system(f"./a.exe < input_{i}.txt > testout_{i}.txt")
        with open(os.path.join(sys.path[0], f"output_{i}.txt" ), "r") as f :
                lines = f.readlines()

        with open(os.path.join(sys.path[0], f"testout_{i}.txt" ), "r")as f :
                lines_check = f.readlines()

        with open(os.path.join(sys.path[0], f"input_{i}.txt" ), "r")as f :
                        lines_in = f.readlines()

        if(len(lines) == len(lines_check)):
                counter = len(lines)
        else:
                # print(f"Lines donot match for {i}")
                if(len(lines) > len(lines_check)):
                        counter = len(lines_check)
                else:
                        counter = len(lines)

        condition = 1
        lines_with_error = []
        for c in range(counter):
                if(lines[c].split() == lines_check[c].split()):
                        continue
                else:
                        g = 0
                        d = lines_in[c+1].split()
                        if(d[0] == 'same_last_names'):
                                e = lines[c].split()
                                f = lines_check[c].split()
                                g = 1
                                h = 0
                                for item_e in e:
                                        for item_f in f:
                                                if(item_e == item_f):
                                                        h = 1
                                                        break
                                        if(h == 0):
                                                g = 0
                                                break                                        
                        
                        if(d[0] == 'get_average_salary'):
                                e = lines[c].split()
                                f = lines_check[c].split()
                                e_f = float(e[0])
                                f_f = float(f[0])
                                if((int((e_f - f_f)*100) == 1) or((int((e_f-f_f)*100)) == -1)or((int((e_f-f_f)*100)) == 0)):
                                        continue
                        if(g == 1):
                                continue
                                

                        lines_with_error.append(c)
                        condition = 0

        if(condition != 1):
                print("Testcase failed", i)
                print(lines_with_error)
                for item in lines_with_error:
                        print(lines_in[item+1], end = "")
                        print(lines[item], end = "")
                        print(lines_check[item], end = "")

b = time.time()
print(b-a)
