#!/usr/bin/python3

import sys

def main():
	solve()

def solve():
	figs = []
	pts = []

	# input
	for line in sys.stdin:
		if line[0] in 'rc*':
			figs.append(line)
		else:
			pts.append(line)

	# discard lines
	figs = figs[:-1] # *
	pts = pts[:-1] # 9999.9 9999.9

	# output
	for i, pt in enumerate(pts):
		contained = False
		for j, fig in enumerate(figs):
			if(isIn(pt, fig)):
				contained = True
				print('Point {} is contained in figure {}'.format(i+1, j+1))

		if not contained:
			print('Point {} is not contained in any figure'.format(i+1))
		
			
def isIn(pt, fig):
	# point
	px, py = pt.split(' ')
	px, py = float(px), float(py)

	# rectagle
	if 'r' in fig:
		r, rx1, ry1, rx2, ry2 = fig.split(' ')
		rx1, ry1, rx2, ry2 =  float(rx1), float(ry1), float(rx2), float(ry2)
		if rx1 < px < rx2 and ry2 < py < ry1:
			return True

	# circle
	if 'c' in fig:
		c, cx, cy, cr = fig.split(' ')
		cx, cy, cr = float(cx), float(cy), float(cr)
		if ((px-cx)**2 + (py-cy)**2) < cr**2:
			return True
		
	return False

main()
