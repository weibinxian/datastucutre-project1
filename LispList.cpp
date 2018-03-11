/*
 * LispList.cpp
 *
 *  Created on: 2011-11-25
 *      Author: morin
 */

#include "LispList.h"


template LispList<int>::LispList();
template LispList<int>::~LispList();
template LispList<int> &LispList<int>::copy(Node *n);
template LispList<int>::LispList(const LispList &obj);
template LispList<int> &LispList<int>::operator=(const LispList &right);
template int LispList<int>::push(int x);
template bool LispList<int>::add(int x);
template int LispList<int>::remove();
template int LispList<int>::pop();
template int LispList<int>::size();
template void LispList<int>::print();
template int LispList<int>::first();
template LispList<int>LispList<int>::rest();
template LispList<int>LispList<int>::append(LispList &obj);
