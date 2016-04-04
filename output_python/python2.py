n,c=map(int,raw_input().split())
i=0
while i<n:
	p[i]=map(int,raw_input().split())
	i+=1
i=0
while i<n:
	t[i]=map(int,raw_input().split())
	i+=1
cur=0; a=0;
i=0
while i<n:
	cur+=t[i];
	a+=max(0,p[i]-cur*c);
	i+=1
cur=0; b=0;
i=n-1
while i>=0:
	cur+=t[i];
	b+=max(0,(p[i]-cur*c));
	i-=1
if a>b:
	print("Limak\n")
elif b>a:
	print("Radewoosh\n")
else:
	print("Tie\n")
