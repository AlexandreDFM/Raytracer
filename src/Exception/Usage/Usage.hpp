/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Usage.hpp
*/

#ifndef USAGE_HPP_
    #define USAGE_HPP_

    #include <string>
    #include <iostream>
    #include <filesystem>

class Usage {
    public:
        class Error : public std::exception {
            public:
                //////////////////////// ErrorTypes ////////////////////////
                enum ErrorType {
                    PATH,
                    NOT_ENOUGH_ARGS,
                    TOO_MANY_ARGS,
                    UNKNOWN
                };
                explicit Error(ErrorType type = UNKNOWN) noexcept;
                ~Error() noexcept override = default;
                [[nodiscard]] const char *what() const noexcept override;
            private:
                ErrorType _errorType;
        };
        static void CheckUsage(int ac, char **av);
        static void DisplayUsage();
};

#endif /* !USAGE_HPP_ */
