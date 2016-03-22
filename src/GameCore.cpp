//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        GameCore.cpp                              //
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

//Header
#include "../include/GameCore.h"

//std
#include <sstream>
#include <algorithm>
#include <iterator>


//Usings
USING_NS_COREWORDSSEARCH;

// Constants / Enums / Typedefs //
const int GameCore::kRandomSeed     = -1;
const int GameCore::kUnlimitedHints = -1;
const int GameCore::kUnlimitedTries = -1;

// CTOR / DTOR //
GameCore::GameCore(const Options &options, std::vector<std::string> wordsList) :
    //m_board - Will be initialized in GameCore::initBoard().
    m_currTriesCount(0),
    m_currHintsCount(0),
    m_words(wordsList),
    //m_foundWords - Default initialized.
    m_remainingWords(wordsList),
    //m_wordsCoords - Will be initialized in GameCore::initBoard().
    m_options(options),
    m_status(Status::Continue)
{
    initRandomNumGenerator();
    initOperandCoords();
    initBoard();
}

GameCore::~GameCore()
{
    //Empty...
}


// Public Methods //
//Action
GameCore::TryStatus GameCore::checkCoords(const CoreCoord::Coord::Vec &coords)
{
    //COWTODO: Implement.
    TryStatus tryStatus;
    return tryStatus;
}

//Board
char GameCore::getLetterAt(const CoreCoord::Coord &coord) const
{
    return m_board[coord.y][coord.x];
}
const Board& GameCore::getBoard() const
{
    return m_board;
}

//Tries
int GameCore::getMaxTriesCount() const
{
    return m_options.maxTries;
}
int GameCore::getTriesCount() const
{
    return m_currTriesCount;
}
int GameCore::getRemainingTriesCount() const
{
    if(m_options.maxTries == GameCore::kUnlimitedTries)
        return kUnlimitedTries;

    return m_options.maxTries - m_currTriesCount;
}

//Hints
int GameCore::getMaxHintsCount() const
{
    return m_options.maxHints;
}
int GameCore::getUsedHintsCount() const
{
    return m_currHintsCount;
}
int GameCore::getRemainingHintsCount() const
{
    if(m_options.maxHints == GameCore::kUnlimitedHints)
        return kUnlimitedHints;

    return m_options.maxTries - m_currTriesCount;
}
CoreCoord::Coord::Vec GameCore::getHintCoords() const
{
    //COWTODO: Implement.
    return CoreCoord::Coord::Vec();
}

//Words
const std::vector<std::string>& GameCore::getWordsList() const
{
    return m_words;
}
const std::vector<std::string>& GameCore::getFoundWordsList() const
{
    return m_foundWords;
}
const std::vector<std::string>& GameCore::getRemainingWordsList() const
{
    return m_remainingWords;
}

//SearchStyle
bool GameCore::isSnakeStyleSearchEnabled() const
{
    return m_options.snakeStyleSearch;
}    
bool GameCore::isReverseStyleSearchEnabled() const
{
    return m_options.reverseStyleSearch;
}

//Others
Status GameCore::getStatus() const
{
    return m_status;
}
int GameCore::getSeed() const
{
    return m_options.seed;
}
int GameCore::getBoardWidth() const
{
    return m_options.boardWidth;
}
int GameCore::getBoardHeight() const
{
    return m_options.boardHeight;
}

//Helpers 
bool GameCore::isValidCoord(const CoreCoord::Coord &coord) const
{
    return coord.y >= 0 && m_board.size()
        && coord.x >= 0 && m_board[coord.y].size();
}

std::string GameCore::ascii() const
{
    std::stringstream ss;

    for(const auto &line : m_board)
    {
        for(const auto &letter : line)
            ss << letter;
        
        ss << std::endl;
    }
    
    return ss.str();
}


// Private Methods //
//Other
void GameCore::checkStatus()
{
    //COWTODO: Implement.
}

//Coords
bool GameCore::isValidCoordSequence(const CoreCoord::Coord::Vec &coords) const
{
    //COWTODO: Implement.
    return false;
}

std::string GameCore::coordsMakeWord(const CoreCoord::Coord::Vec &coords) const
{
    std::vector<std::string> sameSizeWordsList;
    sameSizeWordsList.reserve(m_remainingWords.size());
    
    std::copy_if(begin(m_remainingWords),
                 end(m_remainingWords),
                 std::back_inserter(sameSizeWordsList),
                 [&coords](const std::string &word)
                 {
                     return word.size() == coords.size();
                 });
    
    auto wordFromCoords = getWordFromCoords(coords);
    for(auto &word : sameSizeWordsList)
    {
        if(word == wordFromCoords)
            return word;
        
        std::reverse(begin(word), end(word));
        if(word == wordFromCoords)
            return word;
    }
    
    return "";
}

std::string GameCore::getWordFromCoords(const CoreCoord::Coord::Vec &coords) const
{  
    std::stringstream ss;
    for(const auto &coord : coords)
        ss << getLetterAt(coord);
    
    return ss.str();
}

const CoreCoord::Coord& GameCore::getOperandCoordForDirection(WordPlacementDirection direction) const
{
    return m_operandDirectionCoords[static_cast<int>(direction)];
}


//Init
void GameCore::initBoard()
{
    //COWTODO:
    m_board.reserve(m_options.boardHeight);
    for(int i = 0; i < m_options.boardHeight; ++i)
        m_board.push_back(std::vector<char>(m_options.boardWidth));
    

    std::vector<std::string> orderedWords(std::begin(m_words),
                                          std::end(m_words));
    
    //Sort backwards - The greater word will be placed on back of vector
    //did this way to ease the pop_back calls.
    std::sort(std::begin(m_words),
              std::end(m_words),
              [](const std::string &word1, const std::string &word2) {
                  return word1.size() > word2.size();
              });
    
    
    
    
}
void GameCore::initRandomNumGenerator()
{
    //COWTODO: Change this to C++ style.
    if(m_options.seed == GameCore::kRandomSeed)
        m_options.seed = static_cast<int>(time(nullptr));
    
    srand(m_options.seed);
}
void GameCore::initOperandCoords()
{
    m_operandDirectionCoords = {
        CoreCoord::Coord( 0, 1), //Horizontal
        CoreCoord::Coord( 1, 0), //Vertical
        CoreCoord::Coord(-1, 1), //DiagonalToTop
        CoreCoord::Coord( 1, 1), //DiagonalToBottom
    };
}


//Random
int GameCore::getRandomInt(int min, int max) const
{
    //COWTODO: Change this to C++ style.
    return min + (rand() % ((max + 1) - min));
}
CoreCoord::Coord GameCore::getRandomCoord() const
{
    return CoreCoord::Coord(getRandomInt(0, static_cast<int>(m_board.size())),     //y
                            getRandomInt(0, static_cast<int>(m_board[0].size()))); //x
                                         
}
CoreCoord::Coord GameCore::getRandomFreeCoord() const
{
    while(1)
    {
        const auto& coord = getRandomCoord();
        if(getLetterAt(coord) == GameCore::kEmptyChar)
            return coord;
    }
}


//Word
void GameCore::putWord(const std::string &word,
                       CoreCoord::Coord coord,
                       WordPlacementDirection direction)
{
    
    for(int i = 0; i < word.size(); ++i)
    {
        putLetterAt(coord, word[i]);
        coord += getOperandCoordForDirection(direction);
    }
}

void GameCore::putLetterAt(const CoreCoord::Coord &coord, char ch)
{
    m_board[coord.y][coord.x] = ch;
}