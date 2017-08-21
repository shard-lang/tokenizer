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
#include "shard/interpreter/Context.hpp"

// Shard
#include "shard/utility.hpp"
#include "shard/interpreter/Exception.hpp"
#include "shard/interpreter/Function.hpp"

/* ************************************************************************* */

namespace shard {
inline namespace v1 {
namespace interpreter {

/* ************************************************************************* */

Context::Context()
{
    auto scope = push();

    // TODO: remove
    auto print = scope->addSymbol("print", SymbolKind::Function);
    SHARD_ASSERT(print);
    print->setValue(Function("print"));
}

/* ************************************************************************* */

ViewPtr<Scope> Context::push(ViewPtr<Scope> parent)
{
    if (parent == nullptr)
        parent = getCurrent();

    // Create new scope
    m_scopes.emplace_back(makeUnique<Scope>(parent));

    // Get last created
    m_current = makeView(m_scopes.back());

    return m_current;
}

/* ************************************************************************* */

void Context::pop()
{
    if (m_scopes.size() <= 1)
        throw Exception("Trying to remove last scope");

    // Remove scope
    m_scopes.pop_back();

    // Set new parent
    m_current = makeView(m_scopes.back());
}

/* ************************************************************************* */

ViewPtr<Symbol> Context::findSymbol(StringView name) noexcept
{
    SHARD_ASSERT(m_current);
    return m_current->findSymbol(name);
}

/* ************************************************************************* */

ViewPtr<Symbol> Context::addSymbol(String name, SymbolKind kind)
{
    SHARD_ASSERT(m_current);
    return m_current->addSymbol(moveValue(name), kind);
}

/* ************************************************************************* */

}
}
}

/* ************************************************************************* */
