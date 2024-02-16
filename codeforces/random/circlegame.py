test_cases = int(input())

while test_cases > 0:
    test_cases -= 1
    piles_size = int(input())
    piles = list(map(int, input().strip().split()))[:piles_size]
    if piles_size % 2 == 0:
        mike_min = piles[0]
        joe_min = piles[1]
        mike_pos = 0
        joe_pos = 1
        count = 2
        while count < piles_size:
            if piles[count] < mike_min:
                mike_min = piles[count]
                mike_pos = count
            if piles[count+1] < joe_min:
                joe_min = piles[count+1]
                joe_pos = count+1
            count += 2
        if mike_min > joe_min:
            print('Mike')
        elif mike_min < joe_min:
            print('Joe')
        else:
            print('Mike' if joe_pos < mike_pos else 'Joe')
    else:
        print('Mike')