#pragma once
#include <vector>
#include "operatorType.h"
#include "expr.h"
#include "exprItem.h"

namespace hdlConvertor {
namespace hdlObjects {

class Operator: public ExprItem {
private:
	Operator();
public:
	OperatorType op;
	std::vector<Expr*> operands;
	Operator(const Operator & o);
	Operator(Expr* op0, OperatorType operatorType, Expr* op1);

	static Operator * call(Expr* fn, const std::vector<Expr*> & operands);
	static Operator * slice(Expr* fn, const std::vector<Expr*> & operands);
	static Operator * ternary(Expr* cond, Expr* ifTrue, Expr* ifFalse);
	ExprItem * clone() const;
	~Operator();
};

}
}