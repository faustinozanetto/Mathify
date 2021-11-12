#pragma once
#include "TerminalColor.h"
#include <string>
#define LOG_DEBUG(Format, ...) Log::debug(std::string("[%s:%d] ") + Format, __FUNCTION__, __LINE__, __VA_ARGS__);

namespace Mathify::Log
{
    namespace Mathify::Log::Color
    {
        const TerminalColorPair DEBUG   { TerminalColor::GREEN  , TerminalColor::BLACK};
        const TerminalColorPair INFO    { TerminalColor::CYAN   , TerminalColor::BLACK};
        const TerminalColorPair WARNING { TerminalColor::YELLOW , TerminalColor::BLACK};
        const TerminalColorPair ERROR   { TerminalColor::RED    , TerminalColor::BLACK};
        const TerminalColorPair FATAL   { TerminalColor::BLACK  , TerminalColor::RED  };
        const TerminalColorPair NORMAL  { TerminalColor::WHITE  , TerminalColor::BLACK};
        const TerminalColorPair SUBJECT { TerminalColor::MAGENTA, TerminalColor::BLACK};
    }

    enum class Level : char {
        INFO    = 0,
        WARNING = 1,
        ERROR   = 2,
        FATAL   = 3,
        NONE    = 4
    };

    class Subject
    {
    public:
        Subject(const std::string& title);
        ~Subject();

        Subject(Subject&& other) = delete;
        Subject(const Subject&) = delete;
        Subject& operator=(Subject&& other) = delete;
        Subject& operator=(const Subject&) = delete;
    };

    void init(const char* logFile);
    void stop();
    void setDelimiter(std::string delimiter);

    void debug(std::string format, ...);
    void info(std::string format, ...);
    void warn(std::string format, ...);
    void error(std::string format, ...);
    void fatal(std::string format, ...);
    void print(std::string format, ...);
    void print(TerminalColorPair color, std::string format, ...);
    void setLogLevel(Log::Level logLevel);
    Level getLogLevel();
}
