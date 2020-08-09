##Simple ATM Controller

There are four main entities here:
    Bank
    Account
    Card
    ATM

Bank has Account information.
Account has Card information.
Card is associated with a number and PIN.
ATM can interact with Bank.


###Build Instructions
In the project directory
mkdir build && cd build
cmake ..
make


Run console_app for console based application
Run test_app for test cases.

Add miscellaneous test cases in test.cpp