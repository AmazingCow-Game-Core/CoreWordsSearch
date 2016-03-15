//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        GameCore.h                                //
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

#ifndef __CoreWordsSearch_include_GameCore_h__
#define __CoreWordsSearch_include_GameCore_h__

//std
#include <string>
#include <vector>
//CoreWordsSearch
#include "CoreWordsSearch_Utils.h"
#include "CoreWordsSearch_Types.h"
//CoreCoord
#include "CoreCoord.h"

NS_COREWORDSSEARCH_BEGIN

class GameCore
{
    // Constants / Enums / Typedefs //
public:
    static const int kRandomSeed;
    static const int kUnlimitedHints;
    static const int kUnlimitedTries;


    // Inner Types //
public:
    struct Options
    {
        int boardHeight;
        int boardWidth;

        int seed     = kRandomSeed;
        int maxHints = kUnlimitedHints;
        int maxTries = kUnlimitedTries;

        bool snakeStyleSearch   = false;
        bool reverseStyleSearch = false;
    };

    struct TryStatus
    {
        bool                  isValid;
        std::string           word;
        CoreCoord::Coord::Vec coords;        
    };


    // CTOR / DTOR //
public:
    GameCore(const Options &options, std::vector<std::string> wordsList);
    ~GameCore();


    // Public Methods //
public:    
    //Action
    TryStatus checkCoords(const CoreCoord::Coord::Vec &coords);

    //Board
    char getLetterAt(const CoreCoord::Coord &coord) const;
    const Board& getBoard() const;

    //Tries
    int getMaxTriesCount() const;
    int getTriesCount() const;
    int getRemainingTriesCount() const;

    //Hints
    int getMaxHintsCount() const;
    int getUsedHintsCount() const;
    int getRemainingHintsCount() const;
    CoreCoord::Coord::Vec getHintCoords() const;

    //Words
    const std::vector<std::string>& getWordsList() const;
    const std::vector<std::string>& getFoundWordsList() const;
    const std::vector<std::string>& getRemainingWordsList() const;

    //SearchStyle
    bool isSnakeStyleSearchEnabled() const;    
    bool isReverseStyleSearchEnabled() const;

    //Others
    Status getStatus() const;
    int getSeed() const;
    int getBoardWidth() const;
    int getBoardHeight() const;

    //Helpers 
    bool isValidCoord(const CoreCoord::Coord &coord) const;

    std::string ascii() const;


    // Private Methods //
private:
    bool isValidCoordSequence(const CoreCoord::Coord::Vec &coords) const;

    std::string coordsMakeWord(const CoreCoord::Coord::Vec &coords) const;
    std::string getWordFromCoords(const CoreCoord::Coord::Vec &coords) const;
    
    void checkStatus();

    void initBoard();

    int getRandomInt(int min, int max) const;

    // iVars //
private:
    //Board
    Board m_board;

    //Tries / Hints
    int m_currTriesCount;
    int m_currHintsCount;

    //Words
    std::vector<std::string>      m_words;
    std::vector<std::string>      m_foundWords;
    std::vector<std::string>      m_remainingWords;    
    std::vector<CoreCoord::Coord> m_wordsCoords;

    //Options
    Options m_options;
    
    //Status
    Status m_status;
};

NS_COREWORDSSEARCH_END
#endif // defined(__CoreWordsSearch_include_GameCore_h__) //
