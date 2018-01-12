#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

struct student
{
    int rollno;
    char name[25];
    student *next;
}*start, *newptr, *save, *ptr, *rear;

int count = 0;

int main()
{
    char choice;
    //Menu for program
    cout << "\nSelect an option (1-4): "
    cout << "\n*****MENU*****"
    cout << "\n1. Insert nodes in a Linked List";
    cout << "\n2. Delete nodes in a Linked List";
    cout << "\n3. Display nodes in a Linked List";
    cout << "\n4. Count the number of nodes in a Linked List";
    cout << "\n5. Exit"
    cin >> choice;
    
    //TODO : Add cases as functions
    switch(choice)
    {
        case 1:
            break;
        case 2:     Deletestudent();
            break;
        case 3:     Display(start);
            break;
        case 4:     count(start);
            break;
        case 5:
            exit(1);
    }
}

//Function 1: Insertion (from end) of a node to the Linked List

/*Theory
 The start pointer points to the beginning of the list, rear points to the last node.
 
 The function 'Create_New_Node()' takes one integer argument, allocates memory to create a new node and returns
 the pointer to the new node (return type: student*)
 
 The function 'Insert_End()' takes student* type pointer as an argument and inserts this node to the end of the list.
 */

student* Create_New_Node(int, char);
void Insert_End(student*);

start = rear = NULL;        //List empty in the beginning
int rno; char ch = 'y', char sname[25];
char* psname;

while (ch == 'y' || ch == 'Y')
{
    system("cls");
    cout << "\nEnter information for new node: "
    cin >> rno;
    cin.getline(sname, 25)
    psname = *sname;
    cout << "\nCreating new node. Press Enter to Continue ";
    system("pause");
    
    newptr = Create_New_Node(int, char);
    if (newptr == NULL)
    {
        cout << "\nNew node created successfully. Press Enter to Continue ";
        system("pause");
    }
    else
    {
        cout << "\nCannot create new node. Aborting..."
        system("pause");
        exit(1);
    }
    
    cout << "\nNow inserting node to the end of the list ";
    cout << "\nPress Enter to Continue ";
    system("pause");
    Insert_End(newptr);
    
    cout << "\nEnter 'Y' to create more nodes, 'N' to exit: ";
    cin >> ch;
}

student* Create_New_Node(int rno, char sname)
    {
        ptr = new student;
        ptr->rollno = rno;
        ptr->name[25] = sname;      //Doubt
        ptr->next = NULL;
        return ptr;
    }

void Insert_End(student* np)
    {
        if (start == NULL)
            start = rear = np;
        else
        {
            rear->next = np;
            rear = np;
        }
    }



//Function 2: Deletion from the beginning of the Linked List
/*Theory
 Function Delnode() deletes the node from the beginning of the list being pointed to by start pointer
*/
void Deletestudent();
    char opt;
    system("cls");
    do
    {
        cout << "\nThe Linked List is now: ";
        Display(start); system("pause");
        cout << "\nDo you want to delete the first node (y/n)? ";
        cin >> opt;
        if (opt == 'y' || opt == 'Y')
        {
            if (start == NULL)
                cout << "\nUnderflow!";
            else
            {
                ptr = start;
                start = start->next;
                delete ptr;
            }
        }
    }while(opt == 'y' || opt == 'Y');
    

//Function 3: Displaying nodes in a Linked List
    
void Display(student* stu)
    {
        while(stu != NULL)
        {
            cout << stu->rollno << "->";
            cout << stu->name << "->";
            stu = stu->next;
        }
        cout << "!!!";
    }
 
 
 
//Function 4: Counting the number of nodes in the Linked List
void count(student* stu)
    {
        while (stu != NULL)
        {
            count++;
        }
        cout << "\nThe number of nodes in the Linked List is: " << count;
    }

