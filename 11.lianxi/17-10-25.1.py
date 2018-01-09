#!/usr/bin/env python
# coding=utf-8


n = int(raw_input())
nums = [int(x) for x in raw_input().split()]
num = int(raw_input())
nums2 = nums
nums2.sort()
i = 0
j = n - 1
for x in range(n):
    if nums2[i] + nums[j] == num:
        break
    elif nums2[i] + nums[j] < num:
        i += 1
    else:
        j -= 1
index1 = nums2[i]
index2 = nums2[j]
for x in range(n):
    if nums[x] == index1:
        print x + 1,
    elif nums[x] == index2:
        print x + 1
