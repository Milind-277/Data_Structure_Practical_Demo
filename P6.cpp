//Create a doubly linked list where each node represents a song, with details like song title, artist, and song duration.
    //a. Implement features to add, remove, and view songs in the playlist.
    //b. Allow the user to shuffle the playlist, where the songs are played in random order by traversing the list forward and backward.
    //c. Implement a &quot;next&quot; and &quot;previous&quot; feature to navigate through the playlist.



#include <iostream>
#include <cstring>
#include <cstdlib>   
#include <ctime>     
using namespace std;

struct Song {
    char title[50];
    char artist[50];
    float duration;
    Song *next;
    Song *prev;
};

Song *head = NULL;
Song *tail = NULL;
Song *current = NULL;   

void addSong() {
    Song *newSong = new Song;

    cin.ignore();
    cout << "Enter Song Title: ";
    cin.getline(newSong->title, 50);

    cout << "Enter Artist Name: ";
    cin.getline(newSong->artist, 50);

    cout << "Enter Duration (in minutes): ";
    cin >> newSong->duration;

    newSong->next = NULL;
    newSong->prev = NULL;

    if (head == NULL) {
        head = tail = current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }

    cout << "\nSong Added Successfully!\n";
}

void viewPlaylist() {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Song *temp = head;
    cout << "\n--- Playlist ---\n";
    while (temp != NULL) {
        cout << "\nTitle: " << temp->title;
        cout << "\nArtist: " << temp->artist;
        cout << "\nDuration: " << temp->duration << " mins\n";
        cout << "---------------------";
        temp = temp->next;
    }
}

void removeSong() {
    if (head == NULL) {
        cout << "Playlist empty!\n";
        return;
    }

    char songTitle[50];
    cin.ignore();
    cout << "Enter Song Title to Remove: ";
    cin.getline(songTitle, 50);

    Song *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->title, songTitle) == 0) {
            if (head == tail) {
                head = tail = current = NULL;
            }
            else if (temp == head) {
                head = head->next;
                head->prev = NULL;
            }
            else if (temp == tail) {
                tail = tail->prev;
                tail->next = NULL;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            cout << "Song Removed Successfully!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Song Not Found!\n";
}

void shufflePlaylist() {
    if (head == NULL) {
        cout << "Playlist empty!\n";
        return;
    }

    srand(time(0)); 

    Song *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "\n--- Shuffled Playlist ---\n";

    for (int i = 0; i < count; i++) {
        int step = rand() % 2;  

        if (step == 0 && current->next != NULL) {
            current = current->next;
        } else if (step == 1 && current->prev != NULL) {
            current = current->prev;
        }

        cout << "\nPlaying: " << current->title;
        cout << "\nArtist: " << current->artist;
        cout << "\n-------------------------";
    }
}

void nextSong() {
    if (current == NULL) {
        cout << "Playlist empty!\n";
        return;
    }

    if (current->next != NULL) {
        current = current->next;
        cout << "\nNow Playing: " << current->title << " by " << current->artist << endl;
    } else {
        cout << "You are at the last song.\n";
    }
}

void prevSong() {
    if (current == NULL) {
        cout << "Playlist empty!\n";
        return;
    }

    if (current->prev != NULL) {
        current = current->prev;
        cout << "\nNow Playing: " << current->title << " by " << current->artist << endl;
    } else {
        cout << "You are at the first song.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Playlist Menu ---\n";
        cout << "1. Add Song\n";
        cout << "2. View Playlist\n";
        cout << "3. Remove Song\n";
        cout << "4. Shuffle Playlist\n";
        cout << "5. Next Song\n";
        cout << "6. Previous Song\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addSong(); break;
            case 2: viewPlaylist(); break;
            case 3: removeSong(); break;
            case 4: shufflePlaylist(); break;
            case 5: nextSong(); break;
            case 6: prevSong(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 7);

    return 0;
}
