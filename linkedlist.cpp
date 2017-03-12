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
   void displayMenu();
   ~NodeType(){};
};
NodeType:: NodeType(int data)
{
	info = data;
	nextPtr = 0;
}
void NodeType :: printList(NodeType * head)
{
	if(head !=NULL)
	{
		cout << "This is the list:\n";
		while(head != NULL)
		{
			cout << head->info;
			cout << endl;
			head = head->nextPtr;
		}
	}
	else
	{
		cout << "List is empty\n";
	}
}
void NodeType :: Find(NodeType * head, int value)
{
	bool found = false;
	while (head != NULL)
	{
		head->info;
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
void NodeType :: deletekey(NodeType *& head, int value)
{
	if(!head)
	{
		cout << "List is empty\n";
		return;
	}
	if(head->info == value)
	{
		currentPtr = head;
		head = head->nextPtr;
		delete currentPtr;
	}
	else
	{
		currentPtr = head;
		while((currentPtr!=NULL) && (currentPtr->info != value))
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if(currentPtr != NULL)
		{
			previousPtr->nextPtr = currentPtr->nextPtr;
			delete currentPtr;
			cout << value << " deleted\n";
		}
		else
		{
			cout << value << " not in list\n";
		}
	}
}
void NodeType :: insert(NodeType *& head, int value)
{
	currentPtr = new NodeType;
	currentPtr->info = value;
	currentPtr->nextPtr = head;
	head = currentPtr;
}
void NodeType :: Delete(NodeType *& head)
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
void NodeType :: displayMenu()
{
	cout << "------------------------------\n";
	cout << "(A)dd to list\n";
	cout << "(P)rint the list\n";
	cout << "(D)elete the front of the list\n";
	cout << "(F)ind\n";
	cout << "(K)Delete a specific key\n";
	cout << "(Q)uit\n";
	cout << "------------------------------\n";
	cout << "Select menu option(A/P/D/F/K/Q): ";
}
int main()
{
	NodeType * head;
	NodeType alpha;
	int value;
	char MenuOption;
	head = NULL;

	alpha.displayMenu();
	cin >> MenuOption;
	while(MenuOption != 'q' && MenuOption != 'Q')
	{
		switch (MenuOption)
		{
		case 'a':case 'A':
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
		case 'f':case'F':
			{
				cout << "Find value: ";
				cin >> value;
				alpha.Find(head,value);
				alpha.displayMenu();
				cin >> MenuOption;
			}
			break;
		case 'k':case'K':
			{
				cout << "Delete value: ";
				cin >> value;
				alpha.deletekey(head, value);
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
