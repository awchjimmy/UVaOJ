import sys

def main():
	solve()

def solve():
	output = 'The Fibonacci number for {} is {}'
	for line in sys.stdin:
		n = int(line)
		print(output.format(n, fib(n)))

def fib(n):
	ans = 0
	if n <= 1:
		ans = n

	f0 = 0
	f1 = 1
	for i in range(2, n+1):
		ans = f0 + f1
		f0, f1 = f1, ans

	return ans
main()
