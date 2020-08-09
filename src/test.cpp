#include "atm.hpp"
#include <gtest/gtest.h>

// Assuming that the following accounts already exit:
//          Card Numbers        PIN
//           "20200001"         "0001" 
//           "20200002"         "0002"   
//           "20200003"         "0003"   


// If something goes wrong, controller returns the following error codes. Else, returns the current balance.
// -1 --> Invalid PIN/Card Number
// -2 --> Invalid option
// -2 --> Insufficient funds
// -2 --> Cashbin overflow/ Cannot accept deposit

TEST(AtmControllerTest, DepositandWithdrawCheck){
    Atm atm;
    ASSERT_EQ(150, atm.testController((char *)"20200001",(char *)"0001",1,3,150));
    ASSERT_EQ(15000, atm.testController((char *)"20200002",(char *)"0002",1,3,15000));
    ASSERT_EQ(300, atm.testController((char *)"20200001",(char *)"0001",1,3,150));
    ASSERT_EQ(0, atm.testController((char *)"20200001",(char *)"0001",0,1,150));
    ASSERT_EQ(250, atm.testController((char *)"20200002",(char *)"0002",0,3,250));
    ASSERT_EQ(14750, atm.testController((char *)"20200002",(char *)"0002",1,2,250));
}

TEST(AtmControllerTest, CornerCaseChecks){
    Atm atm;

    ASSERT_EQ(-1, atm.testController((char *)"20200004",(char *)"0001",1,3,150));
    ASSERT_EQ(-1, atm.testController((char *)"20200001",(char *)"0003",1,3,150));

    ASSERT_EQ(-2, atm.testController((char *)"20200001",(char *)"0001",1,3,-150));
    ASSERT_EQ(-2, atm.testController((char *)"20200002",(char *)"0002",2,3,15000));
    ASSERT_EQ(-2, atm.testController((char *)"20200002",(char *)"0002",1,4,15000));

    ASSERT_EQ(15000, atm.testController((char *)"20200002",(char *)"0002",1,3,15000));
    ASSERT_EQ(-3, atm.testController((char *)"20200002",(char *)"0002",1,2,15001));


    ASSERT_EQ(-4, atm.testController((char *)"20200003",(char *)"0003",0,3,INT64_MAX/2+1));
}

TEST(AtmControllerTest, Miscel){
    Atm atm;
    // ASSERT_EQ(balance, atm.testController(card_number,pin,savings(0)/checkings(1),check balance(1)/ withdraw(2)/ deposit(3),amount));

}


int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}