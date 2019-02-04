#!/usr/bin/env python

print('\n'.join([str(s) for s in sorted([int(input()) for i in range(0, int(input()))])[::-1]]))
