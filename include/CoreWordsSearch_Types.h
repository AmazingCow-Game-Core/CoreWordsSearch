//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        CoreWordsSearch_Types.h                   //
//            █ █        █ █        CoreWordsSearch                           //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __CoreWordsSearch_include_CoreWordsSearch_Types_h__
#define __CoreWordsSearch_include_CoreWordsSearch_Types_h__

//std
#include <vector>
#include <ostream>
//CoreWordsSearch
#include "CoreWordsSearch_Utils.h"
//CoreCoord
#include "CoreCoord.h"

NS_COREWORDSSEARCH_BEGIN

// Enums //

///@brief Defines the possible states of Game Core.
///@see GameCore.
enum class Status 
{
    Victory, ///< Game is over - Player won, i.e. Player had find out all words.
    Defeat,  ///< Game is over - Player lose i.e. No remaining moves, and all words aren't found..
    Continue ///< Game is not over - Keep playing...
};

///@brief Output the name of status. (ex: Status::Victory)
///@see Status.
std::ostream& operator <<(std::ostream &os, Status status);

// Typedefs //
typedef std::vector<std::vector<char>> Board;

NS_COREWORDSSEARCH_END
#endif // defined(__CoreWordsSearch_include_CoreWordsSearch_Types_h__) //
