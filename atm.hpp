#ifndef ATM_HPP
#define ATM_HPP

#include "bank.hpp"
class Atm{
    private:
        Bank m_bank;
        int64_t m_cash = 0;
        std::string readCard();
        std::string readPin();
        int8_t readAccounttype();
        int8_t readAction();

    public:
        Atm();
        Atm(int64_t);
        
        void console();
        int64_t testController(char* cardnum, char* pinnum, int account_type, int action_type, int64_t amount);
};

#endif