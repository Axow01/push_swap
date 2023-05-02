# PUSH_SWAP
## The learning process

So I just started push_swap, and I have no idea how to make the sorting algorithm. Im gonna read the wikipedia page of the sorting algorithm.

## Push_swap Sorting Algorithm

1. Parse the input list and push all the integers onto stack A.
2. While stack A has more than 1:

	1. Fin the smallest value in stack A, and move it to tthe top of the stack using the ra (rotate A) or rra (revers rotate A) instructions.
	2. Push the smallest value from stack A to tack B using the pb (pushB) instruction.
3. Once all the values are on stack B, execute the following steps to move them back to stack A in ascending order:

	1. While stack B is not empty, find the highest value in stack B, and move it tot the top of the stack using the rb (rotate B) or rra(reverse rotate B) instructions.
	2. Push the highest value form stack B to stack A using the pa (push A) instruction.
4. Stack A is now sorted in ascending order.

Here's how this algorithm would sort the list (34, 56, 53, 2, 68):

```
Stack A: 34 56 53 2 68
Stack B: 
```
- Find the smallest value, that is 2. Put it in first position using ra or rra.
```
Stack A: 2 68 34 56 53
Stack B: 
```
- Then pb(push B).
```
Stack A: 68 34 56 53
Stack B: 2
```
- Then repeat, until you have only one element in Stack A.
```
Stack A: 68
Stack B: 2 34 53 56
```
- Then while stack b is not empty, rra(reverse rotate b) pa (push a).
```
Stack A: 2 34 53 56 68
Stack B: 
```
