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
#include "shard/ast/expr/FunctionCallExpr.hpp"

// Shard
#include "shard/utility.hpp"
#include "shard/Assert.hpp"

/* ************************************************************************* */

namespace shard {
inline namespace v1 {
namespace ast {

/* ************************************************************************* */

FunctionCallExpr::FunctionCallExpr(UniquePtr<Expr> expr, PtrDynamicArray<Expr> args, SourceRange range)
    : Expr(Kind, range)
    , m_expr(moveValue(expr))
    , m_arguments(moveValue(args))
{
    SHARD_ASSERT(m_expr);
}

/* ************************************************************************* */

FunctionCallExpr::~FunctionCallExpr() = default;

/* ************************************************************************* */

void FunctionCallExpr::setExpr(UniquePtr<Expr> expr)
{
    SHARD_ASSERT(expr);
    m_expr = moveValue(expr);
}

/* ************************************************************************* */

void FunctionCallExpr::setArguments(PtrDynamicArray<Expr> args)
{
    m_arguments = moveValue(args);
}

/* ************************************************************************* */

UniquePtr<FunctionCallExpr> FunctionCallExpr::make(UniquePtr<Expr> expr, PtrDynamicArray<Expr> args, SourceRange range)
{
    return makeUnique<FunctionCallExpr>(moveValue(expr), moveValue(args), moveValue(range));
}

/* ************************************************************************* */

}
}
}

/* ************************************************************************* */