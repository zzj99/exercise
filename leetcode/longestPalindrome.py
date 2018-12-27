#-*- coding: utf-8 -*-
from time import time

def longestA(s):
    """find the longest Palindromic substring of s
    expand s by inserting "#" so that only need treat the new string, O((2N)^2)
    
    >>> longestA("aaab") = "aaa"
    """
    # expand s
    t = "#" + "#".join(s) + "#"
    # find the longest palindrome of t
    n = len(t)
    maxlen = 1
    istart = 0
    for i in range(n):
        left = i
        right = i
        while(left >= 0 and right < n and t[left] == t[right]):
            left -= 1
            right += 1
        if (right - left - 1 > maxlen):
            maxlen = right - left - 1
            istart = left + 1
    # the index and length for original s
    omaxlen = (maxlen-1)/2
    oistart = istart/2
    return s[oistart:oistart+omaxlen]

def longestB(s):
    """find the longest Palindromic substring of s
    treat odd and even situations O(N^2)
    
    >>> longestB("aaab") = "aaa"
    """
    n = len(s)
    maxlen = 1
    istart = 0
    for i in range(n):
        left = i
        right = i
        while(left >= 0 and right < n and s[left] == s[right]):
            left -= 1
            right += 1
        if (right - left - 1 > maxlen):
            maxlen = right - left - 1
            istart = left + 1

        left = i
        right = i+1
        while(left >= 0 and right < n and s[left] == s[right]):
            left -= 1
            right += 1
        if (right - left - 1 > maxlen):
            maxlen = right - left - 1
            istart = left + 1
    return s[istart: istart+ maxlen]

def Manacher(s):
    """find the longest Palindromic substring of s
    Manacher algorithm O(N)
    
    >>> Manacher("aaab") = "aaa"
    """
    # expand s
    t = "#" + "#".join(s) + "#"
    length = [0]*len(t)
    center = 0
    maxRight = 0
    for i in range(len(t)):
        if (maxRight > i):
            length[i] = min(2*center-i, maxRight-i)
        else:
            length[i] = 1
        while(i-length[i]>=0 and i+length[i]<len(t)
                and t[i-length[i]] == t[i+length[i]]):
            length[i] += 1
        if (length[i] > maxRight -i + 1):
            maxRight = length[i] + i - 1
            center = i
    # start index and the maxlen of the original string
    istart = 0
    maxlen = 0
    for i in range(len(t)):
        if length[i] > maxlen:
            maxlen = length[i]-1     
            istart = (i - maxlen + 1)/2
    return s[ istart: istart+ maxlen]

### test

slist=[]
rlist=[]

s=['x']*1000
s[100:900] = 'y'
slist.append(s)
rlist.append(s)

s=['x']*1000
slist.append(s)
rlist.append(s)

s=['x']*1000
s[0] = 'y'
slist.append(s)
rlist.append(s[1:])

for i in range(len(slist)):
    t1 = time()
    assert(longestA(slist[i]) == rlist[i])
    t2 = time()
    print("longestA:%s" % (t2-t1))

    t1 = time()
    assert(longestB(slist[i]) == rlist[i])
    t2 = time()
    print("longestB:%s" % (t2-t1))

    t1 = time()
    assert(Manacher(slist[i]) == rlist[i])
    t2 = time()
    print("Manacher:%s" % (t2-t1))
