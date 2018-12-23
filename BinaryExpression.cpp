using namespace std;
#include "BinaryExpression.h"
double BinaryExpression::calculate() {
    if (getIsNumber() == 1) {
        return getNumber();
    }

}