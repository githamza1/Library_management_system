#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList;
template <class T>
class AVL;
class Books;
class BookRef;
class Library;
class Helper;

class Helper
{
public:
	static int Str_Length(const char* str)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			++i;
		}
		return i;
	}
	static void Str_Copy(char*& dest, const char*& source)
	{
		int length = Str_Length(source);
		dest = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			dest[i] = source[i];
		}
		dest[length] = '\0';
	}
	static void Str_Copy(char*& dest, char* const source)
	{
		int length = Str_Length(source);
		dest = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			dest[i] = source[i];
		}
		dest[length] = '\0';
	}
	static int Compare_String(char* s1, char* s2)
	{
		int length = Helper::Str_Length(s1);
		for (int i = 0; i < length; i++)
		{
			if (s1[i] != s2[i])
			{
				return 0;
			}
		}
		return 1;
	}
	static int Compare_String(char* s1, const char* s2)
	{
		int length = Helper::Str_Length(s1);
		for (int i = 0; i < length; i++)
		{
			if (s1[i] != s2[i])
			{
				return 0;
			}
		}
		return 1;
	}
	static void ClearScreen()
	{
		system("cls");
	}
	
};

template <class T>
class DoublyLinkedList
{
private:
	class Node
	{
	public:
		Node* next;
		Node* prev;
		T data;

		Node()
		{
			prev = next = NULL;
		}
	};
private:
	class Node;
	Node* head;
	Node* tail;
public:
	class Iterator
	{
		friend class DoublyLinkedList<T>;
	private:
		Node* curr;
	public:
		Iterator(Node* c = 0)
		{
			curr = c;
		}
		bool operator!=(const Iterator& itr)
		{
			if (this->curr != itr.curr)
			{
				return true;
			}
			return false;
		}
		T& operator*()
		{
			return curr->data;
		}
		void newline()
		{
			cout << "  " << endl;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			curr = curr->next;
			return old;
		}
		void getdata()
		{
			return data;
		}
		void Iteratorend()
		{
			cout << endl;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			curr = curr->prev;
			return old;
		}
	};
public:

	DoublyLinkedList()
	{
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = 0;
	}
	void InsertAtStart(T const value)
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = head->next;
		temp->prev = head;
		head->next->prev = temp;
		head->next = temp;
	}
	void Print()
	{
		if (head->next != nullptr)
		{
			Node* ptr = head->next;
			while (ptr != tail)
			{
				cout << ptr->data << ' ';
				ptr = ptr->next;
			}
			cout << '\n';
		}
		else
		{
			cout << "Empty List\n";
		}
	}
	void DeleteAtStart()
	{
		Node* temp = head->next;
		head->next = temp->next;
		temp->next->prev = head;
		delete temp;
	}
	void DeleteAtEnd()
	{
		if (head->next != tail)
		{
			Node* temp = tail->prev;
			temp->prev->next = tail;
			tail->prev = temp->prev;
			delete temp;
		}
	}
	Iterator InsertBefore(Iterator position, const T& value)
	{
		Node* temp = new Node;
		temp->data = value;
		Node* t = position.curr;
		temp->next = t;
		temp->prev = t->prev;
		temp->prev->next = temp;
		t->prev = temp;
		return position;
	}
	void InsertAtEnd(T const value)
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = tail;
		temp->prev = tail->prev;
		tail->prev->next = temp;
		tail->prev = temp;
	}
	Iterator InsertAfter(Iterator position, const T& value)
	{
		Node* temp = new Node;
		temp->data = value;
		Node* t = position.curr;
		temp->prev = t;
		temp->next = t->next;
		t->next->prev = temp;
		t->next = temp;
		return position;
	}
	//    void insertsorted(type const val) //---insert sorted---
//    {
//        node* temp;
//        for (temp = head; temp != 0; temp = temp->next)
//        {
//            if (val < temp->data && temp == head)
//            {
//                insertAtStart(val);
//                break;
//            }
//            else if (val < temp->data)
//            {
//                node* temp2 = new node(val, temp->prev, temp);
//                temp2->prev->next = temp2;
//                break;
//            }
//            else if (temp == tail && val > temp->data)
//            {
//                insertAtEnd(val);
//            }
//        }
//    }
	Iterator erase(Iterator position)
	{
		Node* temp = position.curr;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		Iterator it(temp->next);
		delete temp;
		return it;
	}
	Iterator Begin()
	{
		Iterator it;
		it.curr = head->next;
		return it;
	}
	void iterate()
	{
		cout << "Recursion done here " << endl;
	}
	Iterator End()
	{
		Iterator it(tail);
		return tail;
	}
	void newline()
	{
		cout << "  " << endl;
	}
	void Insert_Sorted(const T d)
	{
		auto it = End();
		it--;
		if (d > *(it))
		{
			InsertAtEnd(d);
		}
		else if (d < *(Begin()))
		{
			InsertAtStart(d);
		}
		else
		{
			Node* curr = head->next;
			for (auto iter = Begin(); iter != End(); iter++)
			{
				if ((curr->data < d) && (curr->next->data > d))
				{
					InsertAfter(iter, d);
					break;
				}
				else
					curr = curr->next;
			}
		}
	}
	void deletefromtail() //---Delete from tail---
	{
		if (head != nullptr)
		{
		            if (head == tail)
		            {
		                delete head;
		                head = tail = 0;
		            }
		            else {
		                tail = tail->prev;
		                delete tail->next;
		                tail->next = 0;
		            }
		        }
		    }
	Iterator Search(T d)
	{
		for (Iterator it = Begin(); it != End(); it++)
		{
			if (*it == d)
			{
				return it;
			}
		}
		return 0;
	}

};

template <class T>
class AVL
{
	class ANode
	{
	public:
		T data;
		ANode* left;
		ANode* right;
		int height;
		ANode()
		{
			left = right = 0;
		}
		ANode(T d, ANode* l, ANode* r, int h)
		{
			data = d;
			left = l;
			right = r;
			height = h;
		}
	};

	ANode* root;
public:
	AVL()
	{
		root = 0;
	}
	int getHeight(ANode* r)
	{
		if (!r)
		{
			return -1;
		}
		return r->height;
	}
	//    void Postorder(Node* t)
//    {
//        if (t == NULL)
//            return;
//        Postorder(t->left);
//        Postorder(t->right);
//        cout << t->ISSN << " ";
//    }
	int max(int a, int b)
	{
		if (a > b)
			return a;
		return b;
	}
	int balanceFactor(ANode* r)
	{
		return getHeight(r->left) - getHeight(r->right);
	}
	int calculateheight()
	{
		return getHeight();
	}
	void rotateLeft(ANode*& x)
	{
		ANode* y = x->right;
		x->right = y->left;
		y->left = x;
		x->height = 1 + max(getHeight(x->left), getHeight(x->right));
		y->height = 1 + max(x->height, getHeight(y->right));
		x = y;
	}
	void newline()
	{
		cout << "  " << endl;
	}
	void doubleRotateLeft(ANode*& x)
	{
		rotateRight(x->right);
		rotateLeft(x);
	}
	void rotateRight(ANode*& x)
	{
		ANode* y = x->left;
		x->left = y->right;
		y->right = x;
		x->height = 1 + max(getHeight(x->left), getHeight(x->right));
		y->height = 1 + max(x->height, getHeight(y->right));
		x = y;
	}
	//    void Postorder(Node* t)
//    {
//        if (t == NULL)
//            return;
//        Postorder(t->left);
//        Postorder(t->right);
//        cout << t->ISSN << " ";
//    }
	void getdata()
	{
		return data;
	}
	void qnewline()
	{
		cout << "  " << endl;
	}
	void doubleRotateRight(ANode*& x)
	{
		rotateLeft(x->left);
		rotateRight(x);
	}
	bool Search(T val)
	{
		return Search(val, root);
	}
	void Insert(T d)
	{
		Insert(root, d);
	}
	void newbook()
	{
		cout << "The new ROOT added int the record !  " << endl;
	}
	T findMin()
	{
		return findMin(root);
	}
	void InOrder_Print()
	{
		InOrder_Print(root);
	}
	void newnodeinavl()
	{
		cout << " Node" << endl;
	}
	auto Search(int val)
	{
		return Search(val, root);
	}
	void tnewline()
	{
		cout << "  " << endl;
	}
	Books& searchBook(int issn)
	{
		return searchBook(issn, root);
	}
private:
	Books& searchBook(int val, ANode* r)
	{
		if (r)
		{
			if (r->data.Get_ISSN() == val)
			{
				return *(r->data.Get_Node_In_List());
			}

			else if (r->data.Get_ISSN() > val)
			{
				return searchBook(val, r->left);
			}

			else if (r->data.Get_ISSN() < val)
			{
				return searchBook(val, r->right);
			}

		}
	}
	void InOrder_Print(ANode* r)
	{
		if (r)
		{
			InOrder_Print(r->left);
			cout << r->data << ' ';
			InOrder_Print(r->right);
		}
	}

	//    int GetBalance(Node* t)
	//    {
	//        if (t == NULL)
	//            return 0;
	//        else
	//            return Height(t->left) - Height(t->right);
	//    }
	void new1book()
	{
		cout << "The new book added int the record !  " << endl;
	}
	auto Search(int val, ANode* r)
	{
		if (r)
		{
			if (r->data.Get_ISSN() == val)
				return r->data.Get_Node_In_List();
			else if (r->data.Get_ISSN() > val)
				return Search(val, r->left);
			else if (r->data.Get_ISSN() < val)
				return Search(val, r->right);
		}
	}
	T findMin(ANode* r)
	{
		static int min = r->data;
		if (r->left)
		{
			min = findMin(r->left);
		}
		return min;
	}
	//    void swap(int n1) //---swap nodes---
//    {
//        node* temp = head->next;
//        node* curr = tail->prev;
//        int t;
//        for (int i = 0; i <= n1; i++)
//        {
//            if (i == n1)
//            {
//                t = temp->data;
//                temp->data = curr->data;
//                curr->data = t;
//            }
//            temp = temp->next;
//            curr = curr->prev;
//        }
//    }
	auto Search(T val, ANode* r)
	{
		if (r)
		{
			if (r->data == val)
				return r;
			else if (r->data > val)
				return Search(val, r->left);
			else if (r->data < val)
				return Search(val, r->right);
		}
		return false;
	}
	//Node* findMin(Node* t)
		//    {
		//        if (t == NULL)
		//            return NULL;
		//        else if (t->left == NULL)
		//            return t;
		//        else
		//            return findMin(t->left);
		//    }
	void Insert(ANode*& r, T d)
	{
		if (!r)
		{
			r = new ANode(d, 0, 0, 0);
		}
		else {
			if (d < r->data)
			{
				Insert(r->left, d);
				if (balanceFactor(r) == 2 || balanceFactor(r) == -2)
				{
					if (d < r->left->data)
					{
						rotateRight(r);
					}
					else {
						doubleRotateRight(r);
					}
				}
			}
			else if (d > r->data)
			{
				Insert(r->right, d);
				if (balanceFactor(r) == 2 || balanceFactor(r) == -2)
				{
					if (d > r->right->data)
					{
						rotateLeft(r);
					}
					else
					{
						doubleRotateLeft(r);
					}
				}
			}
			r->height = 1 + max(getHeight(r->left), getHeight(r->right));
		}
	}

};

class Reference_Book
{
	int ISSN;
	DoublyLinkedList<Books>::Iterator Node_In_List;
public:
	Reference_Book(int i, DoublyLinkedList<Books>::Iterator it)
	{
		ISSN = i;
		Node_In_List = it;
	}
	Reference_Book()
	{
		Node_In_List = NULL;
		ISSN = 0;

	}
	friend bool operator== (const Reference_Book& b1, const Reference_Book& b2)
	{
		return (b1.ISSN == b2.ISSN);
	}
	friend bool operator< (const Reference_Book& b1, const Reference_Book& b2)
	{
		return (b1.ISSN < b2.ISSN);
	}
	void newline()
	{
		cout << "  " << endl;
	}
	void displaybook()
	{
		cout << "  " << endl;
	}
	friend bool operator> (const Reference_Book& b1, const Reference_Book& b2)
	{
		return (b1.ISSN > b2.ISSN);
	}
	void newbook()
	{
		cout << "The new book added int the record !  " << endl;
	}
	int Get_ISSN()
	{
		return ISSN;
	}
	int issn()
	{
		return ISSN;
	}
	auto Get_Node_In_List()
	{
		return Node_In_List;
	}
	
};

class Books
{
	int ISSN;
	char* Title;
	char** Authors_;
	int Reference_Book_Count;
	int Issueed_Books_Count;

public:
	Books(int issn, char* t, char** authorL, int a, int x)
	{
		Issueed_Books_Count = x;
		ISSN = issn;
		Reference_Book_Count = a;

		Helper::Str_Copy(Title, t);
		int j = 0;
		while (authorL[j] != NULL)
			++j;
		Authors_ = new char* [j + 1];
		for (int i = 0; i < j; i++)
		{
			Helper::Str_Copy(Authors_[i], authorL[i]);
		}
		Authors_[j] = NULL;
	}
	Books()
	{
		ISSN = 0;
		Title = NULL;
		Authors_ = NULL;
		Reference_Book_Count = 0;
		Issueed_Books_Count = 0;
	}

	friend ostream& operator<< (ostream& out, const Books& book)
	{
		cout << "Name of the book : " << book.Title << endl << endl;
		cout << "ISSN of the book : " << book.ISSN << endl << endl;
		int i = 0;
		cout << "Authors of the book are:\n";
		while (book.Authors_[i] != NULL)
		{
			cout << "       " << i + 1 << ". " << book.Authors_[i] << endl;
			i++;
		}
		cout << "\nNumber of copies available as reference books : " << book.Reference_Book_Count << endl << endl;
		cout << "Number of copies available as issuable books : " << book.Issueed_Books_Count << endl << endl;
		cout << "\n--------------------------------------------------------------------------\n";
		return out;
	}
	friend bool operator== (const Books& book1, const Books& book2)
	{
		return (book2.ISSN == book1.ISSN);
	}
	friend bool operator< (const Books& book1, const Books& book2)
	{
		return (book1.ISSN < book2.ISSN);
	}
	int getissn()
	{
		return ISSN;
	}
	friend bool operator> (const Books& book1, const Books& book2)
	{
		return (book1.ISSN > book2.ISSN);
	}
	Books& operator= (const Books& book_)
	{
		this->ISSN = book_.ISSN;
		this->Issueed_Books_Count = book_.Issueed_Books_Count;
		this->Reference_Book_Count = book_.Reference_Book_Count;
		Helper::Str_Copy(this->Title, book_.Title);
		int count = 0;
		while (book_.Authors_[count] != NULL)
		{
			++count;
		}
		this->Authors_ = new char* [count + 1];
		for (int i = 0; i < count; i++)
		{
			Helper::Str_Copy(this->Authors_[i], book_.Authors_[i]);
		}
		Authors_[count] = NULL;

		return *this;
	}
	void Update_()
	{
		int New_Title;

		cout << "Press (1) to Change the Title of the Books \n";
		cout << "Press (2) to Change the Authors of the Books \n";
		cout << "Press (3) to Change the No of Copies of the Books \n";
		cout << "Press (4) to Change the No of Copies Available as Issueable Books \n";
		cin >> New_Title;

		if (New_Title == 1)
		{
			cout << "Enter new Title of the book : ";
			char* Name = new char[100];
			cin.ignore();
			cin.getline(Name, 100);
			Helper::Str_Copy(Title, Name);
		}

		if (New_Title == 2)
		{
			cout << "\nEnter number of new Authors_ of the book : ";
			int Author_Count;
			cin >> Author_Count;

			Authors_ = new char* [Author_Count + 1];
			for (int i = 0; i < Author_Count; i++)
			{
				cout << "\n Enter name of New Author : ";
				char* temp = new char[100];
				cin.ignore();
				cin.getline(temp, 100);
				Helper::Str_Copy(Authors_[i], temp);
			}
			Authors_[Author_Count] = NULL;
		}

		if (New_Title == 3)
		{
			cout << "\nEnter number of copies available as reference book : ";
			cin >> Reference_Book_Count;
		}

		if (New_Title == 4)
		{
			cout << "\nEnter number of copies available as issuable book : ";
			cin >> Issueed_Books_Count;
		}

	}
};

class Library
{
	AVL<Reference_Book> Reference_Books;
	DoublyLinkedList<Books> All_Books_List;

public:

	void Print_All_Books()
	{
		Helper::ClearScreen();
		All_Books_List.Print();
	}
	void Delete_Book()
	{
		Helper::ClearScreen();
		int val;
		cout << "Enter the ISSN number of the book you wish to delete : "; cin >> val;
		Helper::ClearScreen();
		Delete_(val);
	}
	void Execute()
	{
		bool Condition = 1;
		while (Condition)
		{
			cout << "LIBRARY DATABASE SYSTEM\n" << endl;
			int val;
			cout << "1. Create a Books Record\n";
			cout << "2. Review a Books Record\n";
			cout << "3. Update_ a Books Record\n";
			cout << "4. Delete_ a Books Record\n";
			cout << "5. List all Books Records\n";
			cout << "\nChoose desired operation : ";
			cout << "\nOr Press Any other key to exit : ";
			cin >> val;

			if (val == 1) { Create_Book(); }
			else if (val == 2) { Review_Book(); break; }
			else if (val == 3) { Update_Book(); break; }
			else if (val == 4) { Delete_Book(); break; }
			else if (val == 5) { Print_All_Books(); break; }
			else { Condition = 0; }

		}
	}
	void Add_Book(int issn, char* Title, char** Authors_, int refB, int issuableB)
	{
		Books* b = new Books{ issn, Title, Authors_, refB, issuableB };
		All_Books_List.Insert_Sorted(*b);
		auto Book__ = All_Books_List.Search(*b);
		Reference_Books.Insert(Reference_Book{ issn, Book__ });
	}
	void Create_Book()
	{
		system("cls");
		cout << "Enter title of the book : ";
		char* name = new char[100];
		cin.ignore();
		cin.getline(name, 100);

		cout << "\nEnter the ISSN number of the book : ";
		int issn;
		cin >> issn;

		cout << "\nEnter number of authors of the book : ";
		int num;
		cin >> num;

		char** Authors_ = new char* [num + 1];
		for (int i = 0; i < num; i++)
		{
			cout << "\nEnter name of author : ";
			char* temp = new char[100];
			if (i == 0)
				cin.ignore();
			cin.getline(temp, 100);
			Helper::Str_Copy(Authors_[i], temp);
		}
		Authors_[num] = NULL;

		cout << "\nEnter number of copies available as reference book : ";
		int n1;
		cin >> n1;

		cout << "\nEnter number of copies available as issuable book : ";
		int n2;
		cin >> n2;

		Add_Book(issn, name, Authors_, n1, n2);
	}
	void newbook()
	{
		cout << "The new book added int the record !  " << endl;
	}
	void Review_Book()
	{
		Helper::ClearScreen();
		int val;
		cout << "Enter the ISSN number of the book you wish to view the record of : "; cin >> val;
		Helper::ClearScreen();
		Review_(val);
	}
	void Update_Book()
	{
		Helper::ClearScreen();
		int val;
		cout << "Enter the ISSN of the book to modify records ";
		cin >> val;
		Update_(val);
	}
private:
	// Private Member Functions
	void Review_(int Issn_)
	{
		DoublyLinkedList<Books>::Iterator book_ = Reference_Books.Search(Issn_);
		cout << *(book_);

	}
	void Libraryrecord()
	{
		cout << "The new book added int the record !  " << endl;
	}
	void Update_(int Issn_)
	{
		Reference_Books.searchBook(Issn_).Update_();
	}
	void Delete_(int Issn_)
	{
		DoublyLinkedList<Books>::Iterator book = Reference_Books.Search(Issn_);
		All_Books_List.erase(book);
	}
};

int main()
{
	system("color 5F");
	Library Lib;
	Lib.Execute();
}