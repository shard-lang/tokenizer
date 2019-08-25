/* ************************************************************************* */
/* This file is part of Shard.                                               */
/*                                                                           */
/* Shard is free software: you can redistribute it and/or modify             */
/* it under the terms of the GNU Affero General Public License as            */
/* published by the Free Software Foundation.                                */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              */
/* GNU Affero General Public License for more details.                       */
/*                                                                           */
/* You should have received a copy of the GNU Affero General Public License  */
/* along with this program. If not, see <http://www.gnu.org/licenses/>.      */
/* ************************************************************************* */

// Declaration
#include "shard/ast/Source.hpp"

// C++
#include <ostream>

// Shard
#include "shard/ast/DumpContext.hpp"
#include "shard/ast/AnalysisContext.hpp"

/* ************************************************************************* */

namespace shard::ast {

/* ************************************************************************* */

void Source::analyse()
{
    AnalysisContext context;

    // Foreach all statements
    for (const auto& stmt : m_statements)
        stmt->analyse(context);
}

/* ************************************************************************* */

void Source::dump(std::ostream& os) const
{
    os << "Source\n";

    DumpContext context(os);

    // Foreach all statements
    for (const auto& stmt : m_statements)
        stmt->dump(context);
}

/* ************************************************************************* */

} // namespace shard::ast

/* ************************************************************************* */
