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
#include "shard/utility.hpp"

/* ************************************************************************* */

namespace shard::tokenizer {

/* ************************************************************************* */

/**
 * @brief      Supported token types.
 */
enum class TokenType
{
    /// Unknown token type.
    Unknown,

    /// Identifier: [a-zA-Z_][a-zA-Z0-9_]*
    Identifier,

    /// String inside double quotes.
    StringLiteral,

    /// String inside single quotes.
    CharLiteral,

    /// Number: [0-9]+
    NumberLiteral,

    /// Comment.
    Comment,

    /// Nonprintable character.
    WhiteSpace,

    /// End of line/new line character.
    EndOfLine,

    // Other sequence of printable characters.
    Other,
};

/* ************************************************************************* */

} // namespace shard::tokenizer

/* ************************************************************************* */
