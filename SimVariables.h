#ifndef SIM_VARIABLES_H
#define SIM_VARIABLES_H

#include <string>
#include <list>

using namespace std;

/**
 * Main class of the simulator variables addresses.
 */
class SimVariables {
private:
    list<string> lst;
public:
    /**
     * Creates the list.
     */
    void create();
    /**
     * Returns the list.
     * @return the list.
     */
    list<string> get() {
        return lst;
    }
};


#endif //SIM_VARIABLES_H
