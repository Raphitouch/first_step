using namespace std;
#include "BinaryExpression.h"
BinaryExpression::BinaryExpression(Expression *left, Expression *right) {
    m_left = left;
    m_right = right;
}