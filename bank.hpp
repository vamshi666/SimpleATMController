#ifndef BANK_HPP
#define BANK_HPP

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "account.hpp"

class Bank{
    private:
        std::unordered_map<std::string, std::shared_ptr<Account>> m_accounts;
        std::string m_name;

    public:
        Bank();
        Bank(std::string& name);
        std::string getName();
        virtual bool createAccount(std::shared_ptr<Account> account );
        bool withdrawAmount(std::string& card_number, bool isChecking, int64_t amount);
        bool depositAmount(std::string& card_number, bool isChecking, int64_t amount);
        int64_t getBalance(std::string& card_num,  std::string& pin, bool isChecking);
        bool isPinValid(std::string card_num, std::string pin);
        bool isCardValid(std::string card_num);
        virtual bool changePin(std::string& new_pin, std::string& password);

        bool initialiseAccountsData();

};

#endif