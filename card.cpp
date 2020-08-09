#include "card.hpp"

Card::Card():m_cardNumber(""), m_CVC(0),m_name(""){};

Card::Card(char* card_number, uint16_t cvc, char* name):
                m_cardNumber(card_number), m_CVC(cvc), m_name(name)
                {};

Card::Card(Card& other){
    m_cardNumber = other.getCardNumber();
    m_CVC = other.getCVC();
    m_name = other.getName();
}

std::string Card::getCardNumber(){
            return m_cardNumber;
        }  
uint16_t Card::getCVC(){
    return m_CVC;
}
std::string Card::getName(){
    return m_name;
}
