//
// Created by oleg on 26.11.2021.
//

    /*!
     * @file
     * @details Target is air for planes; target is earth for ships and other...
     */

#ifndef LAB4_TARGET_H
#define LAB4_TARGET_H

namespace lab4 {

    /// Target can be 2 type
    enum Target {
        earth, ///< earth mean that target-object isn't in air and not under water
        air ///< air mean that target-object is in air
    };

}

#endif //LAB4_TARGET_H
