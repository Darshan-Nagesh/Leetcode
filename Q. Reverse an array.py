#program to reverse an array

a = [2,3,4,5,6]
print(a)
left = 0
right = len(a)-1
while(left<right):
    a[left],a[right] = a[right],a[left]
    left += 1
    right -= 1
print(a)
