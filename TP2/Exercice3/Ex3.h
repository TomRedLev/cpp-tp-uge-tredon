#pragma once
#include <iostream>
#include <ostream>

class MinuteHand {
public:
    int get_minutes();
    void advance();

private:
    int _minutes = 0;                      
};

std::ostream& operator<<(std::ostream& stream, MinuteHand& mh);

class SecondHand {
public:
    SecondHand(MinuteHand& mh);
    int get_seconds();
    MinuteHand& get_minute_hand();
    void advance();

private:
    int _seconds = 0;
    MinuteHand& _min_hand;                      
};

std::ostream& operator<<(std::ostream& stream, SecondHand& sh);

class Clock {
public:
    Clock(MinuteHand& mh, SecondHand& sh);
    void tick();

private:
    MinuteHand& _min_hand;  
    SecondHand& _sec_hand;                     
};