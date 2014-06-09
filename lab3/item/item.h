#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <set>

namespace the_lion_king_saga {

    class Item {
        protected:
            std::string _name;
            std::string _description;
            std::set<std::string> _status;
            bool _usable;
            int _weight;
        public:
            Item(std::string, std::string, int, bool);
            Item(std::string, std::string, int);
            std::string name() const;
            std::string description() const;
            std::string status() const;
            int weight() const;
            bool isUsable() const;
            virtual void use();

            void addStatus(const std::string&);
            void removeStatus(const std::string&);
    };
}
#endif
