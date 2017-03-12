#include<iostream>
using namespace std;
class NodeType
{
	NodeType * nextPtr;
	int info;
	NodeType * currentPtr;
	NodeType * previousPtr;
public:
	NodeType( int = 0 );
   void printList(NodeType * head);
   void insert(NodeType *& head, int value);
   void Delete(NodeType *& head);
   void Find(NodeType * head, int value);
   void deletekey(NodeType *& head, int value);
   void deleteEnd(NodeType *& head);
   void addend(NodeType *& head, int value);
   void printreverse(NodeType * head);
   void displayMenu();
   void sum(NodeType * head, int total);
   void total(NodeType * head, int sum);
   ~NodeType(){};
};
NodeType:: NodeType(int data)
{
	info = data;
	nextPtr = 0;
}

//list print using recursion
void NodeType :: printList(NodeType * head)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		cout << head->info << endl;
		printList(head->nextPtr);
	}
}
void NodeType :: Find(NodeType * head, int value)
{
	bool found = false;
	while (head != NULL)
	{
		if (head->info == value)
		{
			found = true;
		}
		head = head->nextPtr;
	}
	if (found == true)
	{
		cout << value << " found\n";
	}
	else
	{
		cout << value << " not found in list\n";
	}
}

//delete a specific value recursively
void NodeType :: deletekey(NodeType *& head, int value)
{
	bool deleted = false;
	if(!head)
	{
		cout << "List is empty\n";
		return;
	}
	if(head->info == value)
	{
		currentPtr = head;
		head = head->nextPtr;
		currentPtr->nextPtr = 0;
		delete currentPtr;
		deleted = true;
	}
	else
	{
		deletekey(head->nextPtr,value);
	}
	if(deleted == true)
	{
		cout << value << " deleted\n";
	}
	else
	{
		cout << value << " not in list\n";
	}
}
void NodeType :: insert(NodeType *& head, int value)
{
	currentPtr = new NodeType;
	currentPtr->info = value;
	currentPtr->nextPtr = head;
	head = currentPtr;
}
void NodeType:: Delete(NodeType *& head)
{
	if(head != NULL)
	{
		currentPtr = head;
		head = head->nextPtr;
		currentPtr->nextPtr = 0;
		delete currentPtr;
	}
	else
	{
		cout << "List is empty\n";
	}

}

//delete at the end of the list using recursion
void NodeType :: deleteEnd(NodeType *& head)
{
	if(head->nextPtr == NULL)
	{
		currentPtr = head;
		head = previousPtr;
		head->nextPtr = NULL;
		delete currentPtr;
	}
	else
	{
		previousPtr = head;
		deleteEnd(head->nextPtr);
	}
}
void NodeType:: displayMenu()
{
	cout << "----------------------------------------\n";
	cout << "(A)dd to list\n";
	cout << "**(P)rint the list\n";
	cout << "(D)elete the front of the list\n";
	cout << "(F)ind\n";
	cout << "**(K)Delete a specific key\n";
	cout << "**(E)Add at the end of the list\n";
	cout << "**(R)Print the list in reverse\n";
	cout << "**(B)Delete at the end of the list\n";
	cout << "(Q)uit\n";
	cout << "\n** is a recursive function\n";
	cout << "----------------------------------------\n";
	cout << "Select menu option: ";
}

//a new value added recursively at end of list
void NodeType :: addend(NodeType *& head, int value)
{
	if(head == NULL)
	{
		head = new NodeType;
		head->info = value;
		head->nextPtr = NULL;
	}
	else
	{
		addend(head->nextPtr, value);
	}
}

//list printed in reverse through recursion
void NodeType :: printreverse(NodeType * head)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		printreverse(head->nextPtr);
		cout << head->info << endl;
	}
}
void NodeType :: sum(NodeType * head, int total)
{
	if(head == NULL)
	{
		cout << total << endl;
		return;
	}
	else
	{
		total += head->info;
		sum(head->nextPtr,total);
	}
}
void NodeType :: total( NodeType * head, int sum)
{
	while(head)
	{
		sum += head->info;
		head = head->nextPtr;
	}
	cout << sum <<endl;
}
int main()
{
	NodeType * head;
	NodeType alpha;
	int value;
	char MenuOption;
	head = NULL;
	int total = 0;

	alpha.displayMenu();
	cin >> MenuOption;
	while(MenuOption != 'q' && MenuOption != 'Q')
	{
		switch (MenuOption)
		{
		case 'a':case'A':
			{
				cout << "Value: ";
				cin >> value;
				alpha.insert(head, value);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 'p':case 'P':
			{
				cout << "this is the list:\n";
				alpha.printList(head);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 'd':case 'D':
			{
				alpha.Delete(head);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 'f':case 'F':
			{
				cout << "Find value: ";
				cin >> value;
				alpha.Find(head,value);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 'k':case 'K':
			{
				cout << "Delete value: ";
				cin >> value;
				alpha.deletekey(head, value);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 'e':case 'E':
			{
				cout << "Add value: ";
				cin >> value;
				alpha.addend(head, value);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 'r':case 'R':
			{
				cout << "The list in reverse:\n";
				alpha.printreverse(head);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 'b':case 'B':
			{
				alpha.deleteEnd(head);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 's':case 'S':
			{
				alpha.sum(head,total);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 't':case 'T':
			{
				alpha.total(head,total);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		default:
		{
			cout << "invalid input\n";
			alpha.displayMenu();
			cin >> MenuOption;
		}
		break;
		}
	}
	system("pause");
	return 0;
}
