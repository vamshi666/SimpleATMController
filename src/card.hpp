#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <memory>
#include <iostream>
class Card
{
    private:
        std::string m_cardNumber;
        uint16_t m_CVC;
        std::string m_name;
    public:
        Card();
        Card(char* card_number, uint16_t cvc, char* name); 
        Card(Card& other);
        std::string getCardNumber(); 
        virtual uint16_t getCVC();
        std::string getName();


};

#endif