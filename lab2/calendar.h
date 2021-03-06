#ifndef CALENDAR_H
#define CALENDAR_H
#include <map>
#include <vector>
#include <iostream>
#include <string>

namespace lab2 {
    template <typename T>
    class Calendar {
    private:
        T _today;
        std::map<T, std::vector<std::string> > _eventList;

    public:
        Calendar();
        template <typename S> Calendar(const Calendar<S> &);
        Calendar(const Calendar<T> &);

        const T& getToday() const;
        const std::map<T, std::vector<std::string> >& getEventList() const;

        bool add_event(std::string, int, int, int);
        bool add_event(std::string, int, int);
        bool add_event(std::string, int);
        bool add_event(std::string);
        bool add_event(std::string, T);

        bool remove_event(std::string, int, int, int);
        bool remove_event(std::string, int, int);
        bool remove_event(std::string, int);
        bool remove_event(std::string);
        bool remove_event(std::string, T);

        bool set_date(int, int, int);
    };

    template <typename T>
    Calendar<T>::Calendar() : _today(T()), _eventList() {}

    template <typename T> 
    Calendar<T>::Calendar(const Calendar<T> & c) : _today(c.getToday()), _eventList(c.getEventList()){}

    template <typename T>
    template <typename S> 
    Calendar<T>::Calendar(const Calendar<S> & c) : _today(c.getToday()){
        //typename std::map<S,std::vector<std::string> >::const_iterator it;
        for(auto it = c.getEventList().begin(); it != c.getEventList().end(); ++it){
            _eventList[T(it->first)] = it->second;
        }
    }

    template <typename T>
    const T& Calendar<T>::getToday() const{
        return _today;
    }

    template <typename T>
    const std::map<T, std::vector<std::string> >& Calendar<T>::getEventList() const{
        return _eventList;
    }

    // Add_event
    template <typename T>
    bool Calendar<T>::add_event(std::string text, int day, int month, int year){
        try{
            return Calendar<T>::add_event(text, T(year, month, day));
        } catch(...){ return false; }
    }

    template <typename T>
    bool Calendar<T>::add_event(std::string text, int day, int month){
        return Calendar<T>::add_event(text, day, month, _today.year());
    }

    template <typename T>
    bool Calendar<T>::add_event(std::string text, int day){
        return Calendar<T>::add_event(text, day, _today.month(), _today.year());
    }

    template <typename T>
    bool Calendar<T>::add_event(std::string text){
        return Calendar<T>::add_event(text, _today);
    }

    template <typename T>
    bool Calendar<T>::add_event(std::string text, T date){
        //typename std::vector<std::string>::const_iterator
        for(auto it = _eventList[date].begin(); it < _eventList[date].end(); ++it){
            if(*it == text) return false;
        }
        _eventList[date].push_back(text);
        return true;
    }

    // Remove event
    template <typename T>
    bool Calendar<T>::remove_event(std::string text, int day, int month, int year){
        try {
            return Calendar<T>::remove_event(text, T(year, month, day));
        } catch(...){ return false; }
    }

    template <typename T>
    bool Calendar<T>::remove_event(std::string text, int day, int month){
        return Calendar<T>::remove_event(text, day, month, _today.year());
    }

    template <typename T>
    bool Calendar<T>::remove_event(std::string text, int day){
        return Calendar<T>::remove_event(text, day, _today.month(), _today.year());
    }

    template <typename T>
    bool Calendar<T>::remove_event(std::string text){
        return Calendar<T>::remove_event(text, _today);
    }

    template <typename T>
    bool Calendar<T>::remove_event(std::string text, T date){
        //typename std::vector<std::string>::iterator
        for(auto it = _eventList[date].begin(); it < _eventList[date].end(); ++it){
            if(*it == text){
                _eventList[date].erase(it);
                return true;
            }
        }
        return false;       
    }

    template <typename T>
    bool Calendar<T>::set_date(int year, int month, int day){
        try{
            _today.set_date(year, month, day);
        }catch(...){
            return false;
        }
        return true;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Calendar<T>& c) {
        //typename std::map<T,std::vector<std::string> >::const_iterator itMap;
        for(auto itMap = c.getEventList().begin(); itMap != c.getEventList().end(); ++itMap){
            if(itMap->first > c.getToday()) {
                //typename std::vector<std::string>::const_iterator itVector;
                for(auto itVector = itMap->second.begin(); itVector != itMap->second.end(); ++itVector){
                    os << itMap->first << " : " << *itVector << '\n'; 
                }
            }
        } 
        return os;
    }

}
#endif
