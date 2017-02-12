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

#pragma once

/* ************************************************************************* */

// Shard
#include "shard/SourceLocation.hpp"
#include "shard/SourceRange.hpp"

/* ************************************************************************* */

namespace shard {
inline namespace v1 {
namespace ast {


/* ************************************************************************* */

/**
 * @brief      Base class for all AST nodes.
 */
class Node
{

// Public Accessors & Mutators
public:


    /**
     * @brief      Returns source range.
     *
     * @return     The source range.
     */
    const SourceRange& getSourceRange() const noexcept
    {
        return m_range;
    }


    /**
     * @brief      Returns source range start.
     *
     * @return     The source start.
     */
    const SourceLocation& getSourceStart() const noexcept
    {
        return getSourceRange().getStart();
    }


    /**
     * @brief      Returns source range end.
     *
     * @return     The source end.
     */
    const SourceLocation& getSourceEnd() const noexcept
    {
        return getSourceRange().getEnd();
    }


// Protected Ctors & Dtors
protected:


    /**
     * @brief      Constructor.
     *
     * @param      range  Source range.
     */
    Node(SourceRange range) noexcept;


    /**
     * @brief      Destructor.
     */
    ~Node() = default;


// Private Data Members
private:

    /// Source range.
    SourceRange m_range;

};

/* ************************************************************************* */

}
}
}

/* ************************************************************************* */