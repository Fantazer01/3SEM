//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_TABLEOFSHIPS_H
#define LAB4_TABLEOFSHIPS_H

#include "Ship.h"
#include <map>

namespace lab4 {

    class TableOfShips {
    public:
        class iterator {
        private:
            std::map<std::string, Ship*>::iterator it;
        public:
            iterator() = default;
            explicit iterator(const std::map<std::string, Ship*>::iterator &_it): it(_it) {}

            bool operator ==(const iterator &out_it) const { return this->it == out_it.it; }
            bool operator !=(const iterator &out_it) const { return this->it != out_it.it; }
            iterator& operator ++() { ++it; return (*this); }
            iterator operator ++(int) { iterator itCopy(it); ++it; return itCopy; }
            std::pair<const std::string, Ship*>& operator *() { return *it; }
            std::pair<const std::string, Ship*>* operator ->() { return &(*it); }

        };

        class const_iterator {
        private:
            std::map<std::string, Ship*>::const_iterator it;
        public:
            const_iterator() = default;
            explicit const_iterator(const std::map<std::string, Ship*>::const_iterator &_it): it(_it) {}

            std::map<std::string, Ship*>::const_iterator getCIT() const { return it; }

            bool operator ==(const const_iterator &out_it) const { return this->it == out_it.it; }
            bool operator !=(const const_iterator &out_it) const { return this->it != out_it.it; }
            const_iterator& operator ++() { ++it; return (*this); }
            const_iterator operator ++(int) { const_iterator itCopy(it); ++it; return itCopy; }
            const std::pair<std::string, Ship*>& operator *() const { return *it; }

        };
    private:
        std::map <std::string, Ship*> cells;//first - callsign, second - pointer
    public:
        TableOfShips() = default;

        uint getNumOfGroup() const { return cells.size(); }

        const_iterator begin() const { return const_iterator(cells.cbegin()); }
        const_iterator end() const { return const_iterator(cells.cend()); }

        Ship* find(const std::string& first) const { return cells.find(first)->second; }
        void insert(const std::string& first, Ship * second) { cells.insert(std::make_pair(first, second)); }
        void erase(const const_iterator &out_it) { cells.erase(out_it.getCIT()); }

        std::ostream& print(std::ostream &output) const;
        friend std::ostream& operator <<(std::ostream &output, const TableOfShips &table);

        friend iterator;
        friend const_iterator;
    };

}



#endif //LAB4_TABLEOFSHIPS_H
