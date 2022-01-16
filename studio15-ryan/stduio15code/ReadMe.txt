Ryan Chen

Q2
    int a = 1;
    int b = 2;
    r value assigned to i value reference is correct

    int& a_ = a;
    int& b_ = b;
    i value assigned to i value reference is correct

    int&& r_a = a*2;
    int&& r_b = b+b;
    r value assigned to r value reference is correct 

    int&& r_b = b;
    i value assigned to r value reference is not correct

Q3
    int a = 1;
    int b = 2;
    
    int&& r_a = move(a);
    int&& r_b = move(b);

    cout << r_a << ", " << r_b << endl;

    int c = r_a;
    int d = r_b;

    cout << c << ", " << d << endl;

    move solves problem of assigning i values to r value refernce
    assigning r value reference to int variable is the same as assigning r to i, which is fine

Q4
    Whether or not detector objects are being allocated and de-allocated correctly by the
copy construction and copy-assignment operations, and why you think that.
    Yes, since all detector object created are fianlly destroyed.

Q5
    Explain why you think the code is behaving correctly and show the output from your program that demonstrates that is so.

    Detector: 0117ED78 has id 0
----------Move constructor start----------
Global count at start: 1
Original wrapper id at start: 0
----------Move constructor end----------
Global count at start: 1
Original Copy points to null, Copy wrapper id at end: 0

    Detector: 01175C88 has id 1
----------Copy constructor start----------
Global count at start: 2
Original wrapper id at start: 1
----------Copy constructor end----------
Global count at end: 2
Original wrapper id at end: 1
Copy wrapper id at end: 1

    ~Detector: 01175C88 has id 1
    ~Detector: 0117ED78 has id 0

        The global count for detector and id of each detector object are consistent, so it is behaving correctly.

Q6
    (1) explain why you think the code is behaving correctly
        The global count for detector and id of each detector object are consistent, so it is behaving correctly.
    (2) show the output from your program that demonstrates that is so.

    Detector: 00D5ADB0 has id 0
    Detector: 00D55A80 has id 1
----------Copy-assignment constructor start----------
Global count at start: 2
Original wrapper id at start: 1
----------Copy constructor start----------
Global count at start: 2
Original wrapper id at start: 1
----------Copy constructor end----------
Global count at end: 2
Original wrapper id at end: 1
Copy wrapper id at end: 1

    ~Detector: 00D5ADB0 has id 0
----------Copy-assignment constructor end----------
Global count at end: 2
Original wrapper id at end: 1
Copy wrapper id at end: 1

----------Move constructor start----------
Global count at start: 2
Original wrapper id at start: 1
----------Move constructor end----------
Global count at start: 2
Original Copy points to null, Copy wrapper id at end: 1

    ~Detector: 00D55A80 has id 1