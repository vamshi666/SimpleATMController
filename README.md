**Simple ATM Controller**

There are four main entities here:
1. Bank,
1. Account,
1. Card and
1. ATM

Bank has Account information.

Account has Card information.

Card is associated with a number and PIN.

ATM can interact with Bank.

**Build Instructions**

In the project directory
```
mkdir build && cd build
cmake ..
make
```


For console based application, run
```
./console_app
```

To run test cases, run
```
./test_app
```

Add miscellaneous test cases in test.cpp