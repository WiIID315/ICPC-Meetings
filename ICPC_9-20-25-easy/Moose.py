left, right = map(int, input().split())
value = max(left, right) * 2
if(left == 0 and right == 0):
	print("Not a moose")
elif(left == right):
	print(f"Even {value}")
else:
	print(f"Odd {value}")