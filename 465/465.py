#!/usr/bin/python3

import sys

def main():
	solve()

def solve():
	for line in sys.stdin:
		if '+' in line:
			first, second = line.split(' + ')
			res = int(first) + int(second)
		else:
			first, second = line.split(' * ')
			res = int(first) * int(second)

		# output
		print(line[:-1])
		int_max = 2147483647
		if int(first) > int_max: print("first number too big")
		if int(second) > int_max: print("second number too big")
		if int(res) > int_max: print("result too big")

main()
