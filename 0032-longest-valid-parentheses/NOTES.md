at inital we push -1 in stack, now when we start if it is close bracket we pop the top and when it become empty we push that element if not emty we calculate its length
​
## **concept: the concept here is that we first push -1 to the stack so that whenever there is first element weather it is ( or ) it's index can be pushed so we had write the condition below:
##  if( s[i]==')' ) we pop the -1 and push this element index rather we were initially just passing over it
##   now when next time it comes the stack will not empty and when it is not empty we were calculating the maximum length of the contigious part which is : current index - stack top index**