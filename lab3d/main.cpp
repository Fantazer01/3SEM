//
// Created by oleg on 04.11.2021.
//

#include <iostream>
#include "Dialog.h"


using namespace lab3d;

int main() {
    /*
    system("clear");
    introduction();
    system("clear");
    */
    int rc;
    Lab3C::printedCircuitBoard _arduino;

    while ((rc = dialog()) != 0) {
        system("clear");
        try {
            switch(rc)
            {
                case 1:
                    AddContact(_arduino);
                    break;
                case 2:
                    EstablishConnect(_arduino);
                    break;
                case 3:
                    OutputPCB(_arduino);
                    break;
                case 4:
                    GroupOfContacts(_arduino);
                    break;
                case 5:
                    LengthOfTrack(_arduino);
                    break;
            }
            std::cin.get();
            std::cin.get();
            system("clear");
        } catch (const char err[]) {
            return 1;
        }

    }

    return 0;
}

