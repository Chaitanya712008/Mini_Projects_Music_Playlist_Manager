    #include<iostream>
#include<string>
#include<climits>
using namespace std;

class Node{

    public:
    string songtitle;
    string artistname;
    Node *next;
    Node *prev;

     Node(string SongTitle, string ArtistName)
    {
        songtitle = SongTitle;
        artistname = ArtistName;

        // Initially, the new node has no previous or next node
        prev = nullptr;
        next = nullptr;
    }
     
};

Node *head = nullptr;   //head points ot first song
Node *current = nullptr;  // current points to the currently playing song

int empty(){
    if (head == nullptr){
        return 1;     // Playlist is empty
    }
    else{
        return 0;     // Playlist is not empty
    }
}

void addSong(string SongTitle, string ArtistName)
{
    Node *p = new Node(SongTitle, ArtistName);     //p points to the new node

    if (empty())
    {
        head = p;     //first song becomes the head
        current = p;  // first song becomes the current song
    }
    else
    {
        Node *q = head;   //q is used to traverse the list

        while (q->next != nullptr)   // Move q to the last node
        {
            q = q->next;
        }

        q->next = p;
        p->prev = q;
    }
}


void displayPlaylist(){
    if (empty()){
        cout << "Playlist is empty" << endl;
    }
    else{
        Node *q = head;
        while( q != nullptr){    //display song from first to last
            cout << "Song Title: " << q->songtitle << ", Artist Name: " << q->artistname << endl;
            q = q->next;
        }
    }
}


void deleteSong(string songTitle)
{
    if (empty())
    {
        cout << "Playlist is empty" << endl;
        return;
    }

    Node *p = nullptr;  //p point to the node to be deleted

    if (head->songtitle == songTitle)
    {
        p = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        if (current == p)
        {
            current = head;
        }

        delete p;
        cout << "Song deleted successfully" << endl;
        return;
    }

    Node *q = head;  //q is used for traversal

    while (q->next != nullptr)
    {
        if (q->next->songtitle == songTitle)
        {
            p = q->next;
            q->next = p->next;   // Update links to remove the node p

            if (p->next != nullptr)
            {
                p->next->prev = q;    // Update the previous link of the next node
            }

            if (current == p)
            {
                if (p->next != nullptr)
                {
                    current = p->next;
                }
                else
                {
                    current = p->prev;
                }
            }

            delete p;  // deleting song which is selected by user
            cout << "Song deleted successfully" << endl;
            return;
        }

        q = q->next;
    }

    cout << "Song not found" << endl;
}

void playCurrentSong(){
    if (current == nullptr){
        cout << "No song is currently playing" << endl;
    }
    else{
        cout << "Now playing: " << current->songtitle << " by " << current->artistname << endl;

    }
}

void playNextSong(){
    if(current == nullptr){
        cout << "No song is currently playing" << endl;
    }
    else if(current->next == nullptr){
        cout << "This is the last song in the playlist" << endl;
    }
    else{
        current = current->next;
        cout << "Now playing: " << current->songtitle << " by " << current->artistname << endl;
    }    
}

void playPreviousSong(){
    if(current == nullptr){
        cout << "No song is currently playing "<< endl;
    }
    else if(current-> prev == nullptr){
        cout << "This is the first song in the playlist" << endl;
    }
    else{
        current = current->prev;
        cout << "Now playing: " << current->songtitle << " by " << current->artistname << endl;
    }
}

void displayReversePlaylist(){
    if(empty()){
        cout<<" list is empty"<< endl;
        return;
    }

    Node *q = head;
    // Move q to the last node
    while(q-> next != nullptr){
        q= q-> next;
    }

    // traverse in reverse order
    while(q != nullptr){
        cout << "Song Title: " << q->songtitle << ", Artist Name: " << q->artistname << endl;
        q = q -> prev;
    }
}


void showCurrentSong() {
    if (current == nullptr) {
        cout << "No song is currently selected" << endl;
        return;
    }

    cout << "Current Song: " << current->songtitle
         << " by " << current->artistname << endl;
}

void completeplaylist(){
    if(empty()){
        cout << " Playlist is empty " << endl;
        return;
    }
        Node *q = head;

        while(q != nullptr){
             cout << "Song Title: " << q->songtitle << ", Artist Name: " << q->artistname << endl;
            q = q -> next;
        }
    
}

void repeatAll(int repetitions){
    if (empty()){
        cout << "Playlist is empty" << endl;
        return;
    }
    if(repetitions <= 0){
        cout << "Invalid number of repetitions" << endl;
        return;
    }
    //Repeat the playlist for the specified number of repetitions
    for (int i = 1;  i <= repetitions; i++){
        cout << "Repetition: " << i << endl;
        Node *q = head;    // start from first song for each repetition
        while(q != nullptr){
            cout << "Song Title: " << q->songtitle << ", Artist Name: " << q->artistname << endl;
            q = q->next;
        }
    }

}

int main() {
    int choice, repetitions;
    string songTitle, artistName;

    //display menu for selecting choice
    do {
        cout << endl << " || Music Playlist Manager || " << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Delete Song" << endl;
        cout << "3. Display Playlist" << endl;
        cout << "4. Display Playlist in Reverse" << endl;
        cout << "5. Play Current Song" << endl;
        cout << "6. Play Next Song" << endl;
        cout << "7. Play Previous Song" << endl;
        cout << "8. Play Complete Playlist" << endl;
        cout << "9. Repeat All" << endl;
        cout << "10. Show Current Song" << endl;
        cout << "11. Exit" << endl <<endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                cin >> songTitle;

                cout << "Enter artist name: ";
                cin >> artistName;

                addSong(songTitle, artistName);
                break;

            case 2:
                cout << "Enter song title to delete: ";
                cin >> songTitle;

                deleteSong(songTitle);
                break;

            case 3:
                displayPlaylist();
                break;

            case 4:
                displayReversePlaylist();
                break;

            case 5:
                playCurrentSong();
                break;

            case 6:
                playNextSong();
                break;

            case 7:
                playPreviousSong();
                break;

            case 8:
                completeplaylist();
                break;

            case 9:
                cout << "Enter number of repetitions: ";
                cin >> repetitions;

                repeatAll(repetitions);
                break;

            case 10:
                showCurrentSong();
                break;

            case 11:
                cout << "Exiting Music Playlist Manager..." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter 1-11." << endl;
        }

    } while (choice != 11);   //continue until the user selects Exit

    return 0;
}


//Output: 
// PS D:\cpp codes> 
// PS D:\cpp codes> g++ Music_Playlist_Manager.cpp                                               
// PS D:\cpp codes> ./a.exe                                                                      
                                                                                              
//  || Music Playlist Manager ||                                                                 
// 1. Add Song                                                                                   
// 2. Delete Song            
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 2
// Enter song title to delete: ABCD
// Playlist is empty

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 1
// Enter song title: Hanumanchalisa
// Enter artist name: Rasrajji

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 1
// Enter song title: BajrangBaan
// Enter artist name: Rasrajji

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 1
// Enter song title: HarHargange
// Enter artist name: ArjitSingh

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 1
// Enter song title: Shivtandav
// Enter artist name: Shakarmahadevan

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 2    
// Enter song title to delete: Hanumanchalisa
// Song deleted successfully

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 3              
// Song Title: BajrangBaan, Artist Name: Rasrajji
// Song Title: HarHargange, Artist Name: ArjitSingh
// Song Title: Shivtandav, Artist Name: Shakarmahadevan

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 4
// Song Title: Shivtandav, Artist Name: Shakarmahadevan
// Song Title: HarHargange, Artist Name: ArjitSingh
// Song Title: BajrangBaan, Artist Name: Rasrajji

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 5
// Now playing: BajrangBaan by Rasrajji

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 2
// Enter song title to delete: Harhargange
// Song not found

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 2
// Enter song title to delete: HarHargange
// Song deleted successfully

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 3
// Song Title: BajrangBaan, Artist Name: Rasrajji
// Song Title: Shivtandav, Artist Name: Shakarmahadevan

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 1
// Enter song title: Namonamo
// Enter artist name: amittrivedi

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 3
// Song Title: BajrangBaan, Artist Name: Rasrajji
// Song Title: Shivtandav, Artist Name: Shakarmahadevan
// Song Title: Namonamo, Artist Name: amittrivedi

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 2
// Enter song title to delete: Namonamo
// Song deleted successfully

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 3
// Song Title: BajrangBaan, Artist Name: Rasrajji
// Song Title: Shivtandav, Artist Name: Shakarmahadevan

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 5
// Now playing: BajrangBaan by Rasrajji

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 6
// Now playing: Shivtandav by Shakarmahadevan

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 7
// Now playing: BajrangBaan by Rasrajji

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 7
// This is the first song in the playlist

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 6
// Now playing: Shivtandav by Shakarmahadevan

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 
// 6
// This is the last song in the playlist

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 1
// Enter song title: Tufaan
// Enter artist name: Keshav

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 3
// Song Title: BajrangBaan, Artist Name: Rasrajji
// Song Title: Shivtandav, Artist Name: Shakarmahadevan
// Song Title: Tufaan, Artist Name: Keshav

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 8
// Song Title: BajrangBaan, Artist Name: Rasrajji
// Song Title: Shivtandav, Artist Name: Shakarmahadevan
// Song Title: Tufaan, Artist Name: Keshav

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 9 
// Enter number of repetitions: 3
// Repetition: 1
// Song Title: BajrangBaan, Artist Name: Rasrajji
// Song Title: Shivtandav, Artist Name: Shakarmahadevan
// Song Title: Tufaan, Artist Name: Keshav
// Repetition: 2
// Song Title: BajrangBaan, Artist Name: Rasrajji
// Song Title: Shivtandav, Artist Name: Shakarmahadevan
// Song Title: Tufaan, Artist Name: Keshav
// Repetition: 3
// Song Title: BajrangBaan, Artist Name: Rasrajji
// Song Title: Shivtandav, Artist Name: Shakarmahadevan
// Song Title: Tufaan, Artist Name: Keshav

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 9
// Enter number of repetitions: -8
// Invalid number of repetitions

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 10
// Current Song: Shivtandav by Shakarmahadevan

//  || Music Playlist Manager || 
// 1. Add Song
// 2. Delete Song
// 3. Display Playlist
// 4. Display Playlist in Reverse
// 5. Play Current Song
// 6. Play Next Song
// 7. Play Previous Song
// 8. Play Complete Playlist
// 9. Repeat All
// 10. Show Current Song
// 11. Exit

// Enter your choice: 11
// Exiting Music Playlist Manager...
// PS D:\cpp codes>  

