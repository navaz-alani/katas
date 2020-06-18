upper_bound = 100
for i in range(upper_bound + 1):
    div3 = i % 3
    div5 = i % 5
    if div3 == 0 and div5 == 0:
        print(f"{i} fizzbuzz")
    elif div3 == 0:
        print(f"{i} fizz")
    elif div5 == 0:
        print(f"{i} buzz")
    else:
        print(i)

