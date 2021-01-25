/**
 * @file FluidEvent.h++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FluidEventFile
#define FluidEventFile

#include "../Abstraction/FluidEngineMember.h++"

#include <functional>
#include <map>

namespace FluidEngine
{
    
    namespace Events
    {
        template<typename ... EventArgumentTypes>
        class FluidEvent : public Abstraction::FluidEngineMember
        {
        private:
            std::map<
                std::ptrdiff_t, 
                Abstraction::Shell<
                    std::function<void (EventArgumentTypes ...) noexcept>
                >
            > functionsSubscribed;

        public:
            FluidEvent(const std::wstring& = L"Unnamed Event") noexcept;

            Abstraction::Acknowledgement Find
            (
                const std::function<void (EventArgumentTypes ...) noexcept>&
            ) const noexcept;

            Abstraction::Acknowledgement Find
            (
                const std::function<void (EventArgumentTypes ...) noexcept>&
            ) noexcept;

            Abstraction::Acknowledgement Hook
            (
                const std::function<void (EventArgumentTypes ...) noexcept>&
            ) noexcept;

            Abstraction::Acknowledgement Free
            (
                const std::function<void (EventArgumentTypes ...) noexcept>&
            ) noexcept;

            void Wake(EventArgumentTypes ...) noexcept;
        };
    } // namespace Events
    
} // namespace FluidEngine


#endif