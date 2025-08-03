#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSONGS 50
#define MAXNAMELENGTH 100
#define MAXPLAYLISTSIZE 20

typedef struct {
    char name[MAXNAMELENGTH];
    char artist[MAXNAMELENGTH];
    char releasedate[MAXNAMELENGTH];
} Song;     //Making a structure named Song

typedef struct {
    char name[MAXNAMELENGTH];
    Song songs[MAXPLAYLISTSIZE];
    int count;
} Playlist;     //Making a structure named playlist 

Song songs[MAXSONGS];
int songCount = 0;

Playlist playlist;

void initialize() {
    playlist.count = 0;
}

void addSong(char name[], char artist[], char releasedate[]) {
    if (songCount < MAXSONGS) {
        strcpy(songs[songCount].name, name);
        strcpy(songs[songCount].artist, artist);
        strcpy(songs[songCount].releasedate, releasedate);
        songCount++;
    } else {
        printf("Cannot add more songs. Song limit reached.\n");
    }
}        //Making a void function to add songs 

void searchByName(char name[]) {
    int found = 0;
    printf("Search results by song name:\n");
    int i;
    for (i = 0; i < songCount; i++) {
        if (strstr(songs[i].name, name) != NULL) {
            printf("%s by %s (%s)\n", songs[i].name, songs[i].artist, songs[i].releasedate);
            found = 1;
        }
    }
    if (!found) {
        printf("No songs found with the entered name.\n");
    }
}        //Making a void function to search songs by name

void searchByArtist(char artist[]) {
    int found = 0;
    printf("Search results by artist name:\n");
    int i;
    for (i = 0; i < songCount; i++) {
        if (strstr(songs[i].artist, artist) != NULL) {
            printf("%s by %s (%s)\n", songs[i].name, songs[i].artist, songs[i].releasedate);
            found = 1;
        }
    }
    if (!found) {
        printf("No songs found by the entered artist name.\n");
    }
}       //Making a void function to search songs by the name of the artist 

void addToPlaylist(char name[]) {
    if (playlist.count < MAXPLAYLISTSIZE) {
    	int i;
        for (i = 0; i < songCount; i++) {
            if (strcmp(songs[i].name, name) == 0) {
                strcpy(playlist.songs[playlist.count].name, songs[i].name);
                strcpy(playlist.songs[playlist.count].artist, songs[i].artist);
                strcpy(playlist.songs[playlist.count].releasedate, songs[i].releasedate);
                playlist.count++;
                printf("Song added to playlist successfully.\n");
                return;
            }
        }
        printf("Entered song not found.\n");
    } else {
        printf("Cannot add more songs to the playlist. Playlist is full.\n");
    }
}        //Making a void function to add songs to the playlist 

void changePlaylistName(char name[]) {
    strcpy(playlist.name, name);
    printf("Playlist name changed to %s.\n", name);
}       //Making a void function to change the name of the playlist 

void viewPlaylist() {
    printf("Playlist: %s\n", playlist.name);
    int i;
    for (i = 0; i < playlist.count; i++) {
        printf("%s by %s (%s)\n", playlist.songs[i].name, playlist.songs[i].artist, playlist.songs[i].releasedate);
    }
}     //Making a void function to view playlist 

int main() {
    char input[MAXNAMELENGTH];
    char artist[MAXNAMELENGTH];

    initialize();

    addSong("Daylight", "Taylor Swift", "January 7, 2020");
    addSong("Love Story", "Taylor Swift", "April 13, 2017");
    addSong("Gumaan", "Young Stunners", "September 18, 2020");
    addSong("Afsanay", "Young Stunners", "March 19, 2021");
    addSong("No Cap", "KR$NA", "November 10, 2021");
    addSong("Blowing Up", "KR$NA", "March 10, 2022");
    addSong("Kessariya", "Arjit Singh", "October 21, 2022");
    addSong("Channa Mereya", "Arjit Singh", "December 17, 2019");
    addSong("Lose Yourself", "Eminem", "October 28, 2002");
    addSong("Stan (feat. Dido)", "Eminem", "November 21, 2000");
    addSong("See You Again (feat. Wiz Khalifa)", "Charlie Puth", "March 10, 2015");
    addSong("Attention", "Charlie Puth", "April 21, 2017");
    addSong("Faded", "Alan Walker", "December 4, 2015");
    addSong("Alone", "Alan Walker", "December 2, 2016");
    printf("Welcome to the Music Player!\n");
//All the songs which can be searched or added in the program which are already in the program database 
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Search for song by name\n");
        printf("2. Search for songs by artist name\n");
        printf("3. Add song to playlist\n");
        printf("4. Change playlist name\n");
        printf("5. View playlist\n");
        printf("6. Exit\n");
        printf("Enter your choice from the above given options (1/2/3/4/5/6): "); //making a menu driven program 

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter the song name: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                searchByName(input);
                break;
            case 2:
                printf("Enter the name of the artist: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = 0;
                searchByArtist(artist);
                break;
            case 3:
                printf("Enter song name to add to the playlist: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                addToPlaylist(input);
                break;
            case 4:
                printf("Enter the new name for your playlist: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                changePlaylistName(input);
                break;
            case 5:
                viewPlaylist();
                break;
            case 6:
                printf("Goodbye.....:)\n");
                exit(0);
            default:
                printf("Invalid choice, please try again......:(\n");
                break;
        }
    } //Making a menu driven program for searching the song by name, search by artist name, add song to playlist, change playlist name, view playlist, and exiting the program 
    return 0;
} //exiting the program
