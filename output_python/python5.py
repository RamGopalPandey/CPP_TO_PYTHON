i=0
while i<n:
	j=0
	while j<n:
		x,y=map(int,raw_input().split())
		j+=1
	i+=1
i=0
while i<n:
	j=0
	while j<n:
		if i+j%2==0:
			print(i+j,"is even\n")
		else:
			print(i+j,"is odd\n")
		j+=1
	i+=1
