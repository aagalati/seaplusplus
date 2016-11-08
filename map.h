//Map builder Program
//Uses the 2 concrete builder patterns to create a map object and read from it
//The character level portion is currently not fully implemented
//comp345 a2
#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

//template
template <typename T>
class matrix2D
{
public:
	using elem_type = T;
	using this_type = matrix2D<elem_type>;
	using size_type = std::size_t;
	using row_type = std::vector<elem_type>;

	// construct matrix RxC
	matrix2D(size_type row_count, size_type col_count)
	{
		this->set_col_count(col_count);
		this->set_row_count(row_count);
	}

	// default constructor 0x0
	matrix2D() : matrix2D(0, 0) {}

	// (const) reference to cell (bounds not checked for speed reasons)
	elem_type& cell(size_type row, size_type col) { return this->m_data[row][col]; }
	const elem_type& cell(size_type row, size_type col) const { return this->m_data[row][col]; }

	// get row (col) count value
	size_type get_row_count() const { return this->m_row_count; }
	size_type get_col_count() const { return this->m_col_count; }

	// set row count
	void set_row_count(size_type row_count)
	{
		this->m_row_count = row_count;
		this->m_data.resize(row_count, row_type(this->m_col_count));
	}

	// set col count (resize every row)
	void set_col_count(size_type col_count)
	{
		this->m_col_count = col_count;
		for (auto &v : this->m_data) { v.resize(col_count); }
	}

	// output to ostream
	friend std::ostream& operator << (std::ostream &os, const this_type &rhs)
	{
		for (std::size_t row = 0, row_e = rhs.get_row_count(); row != row_e; ++row) // each row
		{
			for (std::size_t col = 0, col_e = rhs.get_col_count(); col != col_e; ++col) // each col
			{
				os << rhs.cell(row, col); // each cell
			}

			os << '\n';
		}

		return os;
	}

private:
	std::vector<row_type> m_data; // data container - vector<vector>
	size_type m_row_count, m_col_count; // size values - col & row
};

// some entities & helper class
enum class entity
{
	Nothing,
	Wall,
	Door,
	Object
};

class entity_wrapper
{
public:
	using data_type = entity;
	using ext_type = char;

	// constructs wrapper from char value
	entity_wrapper(ext_type c)
	{
		switch (c)
		{
		case '#': { this->m_data = entity::Wall; } break;
		case 'D': { this->m_data = entity::Door; } break;

		case 'O': {} // intended fall-through
		case '0': { this->m_data = entity::Object; } break;

		case ' ': {} // intended fall-through
		default: { this->m_data = entity::Nothing; } break; // unsupported entities silently default to nothing
		}
	}

	// default constructor (creates entity::Nothing)
	entity_wrapper() : entity_wrapper(' ') {}

	// get underlying entity object
	data_type get_data() const { return this->m_data; }

	// conversion operator to char
	operator ext_type () const
	{
		switch (this->m_data)
		{
		case data_type::Wall: { return '#'; } break;
		case data_type::Door: { return 'D'; } break;
		case data_type::Object: { return 'O'; } break;

		default: { return ' '; } break;
		}
	}

private:
	data_type m_data; // entity object
};

// map is similar to underlying data structure - matrix2D, except you can't change it's dimensions
class map
{
public:
	using elem_type = entity_wrapper;
	using data_type = matrix2D<elem_type>;
	using size_type = std::size_t;

	// create map from data_type (matrix)
	map(const data_type &data) : m_data(data) {}
	// default constructor uses 0x0 matrix
	map() {}

	// reference to cell (bounds not checked for speed reasons)
	elem_type& cell(size_type row, size_type col) { return this->m_data.cell(row, col); }
	// const reference to cell (bounds not checked for speed reasons)
	const elem_type& cell(size_type row, size_type col) const { return this->m_data.cell(row, col); }

	// get row count value
	size_type get_row_count() const { return this->m_data.get_row_count(); }
	// get col count value
	size_type get_col_count() const { return this->m_data.get_col_count(); }

	// check if empty - any of the dimensions is 0
	bool empty() const { return (this->get_row_count() == 0 || this->get_col_count() == 0); }

	// get underlying matrix
	const data_type& get_data() const { return this->m_data; }

	// output to ostream
	friend std::ostream& operator << (std::ostream &os, const map &rhs)
	{
		return os << rhs.m_data;
	}

private:
	data_type m_data; // matrix data
};

// base map builder
class map_builder
{
public:
	using map_type = map;
	using elem_type = map_type::elem_type;
	using size_type = map_type::size_type;

	// default constructor (does nothing)
	map_builder() {}
	// creates builder from existing map
	map_builder(const map_type &other) : m_data(other.get_data()) {}

	// set entity within cell (bounds not checked for speed reasons)
	void set_cell(size_type row, size_type col, elem_type entity) { this->m_data.cell(row, col) = entity; }

	// these two & set_cell are useful for manual manipulations
	void set_row_count(size_type row_count) { this->m_data.set_row_count(row_count); }
	void set_col_count(size_type col_count) { this->m_data.set_col_count(col_count); }

	// loads map from file
	void load_from_file(const std::string &file)
	{
		std::ifstream in(file);
		if (!in) { return; } // silently ignore bad files

		std::string row;
		size_type row_count = 0; // current row count
		while (std::getline(in, row)) // if read
		{
			if (row_count == 0) { this->m_data.set_col_count(row.size()); } // first line - set col count
			else if (this->m_data.get_col_count() != row.size())
			{
				throw std::runtime_error("Bad input line: " + std::to_string(row_count));
			} // other lines - check col count

			this->m_data.set_row_count(row_count + 1); // add 1 row

			for (size_type i = 0, e = row.size(); i != e; ++i) // set data
			{
				this->m_data.cell(row_count, i) = elem_type(row[i]);
			}

			++row_count;
		}
	}

	// returns new map object
	map_type get_object() const { return map_type(this->m_data); }

protected:
	map_type::data_type m_data;
};

// advanced builder - inherits map_builder & adds character level awareness functionality
class map_builder_advanced : public map_builder
{
public:
	using map_type = map_builder::map_type;
	using elem_type = map_builder::elem_type;
	using size_type = map_builder::size_type;

	using map_builder::map_builder; // inherit constructors

									// this function is used to adapt the map to character level (currently does nothing, except remembering last level)
	void adapt_to_character(int level)
	{
		this->m_cur_level = level; // remember it just in case

								   // implementation defined

		for (size_type row = 0, row_e = this->m_data.get_row_count(); row != row_e; ++row)
		{
			for (size_type col = 0, col_e = this->m_data.get_col_count(); col != col_e; ++col)
			{
				this->m_data.cell(row, col) = this->m_data.cell(row, col); // do something useful here
			}
		}
	}

protected:
	int m_cur_level = 0; // last char level
};