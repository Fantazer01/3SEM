//
// Created by oleg on 04.11.2021.
//

#ifndef LAB3D_DIALOG_H
#define LAB3D_DIALOG_H

#include "lib/Printed_Circuit_Board.h"

namespace lab3d {

    void introduction();
    int dialog();

    //menu functions
    void AddContact(Lab3C::printedCircuitBoard &);
    void EstablishConnect(Lab3C::printedCircuitBoard &);
    void RemoveContact(Lab3C::printedCircuitBoard &);
    void GroupOfContacts(Lab3C::printedCircuitBoard &);
    void LengthOfTrack(Lab3C::printedCircuitBoard &);
    void OutputPCB(Lab3C::printedCircuitBoard &);


}


#endif //LAB3D_DIALOG_H
