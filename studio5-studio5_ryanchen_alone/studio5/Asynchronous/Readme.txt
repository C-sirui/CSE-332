Q1
Ryan Chen
Aync

Q2
    int a = 1;
    int b = 2;

Q3 & Q3.1
a: 1
b: 2
&a: 00AFFB3C
&b: 00AFFB30
mySwap Version1--Done Swapping
a: 2
b: 1
&a: 00AFFB3C
&b: 00AFFB30


Q4
I guess this time it will swap the address of a and b rather than swapping its value like last time.
Q4.1
a: 1
b: 2
&a: 001EF9FC
&b: 001EF9F0
mySwap Version2--Done Swapping
a: 2
b: 1
&a: 001EF9F0
&b: 001EF9FC
Prediction is correct.

Q5
This time only value can be changed since the pinter is constant.
Q5.1
Yes, the compiler unambiguously selected version2 when passing pointers to mySwap.
After commenting out Version2, the compiler automatically chose Version3(the reference to constant pointer one), which corresponds to my guesses.
Q5.2
This time compiler chose Version3 because the parameters are both int* const& for mySwap itself and mySwap in main function.\
Yes, it does follow my expectation.

done.
