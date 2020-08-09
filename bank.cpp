#include "bank.hpp"

Bank::Bank(){
    initialiseAccountsData();
}
// Bank::~Bank(){
//     for(auto i:m_accounts){
//         m_accounts.erase(i.first);
//     }
//     // delete m_name;
// }
Bank::Bank(std::string& name):m_name(name){
    initialiseAccountsData();
};
std::string Bank::getName(){
    return m_name;
}

bool Bank::withdrawAmount(std::string& card_number, bool isChecking, int64_t amount){
    if(isChecking){
        auto balance = m_accounts[card_number]->getCheckingsBalance();
        if(balance>=amount){
            m_accounts[card_number]->setCheckingsBalance(balance-amount);
            return true;
        }
        else
        {
            return false;
        }
        
    }
    else{
        auto balance = m_accounts[card_number]->getSavingsBalance();
        if(balance>=amount){
            m_accounts[card_number]->setSavingsBalance(balance-amount);
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Bank::depositAmount(std::string& card_number, bool isChecking, int64_t amount){
    if(amount <0)
        return false;

    if(isChecking){
        int64_t net = m_accounts[card_number]->getCheckingsBalance()+amount;
        m_accounts[card_number]->setCheckingsBalance(net);
        return true;
    }
    else{
        int64_t net = m_accounts[card_number]->getSavingsBalance()+amount;
        m_accounts[card_number]->setSavingsBalance(net);
        return true;
    }
}

int64_t Bank::getBalance(std::string& card_number, std::string& pin, bool isChecking){
    if(m_accounts[card_number]->getPin() == pin){
        if(isChecking)
            return m_accounts[card_number]->getCheckingsBalance();
        else
        {
            return m_accounts[card_number]->getSavingsBalance();
        }
    }
    return -1;
}

bool Bank::createAccount(std::shared_ptr<Account> account ){
    // std::cout<<"cardnumber "<<account->getCard()->getCardNumber()<<" is added" <<std::endl;
    m_accounts[account->getCard()->getCardNumber()] = account;
}

bool Bank::isCardValid(std::string card_num){
    if(m_accounts.find(card_num)==m_accounts.end()){
        return false;
    }
    return true;
}


bool Bank::isPinValid(std::string card_num, std::string pin){
    return (m_accounts[card_num]->getPin() == pin);
}

bool Bank::initialiseAccountsData(){
    Card c1((char *)"20200001",1,(char *)"User20200001");
    Card c2((char *)"20200002",2,(char *)"User20200002");
    Card c3((char *)"20200003",3,(char *)"User20200003");

    std::shared_ptr<Card> c1_ptr= std::make_shared<Card>(c1);
    std::shared_ptr<Card> c2_ptr= std::make_shared<Card>(c2);
    std::shared_ptr<Card> c3_ptr= std::make_shared<Card>(c3);

    Account ac1( c1_ptr, (char *)"0001", (char *)"10020200001", (char *)"pswd0001", 0,0);
    Account ac2( c2_ptr, (char *)"0002", (char *)"10020200002", (char *)"pswd0002", 0,0);
    Account ac3( c3_ptr, (char *)"0003", (char *)"10020200003", (char *)"pswd0003", 0,0);
    
    std::shared_ptr<Account> ac1_ptr= std::make_shared<Account>(ac1);
    std::shared_ptr<Account> ac2_ptr= std::make_shared<Account>(ac2);
    std::shared_ptr<Account> ac3_ptr= std::make_shared<Account>(ac3);

    bool status;
    status = createAccount(ac1_ptr);
    status = createAccount(ac2_ptr);
    status = createAccount(ac3_ptr);
}

bool Bank::changePin(std::string& new_pin, std::string& password){};