#include "list.h"
#include "dutil.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	ElementType Element;
	Position Next;
};

List MakeEmpty(List L)
{
	//
}

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;
}

void Delete(ElementType X, List L)
{
	Position P = FindPrevious(X, L);

	if (P != NULL) 
	{
		Position tmp = P->Next;
		P->Next = tmp->Next;
		free(tmp);
	}
}

Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}

void Insert(ElementType X, List L, Position P)
{
	Position Tmp;
	Tmp = (Position) checked_malloc(sizeof(struct Node));
	Tmp->Element = X;
	Tmp->Next = P->Next;
	P->Next = Tmp;
}