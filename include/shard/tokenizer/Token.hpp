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
#include "shard/String.hpp"
#include "shard/tokenizer/TokenType.hpp"

/* ************************************************************************* */

namespace shard::tokenizer {

/* ************************************************************************* */

/**
 * @brief      Lexical element.
 *
 * @details    It's used for storing lexical element from the source code which
 *             is a sequence of characters.
 */
class Token
{
public:
    // Ctors & Dtors

    /**
     * @brief      Default constructor.
     */
    Token() = default;

    /**
     * @brief      Constructs token.
     *
     * @param      type      The token type.
     * @param      value     The token value.
     * @param      location  The source location.
     */
    explicit Token(TokenType type, String value, SourceLocation location)
        : m_type(type)
        , m_value(std::move(value))
        , m_location(location)
    {
        // Nothing to do
    }

public:
    // Accessors & Mutators

    /**
     * @brief      Returns token type.
     *
     * @return     The type.
     */
    TokenType type() const noexcept
    {
        return m_type;
    }

    /**
     * @brief      Returns token value.
     *
     * @return     The value.
     */
    const String& value() const noexcept
    {
        return m_value;
    }

    /**
     * @brief      Returns token starting location.
     *
     * @return     The source location.
     */
    SourceLocation location() const noexcept
    {
        return m_location;
    }

private:
    // Data Members

    /// Token type.
    TokenType m_type = TokenType::Unknown;

    /// Token value.
    String m_value;

    // Token start location in the source.
    SourceLocation m_location;
};

/* ************************************************************************* */

} // namespace shard::tokenizer

/* ************************************************************************* */
