import sys

def main():
	solve()

def solve():
	ans = 0
	for line in sys.stdin:
		n = int(line)
		ans += n
	print(ans)

main()
