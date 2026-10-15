#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char song[50];
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *current = NULL;

void addSong()
{
    Node *newNode = new Node;

    cout << "\nEnter Song Name: ";
    gets(newNode->song);

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
	head = newNode;
	current = newNode;
    }
    else
    {
	Node *temp = head;

	while (temp->next != NULL)
	{
	    temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;
    }

    cout << "\nSong Added Successfully!";
}

void displayPlaylist()
{
    Node *temp = head;
    int count = 1;

    if (head == NULL)
    {
	cout << "\nPlaylist Is Empty!";
	return;
    }

    cout << "\n\n===== MUSIC PLAYLIST =====\n";

    while (temp != NULL)
    {
	cout << count << ". " << temp->song << "\n";
	temp = temp->next;
	count++;
    }
}

void playNext()
{
    if (current == NULL)
    {
	cout << "\nPlaylist Is Empty!";
    }
    else if (current->next == NULL)
    {
	cout << "\nThis Is The Last Song!";
    }
    else
    {
	current = current->next;
	cout << "\nNow Playing: " << current->song;
    }
}

void playPrevious()
{
    if (current == NULL)
    {
	cout << "\nPlaylist Is Empty!";
    }
    else if (current->prev == NULL)
    {
	cout << "\nThis Is The First Song!";
    }
    else
    {
	current = current->prev;
	cout << "\nNow Playing: " << current->song;
    }
}

void playFirst()
{
    if (head == NULL)
    {
	cout << "\nPlaylist Is Empty!";
    }
    else
    {
	current = head;
	cout << "\nNow Playing: " << current->song;
    }
}

void deleteSong()
{
    char name[50];
    Node *temp = head;

    if (head == NULL)
    {
	cout << "\nPlaylist Is Empty!";
	return;
    }

    cout << "\nEnter Song Name To Delete: ";
    gets(name);

    while (temp != NULL &&
	   strcmp(temp->song, name) != 0)
    {
	temp = temp->next;
    }

    if (temp == NULL)
    {
	cout << "\nSong Not Found!";
	return;
    }

    if (temp->prev != NULL)
    {
	temp->prev->next = temp->next;
    }
    else
    {
	head = temp->next;
    }

    if (temp->next != NULL)
    {
	temp->next->prev = temp->prev;
    }

    if (current == temp)
    {
	if (temp->next != NULL)
	    current = temp->next;
	else
	    current = temp->prev;
    }

    delete temp;

    cout << "\nSong Deleted Successfully!";
}

void main()
{
    int choice;

    do
    {
	clrscr();

	cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
	cout << "\n1. Add Song";
	cout << "\n2. Display Playlist";
	cout << "\n3. Play Previous Song";
	cout << "\n4. Play Next Song";
	cout << "\n5. Delete Song";
	cout << "\n6. Play First Song";
	cout << "\n7. Exit";

	cout << "\n\nEnter Your Choice: ";
	cin >> choice;
	cin.ignore();

	clrscr();

	switch (choice)
	{
	    case 1:
		addSong();
		break;

	    case 2:
		displayPlaylist();
		break;

	    case 3:
		playPrevious();
		break;

	    case 4:
		playNext();
		break;

	    case 5:
		deleteSong();
		break;

	    case 6:
		playFirst();
		break;

	    case 7:
		cout << "\nExiting Playlist Manager...";
		break;

	    default:
		cout << "\nInvalid Choice!";
	}

	if (choice != 7)
	{
	    cout << "\n\nPress Any Key To Continue...";
	    getch();
	}

    } while (choice != 7);

    while (head != NULL)
    {
	Node *temp = head;
	head = head->next;
	delete temp;
    }

    current = NULL;
    getch();
}