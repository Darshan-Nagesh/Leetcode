#program to pint subarrays
def sub(a,start,end,size):
    if end == size:
        return
    elif start > end:
        return sub(a,0,end+1,size)
    else:
        print(a[start:end+1])
        return sub(a,start+1,end,size)

a = [2,3,4,5,6]
print(a)
sub(a,0,0,len(a))

    
