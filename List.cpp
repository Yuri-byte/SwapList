/*
 * List.cpp
 *
 *  Created on: 12/07/2021
 *  Author: Yuri Schwab 11273851
 */
#include "List.h"
//---------------------------------------------------------------
List::List()
{
  head = NULL;
  count = 0;
}
//---------------------------------------------------------------
List::~List()
{
  clear();
}
//---------------------------------------------------------------
bool List::empty()
{
  return (head == NULL);
}
//---------------------------------------------------------------
bool List::full()
{
   return false;
}
//---------------------------------------------------------------
void List::clear()
{ ListPointer q;

  while (head != NULL)
  {  q = head;
     head = head->nextNode;
     delete q;
  }
  count = 0;
}
//---------------------------------------------------------------
long List::size()
{
   return count;
}
//---------------------------------------------------------------
void List::insert(long p, ListEntry x)
{ ListPointer newNode, current;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  newNode = new ListNode;
  newNode->entry = x;
  if(p == 1)
  {  newNode->nextNode = head;
     head = newNode;
  }
  else
  {  setPosition(p-1,current);
     newNode->nextNode = current->nextNode;
     current->nextNode = newNode;
  }
  count++;
}
//---------------------------------------------------------------
void List::remove(long p, ListEntry &x)
{ ListPointer node, current;

  if (p < 1 || p > count)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  if(p == 1)
  {  node = head;
     head = node->nextNode;
  }
  else
  {  setPosition(p-1,current);
     node = current->nextNode;
     current->nextNode = node->nextNode;
  }
  x = node->entry;
  delete node;
  count = count - 1;
}
//---------------------------------------------------------------
void List::retrieve(long p, ListEntry &x)
{ ListPointer current;

  if (p < 1 || p > count)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  setPosition(p,current);
  x = current->entry;
}
//---------------------------------------------------------------
long List::search(ListEntry x)
{ long p=1;
  ListPointer q=head;

  while (q != NULL && q->entry != x)
  {  q = q->nextNode;
     p++;
  }
  return (q == NULL ? 0 : p);
}
//---------------------------------------------------------------
string List::toString()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q->entry << ",";
     q = q->nextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
string List::toStringAddr()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q << ",";
     q = q->nextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
void List::setPosition(long p, ListPointer &current)
{ long i;

  current = head;
  for(i=2; i<=p; i++)
      current = current->nextNode;
}
//---------------------------------------------------------------
long long List::getAddr(ListEntry x)
{ ListPointer current=NULL;
  long p = search(x);
  if(p != 0)
    setPosition(p, current);
  return (long long)current;
}
//---------------------------------------------------------------
bool List::swap(ListEntry a, ListEntry b)
{ // sua implementacao vem aqui
  // verifica se a lista é vazia ou tem 1 elemento ou se a == b
  if(size() == 1 || a == b || empty()){
    return false;
  }
  // criação das variáveis
  ListPointer currentA = head;
  ListPointer currentB = head;
  ListPointer beforeA = head;
  ListPointer beforeB = head;

  ListPointer aux;

  char flag = 'F';

  int n = 1;
  /* Percorre a lista e seleciona os valores utilizados na função*/
  while( n <= count ){
    if( currentA->entry != a){
      currentA = currentA->nextNode;
    }
    if( currentB->entry != b){
      currentB = currentB->nextNode;
    }
    if( beforeA->nextNode != currentA && beforeA != currentA){
      beforeA = beforeA->nextNode;
    }
    if( beforeB->nextNode != currentB && beforeB != currentB){
      beforeB = beforeB->nextNode;
    }
    n++;
  }

  if(currentA->entry != a) {
    cout << "Valor " << a << " nao encontrado na lista" << endl;
    return false;
  }
  if(currentB->entry != b) {
    cout << "Valor " << b << " nao encontrado na lista" << endl;
    return false;
  }

  /* Verifica se A é o primeiro nó da lista*/
  if(currentA == head){ 
    /* caso A seja o primeiro da lista*/
    flag = 'A';
  }else{ 
    /* caso não seja, o nó anterior a A passa a apontar para B*/
    beforeA->nextNode = currentB;
  }

  /* Verifica se B é o primeiro nó da lista*/
  if(currentB == head){
    /* caso B seja o primeiro da lista*/
    flag = 'B';
  }else{
    /* caso não seja, o nó anterior a B passa a apontar para A*/
    beforeB->nextNode = currentA;
  }

  switch (flag) 
  { 
    case 'A':
      head = currentB; // caso A seja o início da lista -> head se torna B
    break;

    case 'B':
      head = currentA; // caso B seja o início da lista -> head se torna A
    break;

    default:
    break;
  }

  flag = 'F';
  // verifica se algum dos nós é o último
  if(currentA->nextNode || currentB->nextNode){
    // se nenhum dos nós for o último
    // realiza a troca de ponteiros normalmente
    aux = currentA->nextNode;
    currentA->nextNode = currentB->nextNode;
    currentB->nextNode = aux; 
  }else if( !currentA->nextNode ){
    // se currentA for o último
    // aponta nextNode de A para o atual nextNode de B
    currentA->nextNode = currentB->nextNode;
    flag = 'A';  
  }else if( !currentB->nextNode ){
    // se currentB for o último
    // aponta nextNode de B para o atual nextNode de A
    currentB->nextNode = currentA->nextNode;
    flag = 'B';
  }
  // caso A seja o último nó
  // B aponta para null
  if(flag == 'A') currentB->nextNode = NULL;
  
  // caso B seja o último nó
  // A aponta para null
  if(flag == 'B') currentA->nextNode = NULL;

  return true;
}
