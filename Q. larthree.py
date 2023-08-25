#Find largest three elements
a = [2,3,4,5,6]
print(a)
first, second, third = a[0], a[0], a[0]
for i in range(len(a)):
    if a[i] > first:
        third = second
        second = first
        first = a[i]
print(f"First : {first} Second : {second} Third : {third}")
