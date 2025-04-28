/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <maalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:07:43 by maalmeid          #+#    #+#             */
/*   Updated: 2025/04/28 10:07:44 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string toUpper(char* arg)
{
    std::string result;

    result = arg;
    for (size_t i = 0; i < result.size(); i++)
    {
        result[i] = std::toupper(static_cast<unsigned char>(result[i]));
    }
    return result;
}

int main(int argc, char *argv[])
{
    int j;
    std::string text;

    j = 1;
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (j < argc)
        {
            text = toUpper(argv[j]);
            std::cout << text;
            j++;
        }
        std::cout << std::endl;
    }
    return 0;
}