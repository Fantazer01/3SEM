//
// Created by oleg on 10.11.2021.
//

/*!
 * @file
 * @brief Description for class TableOfShip
 */

#ifndef LAB4_TABLEOFSHIPS_H
#define LAB4_TABLEOFSHIPS_H

#include "Ship.h"
#include <map>

namespace lab4 {

    /*!
     * @brief class TableOfShip describe table store ship's call sign pointer on ship.
     * @details When object is inserted to the table, table create dynamic copy this object and take it pointer.
     * Also table has iterator and const iterator
     */
    /*!
     * Table contains in self call sign of ship and pointer on object ship
     */
    class TableOfShips {
    public:
        class iterator;
        class const_iterator;

        /*!
         * @brief iterator for viewing and rewriting element of table
         */
        class iterator {
        private:
            std::map<std::string, Ship*>::iterator it;
        public:
            /*!
             * Default constructor, iterator point on nothing
             */
            iterator() = default;
            /*!
             * Inside constructor for class TableOfShips
             * @param _it
             */
            explicit iterator(const std::map<std::string, Ship*>::iterator &_it): it(_it) {}

            /*!
             * Compare two iterators
             * @param out_it
             * @return if its pointers equal true, else false
             */
            bool operator ==(const iterator &out_it) const { return this->it == out_it.it; }

            /*!
             * @brief Compare two iterators
             * @param out_it
             * @return if its pointers equal false, else true
             */
            bool operator !=(const iterator &out_it) const { return this->it != out_it.it; }

            /*!
             * @brief Moves the pointer to the next element
             * @return
             */
            const iterator& operator ++() { ++it; return (*this); }

            /*!
             * @brief Moves the pointer to the next element
             * @return pointer on previous element
             */
            iterator operator ++(int) { iterator itCopy(it); ++it; return itCopy; }

            /*!
             * @brief Give value of pointed element for reading or rewriting
             * @return
             */
            std::pair<const std::string, Ship*>& operator *() { return *it; }

            /*!
             * @brief Give pointed of pointed element for reading or rewriting
             * @return
             */
            std::pair<const std::string, Ship*>* operator ->() { return &(*it); }

            friend const_iterator;
            friend TableOfShips;
        };

        /*!
         * @brief const iterator for viewing element of table
         */
        class const_iterator {
        private:
            std::map<std::string, Ship*>::const_iterator it;
        public:
            /*!
             * Default constructor, const iterator point on nothing
             */
            const_iterator() = default;

            /*!
             * Inside constructor for class TableOfShips
             * @param _it
             */
            explicit const_iterator(const std::map<std::string, Ship*>::const_iterator &_it): it(_it) {}

            /*!
             * Constructor for converting iterator to const iterator
             * @param _iter_
             */
            const_iterator(TableOfShips::iterator _iter_) { it = _iter_.it; }

            /*!
             * Compare two iterators
             * @param out_it
             * @return if its pointers equal true, else false
             */
            bool operator ==(const const_iterator &out_it) const { return this->it == out_it.it; }

            /*!
             * @brief Compare two iterators
             * @param out_it
             * @return if its pointers equal false, else true
             */
            bool operator !=(const const_iterator &out_it) const { return this->it != out_it.it; }

            /*!
             * @brief Moves the pointer to the next element
             * @return
             */
            const_iterator& operator ++() { ++it; return (*this); }

            /*!
             * @brief Moves the pointer to the next element
             * @return pointer on previous element
             */
            const_iterator operator ++(int) { const_iterator itCopy(it); ++it; return itCopy; }

            /*!
             * @brief Give value of pointed element for reading or rewriting
             * @return
             */
            const std::pair<const std::string, Ship*>& operator *() const { return *it; }

            /*!
             * @brief Give pointed of pointed element for reading or rewriting
             * @return
             */
            const std::pair<const std::string, Ship*>* operator ->() { return &(*it); }

            friend TableOfShips;
        };
    private:
        std::map <std::string, Ship*> cells;
    public:
        /*!
         * @brief Default constructor
         * @details Create empty table
         */
        TableOfShips() = default;
        /*!
         * @brief Copy constructor
         * @param table
         */
        TableOfShips(const TableOfShips &table);
        /*!
         * @brief Destructor
         */
        ~TableOfShips();

        /*!
         * @brief This table is cleared and copied new table
         * @param table
         * @return
         */
        TableOfShips& operator = (const TableOfShips &table);

        /*!
         *
         * @return Number of cells in table
         */
        uint getNumOfGroup() const { return cells.size(); }

        /*!
         *
         * @return const iterator pointer on begin container table
         */
        const_iterator begin() const { return const_iterator(cells.cbegin()); }

        /*!
         *
         * @return const iterator pointer on end container table
         */
        const_iterator end() const { return const_iterator(cells.cend()); }

        /*!
         *
         * @return iterator pointer on begin container table
         */
        iterator begin() { return iterator(cells.begin()); }

        /*!
         *
         * @return iterator pointer on end container table
         */
        iterator end() { return iterator(cells.end()); }

        /*!
         * @brief Find element with call sign
         * @param first
         * @return iterator point on found element or equal end()
         */
        iterator find(const std::string& first) { return iterator(cells.find(first)); }

        /*!
         * @brief Find element with call sign
         * @param first
         * @return const iterator point on found element or equal end()
         */
        const_iterator find(const std::string& first) const { return const_iterator(cells.find(first)); }

        /*!
         * @brief Insert element to table
         * @param first call sign
         * @param second pointer on ship
         */
        void insert(const std::string& first, Ship * second);

        /*!
         * @brief Erase element from table
         * @param out_it
         */
        void erase(const const_iterator &out_it);

        /*!
         * @brief Put all cells to defined stream
         * @param output
         * @return
         */
        std::ostream& print(std::ostream &output) const;

        /*!
         * Doing same method print, because use it
         * @param output
         * @param table
         * @return
         */
        friend std::ostream& operator <<(std::ostream &output, const TableOfShips &table);

        friend iterator;
        friend const_iterator;
    };

}



#endif //LAB4_TABLEOFSHIPS_H
