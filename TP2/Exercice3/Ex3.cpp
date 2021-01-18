#include "Ex3.h"

#include <chrono>
#include <thread>

int MinuteHand::get_minutes() 
{
    return this->_minutes;
}

SecondHand::SecondHand(MinuteHand& mh)
    : _min_hand { mh }
{}

int SecondHand::get_seconds() 
{
    return this->_seconds;
}

MinuteHand& SecondHand::get_minute_hand()
{
    return this->_min_hand;
}

void MinuteHand::advance()
{
    _minutes += 1;
    if (_minutes == 60){
        _minutes = 0;
    }
}

void SecondHand::advance()
{
    _seconds += 1;
    if (_seconds == 60){
        _seconds = 0;
        _min_hand.advance();
    }
}

std::ostream& operator<<(std::ostream& stream, MinuteHand& mh) 
{
    return stream << mh.get_minutes() << "min";
}

std::ostream& operator<<(std::ostream& stream, SecondHand& sh) 
{
    return stream << sh.get_minute_hand() << " " << sh.get_seconds() << "sec";
}

Clock::Clock(MinuteHand& mh, SecondHand& sh)
    : _min_hand { mh },
      _sec_hand { sh }
{}

void Clock::tick()
{
    _sec_hand.advance();
}

int main(int argc, char** argv){
    //const auto events = parse_events(argc, argv);


    MinuteHand mh;
    SecondHand sh(mh);
    Clock clock(mh, sh);
    std::cout<<sh<<std::endl;
    const auto program_duration = 15; 
    for (int i = 0; i < program_duration; ++i)
    {
        clock.tick();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<sh<<std::endl;
    }

    return 0;
}