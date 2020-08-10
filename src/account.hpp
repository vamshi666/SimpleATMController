#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "card.hpp"
#include <memory>
class Account{
    private:
        std::shared_ptr<Card> m_card;
        std::string m_pin;
        std::string m_account_number;
        std::string m_password;
        std::string m_name;
        
        int64_t m_savings;
        int64_t m_checkings;
    
    public:
        Account();
        Account(std::shared_ptr<Card> card, char* pin, char* account_number, char* password, int64_t savings, int64_t checkings);
        Account(Account& other);
        int64_t getSavingsBalance();
        int64_t getCheckingsBalance();
        bool setSavingsBalance(int64_t amount);
        bool setCheckingsBalance(int64_t amount);
        std::string getName();
        std::string getPin();
        std::string getAccountNumber();
        std::string getPassword();
        std::shared_ptr<Card> getCard();

};



#endif