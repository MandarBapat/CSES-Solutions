## Sorting and Searching algorithms

Solutions to some of the sorting and searching problems that I have solved so far.

Some key algorithms:

**1.) Sliding window technique**:

  Note that the Sliding median question is a little unique and you would have to optimize it a little bit. Directly applying sliding window technique was giving TLE.
  
**2.) Kadane's Algorithm**

**3.) Minimizing the sum |x - a_1| + |x - a_2| ... |x - a_n|**

  Minimized when x is the median of a_1, a_2 ... a_n.

**4.) Sum of value questions**

  If you are asked to find the number of tuples of length **k**, i.e, **(a_1, a_2, a_3, ... a_k)** whose sum equals a particular target **t**, just create **(k - 1)** nested loop and use binary search to find if the number **a_k = x - a_1 - a_2 ... a_(k-1)** exists or not and simultaneously keep a count of such tuples.
  

**5.) Prefix sum calculations**

  In some questions, calculating the prefix sums/minimums/maximums or any other quantity related to the question, is very useful.
