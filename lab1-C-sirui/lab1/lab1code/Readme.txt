LAB1
Group member:
Ryan Chen

!!!: check header file for specific function definition

Q12:
Error message: ---------------------------- cannot open file, since i forgot to put the txt file in the debug folder
	This program takes in only one txt file
	text.t cannot be open
Error message:----------------------------- forgot to give any input
	This program takes in only one txt file
	C:\Users\poi\Source\Repos\cse332s-fl21-wustl\lab1-C-sirui\lab1\lab1code\Debug\lab1code.exe + name of input txt file

Q13:
Test case: 
1) Txt file:
asd dsa

123	321 


as12df

qwer
2) Command Line:
lab1code.txt text.txt
3) Output:
They are strings from input file:
asd
dsa
as12df
qwer
They are integers from input file:
123
321

Extra Credit:
The Makefile doesn't compile c++11, so I added -std=c++11 after g++ in CXX, then it worked.
Compile message:
g++ -std=c++11 -o lab1-exe -DUNIX   -Wall -W -g -pedantic lab1code.cpp -lnsl
Commend line: 
./lab1-exe text.txt
Output:
They are strings from input file:
asd
dsa
as12df
qwer
They are integers from input file:
123
321


