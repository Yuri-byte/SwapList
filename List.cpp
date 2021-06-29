/*
 * List.cpp
 *
 *  Created on:
 *      Author:
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

  long Aposition;
  long Bposition;

  ListPointer currentA;
  ListPointer currentB;

  ListPointer auxA;
  ListPointer auxB;

  if(size() == 0 || size() == 1 || a == b){
    return false;
  }

  if(size() >= 2){
    if(search(a) == 0 && search(b) == 0){
      return false;
    }else{

      /* Pro caso de eles estarem no meio da lista e nao serem adjacentes */
      /* Ta funcionando*/

        Aposition = search(a);
        Bposition = search(b);

        setPosition(Aposition, currentA); 
        setPosition(Bposition, currentB);

        /* Verifica se A ou B não é o final da lista ou o inicio ou se são adjacentes */
        if((currentA->nextNode != NULL || currentB->nextNode != NULL) && 
          (currentA->nextNode != currentB || currentB->nextNode != currentA) &&
          (Aposition > 1 || Bposition > 1)){

          /* Caso A esteja antes de B */
          if(Aposition < Bposition){
            ListPointer afterA, beforeA, afterB, beforeB;

            setPosition(Aposition-1, beforeA); 
            setPosition(Aposition+1, afterA); 

            setPosition(Bposition+1, afterB);
            setPosition(Bposition-1, beforeB);

            currentA->nextNode = currentB->nextNode;
            currentB->nextNode = afterA;
            beforeA->nextNode = beforeB->nextNode;
            beforeB->nextNode = currentA;
          }else{/* Caso B esteja antes de A */
            ListPointer beforeB, afterB, beforeA;

            setPosition(Aposition-1, beforeA); 

            setPosition(Bposition+1, afterB);
            setPosition(Bposition-1, beforeB);

            beforeB->nextNode = currentA;
            currentB->nextNode = currentA->nextNode;
            currentA->nextNode = afterB;
            beforeA->nextNode = currentB;
          }
         
        /* ****************************************************************** */
        }else if(5<6){/* Nao sao adjacentes e os dois estao nas pontas */

        }



    } 
  }
}
//---------------------------------------------------------------
