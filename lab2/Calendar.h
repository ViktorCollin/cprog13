#ifndef CALENDAR_H
#define CALENDAR_H
#include <map>
#include <vector>
#include <iostream>
#include "Gregorian.h"
#include "Julian.h"

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
        ~Calendar();
        
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
    
    // template <typename T>
    //     Calendar<T>::~Calendar(){
    //         delete _today;
    //     }
    
    template <typename T>
    Calendar<T>::Calendar() : _today(T()), _eventList() {}
    
    template <typename T> 
    Calendar<T>::Calendar(const Calendar<T> & c) : _today(c.getToday()), _eventList(c.getEventList()){}
    
    template <typename T>
    template <typename S> 
    Calendar<T>::Calendar(const Calendar<S> & c) : _today(c.getToday()){
        for(auto it = c.getEventList.begin(); it != c.getEventList.end(); ++it){
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
    
    template <typename T>
    bool Calendar<T>::add_event(std::string text, T date){
        return false;
    }
    
    template <typename T>
    bool Calendar<T>::remove_event(std::string text, T date){
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
        for(auto itMap = c.getEventList().find(c.getToday()); itMap != c.getEventList().end(); ++itMap){
            for(auto itVector = itMap->second.begin(); itVector != itMap->second.end(); ++itVector){
                os << itMap->first << " : " << itVector->second << std::endl; 
            }
        } 
        return os;
    }
    
}
#endif
