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
#include "shard/ViewPtr.hpp"
#include "shard/UniquePtr.hpp"
#include "shard/DynamicArray.hpp"
#include "shard/interpreter/Scope.hpp"

/* ************************************************************************* */

namespace shard {
inline namespace v1 {
namespace interpreter {

/* ************************************************************************* */

/**
 * @brief      Shard interpreter context.
 */
class Context
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     */
    Context();


// Public Accessors & Mutators
public:


    /**
     * @brief      Returns the current scope.
     *
     * @return     The current scope.
     */
    ViewPtr<Scope> getCurrent() noexcept;


    /**
     * @brief      Returns the current scope.
     *
     * @return     The current scope.
     */
    ViewPtr<const Scope> getCurrent() const noexcept;


// Public Operations
public:


    /**
     * @brief      Push new scope.
     *
     * @param      parent  The optional parent scope. If is `nullptr` the
     *                     current scope is used as parent.
     *
     * @return     The new scope.
     */
    ViewPtr<Scope> push(ViewPtr<Scope> parent = nullptr);


    /**
     * @brief      Pop current scope.
     */
    void pop();


    /**
     * @brief      Find a symbol in current scope.
     *
     * @param      name  The symbol name.
     *
     * @return     Pointer to symbol or nullptr.
     */
    ViewPtr<Symbol> findSymbol(StringView name) noexcept;


    /**
     * @brief      Creates a symbol in the current scope.
     *
     * @param      name  The symbol name.
     * @param      kind  The symbol kind.
     *
     * @return     Pointer to symbol.
     *
     * @throws     Exception  If symbol already exists.
     */
    ViewPtr<Symbol> addSymbol(String name, SymbolKind kind);


// Private Data Members
private:

    /// Scope based symbol table.
    DynamicArray<UniquePtr<Scope>> m_scopes;

    /// Current scope.
    ViewPtr<Scope> m_current;
};

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */

inline ViewPtr<Scope> Context::getCurrent() noexcept
{
    return m_current;
}

/* ************************************************************************* */

inline ViewPtr<const Scope> Context::getCurrent() const noexcept
{
    return m_current;
}

/* ************************************************************************* */

}
}
}

/* ************************************************************************* */
