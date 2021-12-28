//
// Created by oleg on 10.11.2021.
//

#ifndef LAB4_TABLEOFSHIPS_H
#define LAB4_TABLEOFSHIPS_H

#include "Ship.h"
#include <map>

namespace lab4 {

    /*!
     * Table contains in self call sign of ship and pointer on object ship
     */
    class TableOfShips {
    public:
        class iterator {
        private:
            std::map<std::string, Ship*>::iterator it;
        public:
            iterator() = default;
            explicit iterator(const std::map<std::string, Ship*>::iterator &_it): it(_it) {}

            std::map<std::string, Ship*>::iterator getValue() const { return it; }
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
            const_iterator(TableOfShips::iterator _it_) { it = _it_.getValue(); }

            std::map<std::string, Ship*>::const_iterator getCIT() const { return it; }

            bool operator ==(const const_iterator &out_it) const { return this->it == out_it.it; }
            bool operator !=(const const_iterator &out_it) const { return this->it != out_it.it; }
            const_iterator& operator ++() { ++it; return (*this); }
            const_iterator operator ++(int) { const_iterator itCopy(it); ++it; return itCopy; }
            std::pair<std::string, Ship*> operator *() const { return *it; }

        };
    private:
        std::map <std::string, Ship*> cells;
    public:
        TableOfShips() = default;
        TableOfShips(const TableOfShips &table);
        ~TableOfShips();

        TableOfShips& operator = (const TableOfShips &table);

        uint getNumOfGroup() const { return cells.size(); }

        const_iterator begin() const { return const_iterator(cells.cbegin()); }
        const_iterator end() const { return const_iterator(cells.cend()); }
        iterator begin() { return iterator(cells.begin()); }
        iterator end() { return iterator(cells.end()); }

        iterator find(const std::string& first) { return iterator(cells.find(first)); }
        const_iterator find(const std::string& first) const { return const_iterator(cells.find(first)); }
        void insert(const std::string& first, Ship * second);
        void erase(const const_iterator &out_it);

        std::ostream& print(std::ostream &output) const;
        friend std::ostream& operator <<(std::ostream &output, const TableOfShips &table);

        friend iterator;
        friend const_iterator;
    };

}



#endif //LAB4_TABLEOFSHIPS_H
