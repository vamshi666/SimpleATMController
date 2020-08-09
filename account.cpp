#include "account.hpp"

Account::Account():m_savings(0),m_checkings(0){};
Account::Account(std::shared_ptr<Card> card, char* pin, char* account_number, char* password, int64_t savings, int64_t checkings):
                    m_card(card),m_pin(pin), m_account_number(account_number), m_password(password), m_savings(savings), m_checkings(checkings),m_name(card->getName())
                    {};

Account::Account(Account& other):
            m_card(other.getCard()),m_pin(other.getPin()), m_account_number(other.getAccountNumber()), m_password(other.getPassword()), m_checkings(other.getCheckingsBalance()), m_savings(other.getSavingsBalance()), m_name(other.getCard()->getName())
            {};

int64_t Account::getCheckingsBalance(){
    return m_checkings;
}


int64_t Account::getSavingsBalance(){
    return m_savings;
}

bool Account::setCheckingsBalance(int64_t amount){
    m_checkings = amount;
    return true;
}


bool Account::setSavingsBalance(int64_t amount){
    m_savings= amount;
    return true;
}

std::string Account::getName(){
    return m_name;
}

std::string Account::getPin(){
    return m_pin;
}

std::string Account::getAccountNumber(){
    return m_account_number;
}

std::string Account::getPassword(){
    return m_password;
}

std::shared_ptr<Card> Account::getCard(){
    return m_card;
}
