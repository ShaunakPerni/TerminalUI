#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "terminalFormatting.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <limits>
#include <functional>

namespace Package_TerminalUI
{
    namespace formattedOutputs
    {
        /**
         * @brief Generate a title bar
         * @param text The text to be displayed in the title bar
         * @param color The color of the title bar
         */
        void generateTitleBar(std::string text, std::string color)
        {
            terminalFunctions::clearScreen();
            std::cout << color << text << "\n" << terminalFormatingColorcodes::ANSI_RESET;
        }

        /**
         * @brief Print headers for a menu
         * @param selection The selected header
         * @param Headers A vector of header strings
         * @param colorActive The color for the selected header
         * @param colorInactive The color for the unselected headers
         */
        void printHeaders(int selection, const std::vector<std::string> &Headers, std::string colorActive, std::string colorInactive)
        {
            for (int nHeader = 0; nHeader < Headers.size(); nHeader++)
            {
                selection == nHeader ? std::cout << colorActive << Headers[nHeader] << terminalFormatingColorcodes::ANSI_RESET
                                                 << "\t"
                                     : std::cout << colorInactive << Headers[nHeader] << terminalFormatingColorcodes::ANSI_RESET << "\t";
            }
            std::cout << std::endl;
        }

        /**
         * @brief Print a menu with options
         * @param directionVertical If true the menu is printed vertically, otherwise horizontally
         * @param options A vector of strings representing the menu options
         */
        void optionsMenu(bool directionVertical, std::vector<std::string> options)
        {
            std::string endline = "";
            directionVertical ? endline = "\n" : endline = "\t";
            for (std::string option : options)
            {
                std::cout << option << endline;
            }
            std::cout << std::endl;
        }

        /**
         * @brief Print a menu with options
         * @param directionVertical If true the menu is printed vertically, otherwise horizontally
         * @param options A vector of strings representing the menu options
         * @param color The color of the menu
         */
        void optionsMenu(bool directionVertical, std::vector<std::string> options, std::string color)
        {
            std::string endline = "";
            directionVertical ? endline = "\n" : endline = "\t";
            for (std::string option : options)
            {
                std::cout << color << option << terminalFormatingColorcodes::ANSI_RESET << endline;
            }
            std::cout << std::endl;
        }

        /**
         * @brief Add a marker in the output
         * @param MarkerColor The color of the marker
         */
        void addMarker(std::string MarkerColor)
        {
            std::cout << MarkerColor;
        }

        /**
         * @brief Reset the marker in the output
         */
        void resetMarker()
        {
            std::cout << terminalFormatingColorcodes::ANSI_RESET;
        }

        /**
         * @brief Highlight a string in the output
         * @param text The string to be highlighted
         * @param HighlightColor The color of the highlight
         */
        void highlightText(std::string text, std::string HighlightColor)
        {
            std::cout << HighlightColor << text << terminalFormatingColorcodes::ANSI_RESET;
        }

        /**
         * @brief A struct to hold a string and its associated color
         */
        struct stringWColor
        {
            std::string optionString;
            std::string color;
        };

        /**
         * @brief Print a menu with options and custom colors
         * @param directionVertical If true the menu is printed vertically, otherwise horizontally
         * @param optionsStruct A vector of stringWColor structs representing the menu options and their colors
         */
        void fancyOptionsMenu(bool directionVertical, std::vector<stringWColor> optionsStruct)
        {
            std::string endline = "";
            directionVertical ? endline = "\n" : endline = "\t";
            for (stringWColor option : optionsStruct)
            {
                std::cout << option.color << option.optionString << terminalFormatingColorcodes::ANSI_RESET << endline;
                std::cout << "";
            }
            std::cout << std::endl;
        }

        /**
         * @brief Print a value with a binary color threshold
         * @param data The value to be printed
         * @param colorAbove The color to use if the value is above the midpoint
         * @param colorBelow The color to use if the value is below the midpoint
         * @param midPoint The midpoint to be used for the threshold
         */
        template <typename ratedDataType>
        void binaryColorThresholdFormatedValue(ratedDataType data, std::string colorAbove, std::string colorBelow, ratedDataType midPoint)
        {
            data >= midPoint ? std::cout << colorAbove : std::cout << colorBelow;
            std::cout << data << terminalFormatingColorcodes::ANSI_RESET;
        }

        /**
         * @brief Print a value with an alternating color
         * @param printValue The value to be printed
         * @param alternator A pointer to a boolean that is flipped each time the function is called
         * @param Color1 The first color
         * @param Color2 The second color
         */
        void binaryColorAlternateFormatedValue(std::string printValue, bool *alternator, std::string Color1, std::string Color2)
        {
            *alternator ? addMarker(Color1) : addMarker(Color2);
            std::cout << printValue;
            resetMarker();
            *alternator = !*alternator;
        }
    }
    namespace formattedPrompts
    {
        /**
         * @brief Prompt the user for input with a given symbol
         * @tparam returnData The type of the input data to be returned
         * @param promptSymbol The symbol to display as a prompt
         * @return The user input converted to returnData type
         */
        template <typename returnData>
        returnData customPrompt(std::string promptSymbol)
        {
            returnData tempReturnData;
            std::cout << promptSymbol;
            std::cin >> tempReturnData;
            return tempReturnData;
        }

        /**
         * @brief Prompt the user for input with a given symbol and color
         * @tparam returnData The type of the input data to be returned
         * @param promptSymbol The symbol to display as a prompt
         * @param color The color of the prompt symbol
         * @return The user input converted to returnData type
         */
        template <typename returnData>
        returnData customPrompt(std::string promptSymbol, std::string color)
        {
            returnData tempReturnData;
            std::cout << color << promptSymbol;
            std::cin >> tempReturnData;
            std::cout << terminalFormatingColorcodes::ANSI_RESET;
            return tempReturnData;
        }

        /**
         * @brief Prompt the user for two inputs with messages and colors
         * @tparam returnDataMember0 The type of the first input data
         * @tparam returnDataMember1 The type of the second input data
         * @param formMessage The message to display before prompting
         * @param promptSymbol The symbol to display as a prompt
         * @param input0Message The message for the first input prompt
         * @param input1Message The message for the second input prompt
         * @param input0Color The color of the first input prompt
         * @param input1Color The color of the second input prompt
         * @return A pair containing the first and second user inputs
         */
        template <typename returnDataMember0, typename returnDataMember1>
        auto customPromptFormDualInputs(std::string formMessage = "", std::string promptSymbol = ">:", std::string input0Message = "", std::string input1Message = "", std::string input0Color = "", std::string input1Color = "")
        {
            std::cout << formMessage << std::endl;
            returnDataMember0 rData0;
            returnDataMember1 rData1;

            std::cout << input0Message << promptSymbol << terminalFormatingColorcodes::ANSI_RESET << input0Color;

            while (!(std::cin >> rData0))
            {
                std::cout << terminalFormatingColorcodes::ANSI_RESET << "Invalid input. Please enter a valid " << typeid(returnDataMember0).name() << ": " << input0Color;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cout << terminalFormatingColorcodes::ANSI_RESET << input1Message << promptSymbol << terminalFormatingColorcodes::ANSI_RESET << input1Color;

            while (!(std::cin >> rData1))
            {
                std::cout << terminalFormatingColorcodes::ANSI_RESET << "Invalid input. Please enter a valid " << typeid(returnDataMember1).name() << ": " << input1Color;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cout << terminalFormatingColorcodes::ANSI_RESET << std::endl;

            return std::make_pair(rData0, rData1);
        }

    }
}

#endif // TERMINALUI_H