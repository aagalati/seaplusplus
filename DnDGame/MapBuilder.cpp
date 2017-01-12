// MapBuilder.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include "map.h"

int main(int argc, char *argv[])
{
	std::cout << "Enter file name: ";
	std::string file;
	std::getline(std::cin, file);

	try
	{
		map_builder builder;
		builder.load_from_file(file);
		auto map = builder.get_object();

		std::cout << "Read map:\n" << map << '\n';

		map_builder_advanced builder_adv(map);
		builder_adv.adapt_to_character(10);
		auto map_adv = builder_adv.get_object();

		std::cout << "\nAdapted map:\n" << map_adv << '\n';
	}
	catch (const std::exception &e) { std::cout << e.what(); }

	std::cin.get();

	return 0;
}
