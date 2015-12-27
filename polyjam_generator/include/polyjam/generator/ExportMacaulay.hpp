/*************************************************************************
 *                                                                       *
 * polyjam, a polynomial solver generator for C++                        *
 * Copyright (C) 2015 Laurent Kneip, The Australian National University  *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                       *
 *************************************************************************/

#ifndef POLYJAM_GENERATOR_EXPORTMACAULAY_HPP_
#define POLYJAM_GENERATOR_EXPORTMACAULAY_HPP_

#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include <polyjam/core/Poly.hpp>

/**
 * \brief The namespace of this library.
 */
namespace polyjam
{

namespace generator
{

/**
 * The class exports and creates Macaulay compatible files. It allows us
 * to use Macaulay for computing Groebner bases.
 */
class ExportMacaulay
{
public:
  ExportMacaulay();
  virtual ~ExportMacaulay();
  
  // Make sure the dominant index is set correctly before writing these polynomials
  void addPoly( const core::Poly & poly );
  void write( const std::string & fileName );

private:  
  size_t _numberVariables;
  size_t _numberEquations;
  unsigned int _characteristic;
  
  std::stringstream _equations;
  std::stringstream _set;
};

}
}

#endif /* POLYJAM_GENERATOR_EXPROTMACAULAY_HPP_ */
