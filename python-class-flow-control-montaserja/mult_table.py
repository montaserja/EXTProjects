def mult_table(size=10, jumps=1):
    for i in range(1,size+1,jumps):
        for j in range(1,size+1,jumps):
            print(f'{i:>2} * {j:<2} = {i * j}')


# mult_table(4,2)
