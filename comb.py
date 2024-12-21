comb = ['012']

current_index = 0
no_combs = []
while True:
    increment = 1
    while True:   
        for i in range(0, 3):
            for j in range(0, 3):
                for k in range(0, 3):
                    a = comb[current_index][i]
                    b = comb[current_index][j]
                    c = comb[current_index][k]
                    no_combs.append(a+b+c)


        prox = int(comb[current_index]) + increment
        prox_with_zero = "0"+str(prox)

        if(increment == 2):
            print("increment", prox, prox_with_zero)

        if(prox <= 99):
            have = False
            for no_comb in no_combs:
                if(no_comb == prox_with_zero):
                    have = True
    
            if not have:
                comb.append(prox_with_zero)
                current_index+=1
                break
            else:
                increment+=1
        else:
            have = False
            for no_comb in no_combs:
                if no_comb == str(prox):
                    have = True
                

            if not have:
                comb.append(str(prox))
                current_index+=1
                break
            else:
                increment+=1


    if(int(comb[current_index]) >= 999):
        break

comb.remove('1000')
print(comb)