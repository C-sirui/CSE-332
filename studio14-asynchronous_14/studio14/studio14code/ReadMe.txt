Ryan Chen
studio 14 asynchronous

Q2:
Hello World!
detector: 012FFDD4counter: 0
wrapper constructed
~wrapper
~detector: 012FFDD4counter: 0

two classes created and destroyed.


Q3
Hello World!
detector: 017D5D88counter: 0
wrapper constructed
~wrapper

Okey, now two classes are created but only one is destroyed. 
It is an memory leak since the wrapper class doesn't clean up the temporary detector object created after construction, 
	but only cleaned up the member vriable pointer.

Q4
Hello World!
detector: 01255D88counter: 0
wrapper constructed
~detector: 01255D88counter: 0
~wrapper

By adding the delete function in ~wrapper, not only the pointer member variable was cleaned up, but also the object it pointed to.

Q5
Hello World!
detector: 0101F0C0counter: 0
wrapper constructed
copied, another wrapper constructed
~wrapper
~detector: 0101F0C0counter: 0
~wrapper

1) one
2) two pointer points to one object
3) the wrapper object that has boolean boo = 1

Q6
Fail on this
How to copy a static member variable?

