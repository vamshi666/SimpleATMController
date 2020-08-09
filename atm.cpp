#include "atm.hpp"

Atm::Atm():m_cash(INT64_MAX/2){};

// Atm::~Atm()=default;

Atm::Atm(int64_t amount):m_cash(amount){};

std::string Atm::readCard(){
    std::string card_num;
    std::cout<<"Enter card number: ";
    std::cin>> card_num;
    return card_num;
}

std::string Atm::readPin(){
    std::string pin;
    std::cout<<"Enter PIN number: ";
    std::cin>> pin;
    return pin;
}

int8_t Atm::readAccounttype(){
    std::string accounttype="";
    std::cout<<"Menu:"<<std::endl;
    std::cout<<"1. Savings"<<std::endl;
    std::cout<<"2. Checkings"<<std::endl;
    std::cout<<"Enter your option: ";
    std::cin>>accounttype;
    if(accounttype == "1"){
        return 0;
    }
    else if(accounttype == "2"){
        return 1;
    }
    else
    {
        return -1;
    }
}

int8_t Atm::readAction(){
    std::string menu_option="";
    std::string amount = "";
    std::cout<<"Menu:\n";
    std::cout<<"1. Check Balance:"<<std::endl;
    std::cout<<"2. Withdraw Money"<<std::endl;
    std::cout<<"3. Deposit Money"<<std::endl;
    std::cout<<"Enter your option: ";
    std::cin>>menu_option;
    if(menu_option == "1"){
        return 1;
    }
    else if(menu_option == "2"){
        return 2;
    }
    else if(menu_option == "3"){
        return 3;
    }
    else
    {
        return -1;
    }
}

void Atm::console(){
    std::string card_num, pin;
    bool isChecking;
    int64_t withdraw_amount, deposit_amount;

    card_num = readCard();
    pin = readPin();
    if(m_bank.isPinValid(card_num, pin)){
        int account_type = readAccounttype();
        if(account_type == -1){
            std::cout<<"Invalid Option"<<std::endl;
            console();
        }
        else{
            isChecking = (bool)account_type;
        }

        int action = readAction();
        if(account_type == -1){
            std::cout<<"Invalid Option"<<std::endl;
            console();
        }
        else{
            if(action == 1){
                std::cout<<"Your Account Balance is: "<<m_bank.getBalance(card_num, pin, isChecking)<<std::endl;
                return;
            }
            else if(action == 2){
                std::string amount;
                std::cout<<"Enter amount: ";
                std::cin>>amount;
                withdraw_amount = atoi(amount.c_str());
                if(withdraw_amount<0){
                    std::cout<<"Invalid input"<<std::endl;
                    console();
                }
                if(m_cash > withdraw_amount){
                    if(m_bank.withdrawAmount(card_num, isChecking, withdraw_amount)){
                        std::cout<<"Take your cash..."<<std::endl;
                        std::cout<<"Balance: "<<m_bank.getBalance(card_num, pin, isChecking);

                        m_cash -=withdraw_amount;
                    }
                    else{
                        std::cout<<"Insufficient funds"<<std::endl;
                        return;
                    }
                }
                else{
                    std::cout<<"Insufficient cash in ATM"<<std::endl;
                    return;
                }
            }
            else if(action == 3){
                std::string amount;
                std::cout<<"Enter amount: ";
                std::cin>>amount;
                deposit_amount = atoi(amount.c_str());
                if(deposit_amount<0 ){
                    std::cout<<"Invalid input"<<std::endl;
                    console();
                }
                if((m_cash + deposit_amount)<INT64_MAX){
                    if(m_bank.depositAmount(card_num, isChecking, deposit_amount)){
                        // std::cout<<"Insert cash..."<<std::endl;
                        std::cout<<"Balance: "<<m_bank.getBalance(card_num, pin, isChecking)<<std::endl;
                        m_cash += deposit_amount;
                    }
                    else{
                        std::cout<<"Invalid input"<<std::endl;
                        console();
                    }
                }
                else{
                    std::cout<<"Cashbin overflow. Try with less cash"<<std::endl;
                    return;
                }
            }
        }
    }
    else{
        std::cout<<"Invalid PIN"<<std::endl;
        console();
        return;
    }
}


int64_t Atm::testController(char* cardnum, char* pinnum, int account_type, int action_type, int64_t amount){
    std::string card_num = cardnum, pin = pinnum;
    bool isChecking;
    int64_t withdraw_amount, deposit_amount;

    if(!m_bank.isCardValid(card_num))
        return -1;

    if(m_bank.isPinValid(card_num, pin)){
        if((account_type!=0) && (account_type!=1)){
            // std::cout<<"Invalid input"<<std::endl;
            return -2;
        }
        else{
            isChecking = (bool)account_type;
        }

        if((action_type!=1) && (action_type!=2) && (action_type!=3)){
            // std::cout<<"Invalid input"<<std::endl;
            return -2;
        }
        else{
            if(action_type == 1){
                return m_bank.getBalance(card_num, pin, isChecking);
            }
            else if(action_type == 2){
                if(amount<0){
                    // std::cout<<"Invalid input"<<std::endl;
                    return -2;
                }
                else if(m_cash > amount){
                    if(m_bank.withdrawAmount(card_num, isChecking, amount)){
                        // std::cout<<"Disbursing a cash of "<< amount<<std::endl;
                        return m_bank.getBalance(card_num, pin, isChecking);

                        m_cash-=amount;
                    }
                    else
                    {
                        // std::cout<<"Insufficient funds"<<std::endl;
                        return -3;
                    }
                }
            }
            else{
                if(amount<0 ){
                    // std::cout<<"Invalid input"<<std::endl;
                    return -2;
                }
                if((m_cash + amount)<INT64_MAX){
                    if(m_bank.depositAmount(card_num, isChecking, amount)){
                        return m_bank.getBalance(card_num, pin, isChecking);
                        m_cash += amount;
                    }
                    else{
                        // std::cout<<"Invalid input"<<std::endl;
                        return -2;
                    }
                }
                else{
                    // std::cout<<"Cashbin overflow. Try with less cash"<<std::endl;
                    return -4;
                }
            }
        }

    }
    else
    {
        // std::cout<<"Invalid Card/PIN"<<std::endl;
        return -1;
    }
    
}
