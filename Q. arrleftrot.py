#program to move an array left 
a = [2,3,4,5,6]
n = int(input("Enter no. of rotataion : "))
while(n!=0):
    temp = a[0];
    for i in range(len(a)-1):
        a[i] = a[i+1]
    a[len(a)-1] = temp
    n -= 1
print(a)
