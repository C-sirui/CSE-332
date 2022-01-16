Q1
Asynchrounous
Ryan Chen

Q2.1 What happens when you call this function and provide an indexthat is bigger than the size of the vector?
Compile failed and gave error message: Expression: vector subscript out of range.

Q2.2 Test your prediction and provide theresulting output as the answer to this exercise. 
Try: squareElement(a, 4)
error throwed ---- out_of_range
error caught, return -1 ---- uindex larger than vector size

Q2.3 What happens if you fail to catch thethrown exception?
Compile failed.

Q3.1 Note that the std::out_of_range exception type inherits from std::logic_error.Given this, in what order should you write your catch statements in main()?
logic error should be after out_of_range in order to make sure logic_error won't accidentially caught out of range error

Q3.2 Why it is not necessary to throw out of bound exceptions in thisfunction, like it was in squareElement().
Since it is already taken care by the throw statements in squareElement.

Q4.1 what do you expect the output of the program to be?
Whe result of calling squareElement() with the given vectorand the first integer, divided by the result of another call to squareElement() with thegiven vector and the second integer.
2

Q4.2 Now replace the call to squareElement() in main() with a call to divideSquareElements()with valid indices at first. Run the program, and check the output against your initialpredictions.
Error will be caught and output will be an integer.
error throwed ---- logic error
error caught, return -2 ---- dividing by zero

Q4.3 Next, change the call to divideSquareElements() so that the second integer argumentcorresponds to an element of the vector with the value 0. Again, run the program andcheck your predictions.
Exceptions will be thrown and caught.
error throwed ---- out_of_range
error caught, return -1 ---- uindex larger than vector size

Eceptions change the control flow by exiting the current stack frame and searching catch statement. If found, run what's in it and terminate. If not found, went back to the throw statement and continue.

