#include "LinkedList.h"



LinkedList::LinkedList()
{
	Head = new Item;
	Head->next = nullptr;

	length = 0;

}


void LinkedList::insertItem(Item* newItem)
{

	if (!Head->next)
	{
		Head->next = newItem;
		length++;

		return;
	}

	//Cycles through until the end to set last item as new item.
	Item* pre = Head;
	Item* aft = Head;
	while (aft)
	{
		pre = aft;
		aft = pre->next;
	}
	pre->next = newItem;
	newItem->next = nullptr;

	length++;

}


bool LinkedList::removeItem(std::string Value)
{
	if (!Head->next)
	{
		return false;
	}
	Item* pre = Head;
	Item* aft = Head;
	//cycles through list looking for the specific item, if found, delete
	while (aft)
	{
		if (aft->Value == Value)
		{
			pre->next = aft->next;
			delete aft;
			length--;
			return true;
		}
		pre = aft;
		aft = pre->next;
	}
	return false;
}


Item* LinkedList::returnItem(std::string Value)
{
	Item* pre = Head;
	Item* aft = Head;
	while (aft)
	{
		pre = aft;

		if ((pre != Head) && (pre->Value == Value))
		{
			return pre;
		}
		aft = pre->next;
	}
	return nullptr;
}

int LinkedList::GetListLength()
{
	return length;
}


LinkedList::~LinkedList()
{
	Item* pre = Head;
	Item* aft = Head;

	while (aft)
	{
		pre = aft;

		aft = pre->next;
		if (aft)
		{
			delete pre;
		}
	}
}

void LinkedList::PrintList()
{
	Item* pre = Head;
	Item* aft = Head;

	std::cout << std::endl;

	while (aft)
	{
		pre = aft;

		if (pre != Head)
		{
			std::cout << pre->Value;

			if (pre->next)
			{
				std::cout << " - ";
			}
			else
			{
				std::cout << " ";
			}
		}
		aft = pre->next;
	}
	std::cout << std::endl;
}

