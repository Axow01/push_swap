# PUSH_SWAP
## Things to do:
---
*Marsh 27 2023*
- [x] Correct someone to get points.
- [ ] Correct Born2BeRoot.
- [x] Work on push_swap.
---
*Marsh 28 2023*
- [x] Correct Born.
- [ ] Finish all the operation functions of push_swap.

## *March 31 2023*
- [x] Fix the circular linked list.
- [x] Install valgrind.
  
Usage of valgrind for push_swap:
```
valgrind --leak-check=full --log-file=valgrind.rpt ./push_swap $ARGS
```
### Notes:
- Still did not finished the operation function, that are mentionned in the subject file.
- [x] Create a makefile option to start directly with valgrind.
- Need to find a way to make the ra function, to shift all the elements of the stack a by 1. The first element becomes the last. And just copy the function after that to make rb.