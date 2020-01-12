#ifndef VAR_COMMAND_H
#define VAR_COMMAND_H

#include "Command.h"
#include "Variable.h"
#include <map>
#include "VariablesMap.h"
#include "SimVariableIn.h"
#include "SimVariableOut.h"
#include "ExpressionFactory.h"
#include "ExpressionReader.h"
#include "ConnectCommand.h"

/**
 * Main class of var command.
 */
class VarCommand : public Command {
private:
    VariablesMap* vars;
    VariablesMap* simVars;
    ExpressionFactory* ef;
    ConnectCommand* cc;

public:
    /**
     * Constructor.
     * @param simV the simulator variables map.
     * @param variables the variables map.
     * @param expressionFactory the expression factory.
     * @param c the connect command.
     */
    VarCommand(VariablesMap* simV, VariablesMap* variables, ExpressionFactory* expressionFactory, ConnectCommand* c) {
        this->simVars = simV;
        this->vars = variables;
        this->ef = expressionFactory;
        this->cc = c;
    }
    virtual int execute(list<string>::iterator place, list<string>::iterator end);

};


#endif //VAR_COMMAND_H
