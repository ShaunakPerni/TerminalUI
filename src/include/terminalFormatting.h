/**
 * @file terminalFormatting.h
 * @brief This file provides a set of utilities for terminal output formatting.
 */

#ifndef TERMINALFORMATING_H
#define TERMINALFORMATING_H
#include <string>
#include <iostream>
#pragma once
namespace terminalFormatingColorcodes
{
    /**
     * @brief ANSI escape code for resetting all formatting
     */
    const std::string ANSI_RESET = "\033[0m";
    /**
     * @brief ANSI escape code for black text color
     */
    const std::string ANSI_BLACK = "\033[30m";
    /**
     * @brief ANSI escape code for red text color
     */
    const std::string ANSI_RED = "\033[31m";
    /**
     * @brief ANSI escape code for green text color
     */
    const std::string ANSI_GREEN = "\033[32m";
    /**
     * @brief ANSI escape code for yellow text color
     */
    const std::string ANSI_YELLOW = "\033[33m";
    /**
     * @brief ANSI escape code for blue text color
     */
    const std::string ANSI_BLUE = "\033[34m";
    /**
     * @brief ANSI escape code for magenta text color
     */
    const std::string ANSI_MAGENTA = "\033[35m";
    /**
     * @brief ANSI escape code for cyan text color
     */
    const std::string ANSI_CYAN = "\033[36m";
    /**
     * @brief ANSI escape code for white text color
     */
    const std::string ANSI_WHITE = "\033[37m";

    /**
     * @brief ANSI escape code for black background color
     */
    const std::string ANSI_BG_BLACK = "\033[40m";
    /**
     * @brief ANSI escape code for red background color
     */
    const std::string ANSI_BG_RED = "\033[41m";
    /**
     * @brief ANSI escape code for green background color
     */
    const std::string ANSI_BG_GREEN = "\033[42m";
    /**
     * @brief ANSI escape code for yellow background color
     */
    const std::string ANSI_BG_YELLOW = "\033[43m";
    /**
     * @brief ANSI escape code for blue background color
     */
    const std::string ANSI_BG_BLUE = "\033[44m";
    /**
     * @brief ANSI escape code for magenta background color
     */
    const std::string ANSI_BG_MAGENTA = "\033[45m";
    /**
     * @brief ANSI escape code for cyan background color
     */
    const std::string ANSI_BG_CYAN = "\033[46m";
    /**
     * @brief ANSI escape code for white background color
     */
    const std::string ANSI_BG_WHITE = "\033[47m";
}

namespace terminalFunctions
{
    /**
     * @brief Function to clear the terminal screen
     */
    void clearScreen()
    {
        #ifdef _WIN32
        std::cout << "\x1B[2J\x1B[H";
        #elif __linux__
        std::cout << "\x1B[2J\x1B[H";
        #elif __APPLE__
        std::cout << "\x1B[2J\x1B[H";
        #endif
    }
}

namespace terminalFormatingMisc
{
    /**
     * @brief A string used as a spacer in the terminal output
     */
    const std::string spacer = "        ";
}

#endif // TERMINALFORMATING_H

