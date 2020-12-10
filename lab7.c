#include <stdio.h> 
#include <stdbool.h>
#include <string.h> 

/*
@author Demet Çalışkan 041801127
@date 10.12.2020
*/

/*
This program gets multiple string inputs from the user 
and checks whether the strings has even number of characters or not.
*/

struct st{ //struct creation
    char strings[10][20]; //string data to store each string with double dimensional char array
    int chars[20]; //integer array
};

int main() {
    struct st st; //struct object
    int num; //number of strings decleration
    printf("Enter the number of strings: ");
    scanf("%d", &num); //integer input for number of strings

    int counter = 0; //counter variable to create each string
    while(counter < num) {  //while loop to fill strings data of the st struct object
        char str[20]; //temporary string to store input
        printf("\nEnter a string: ");
        scanf("\n%s", str); //input string
        strncpy(st.strings[counter], str, strlen(str)); //making the struct object's string data equal to input string
        counter++; //increase the counter to move on to the next string
    }

    counter = 0; //counter variable to loop through each string
    while(counter < num) { //while loop to print out each letter in each string
        printf("\nCharacters of the %dth string: ", counter);
        for (int i = 0; i < strlen(st.strings[counter]); i++) {
            printf(" %c ", st.strings[counter][i]); //print each character in the string
        } 
        counter++; //increase the counter to move on to the next string
    }

    counter = 0; //counter variable to loop through each string
    while(counter < num) { //while loop to detect even or odd strings
        bool isEven = true; //boolean variable to detect whether a string has even number of characters or not
        int freq[26] = {0}; //integer array to store how many times the characters are used
        for (int i = 0; i < strlen(st.strings[counter]); i++) {
            freq[st.strings[counter][i] - 97]++; //for loop to fill the frequency array 
        }
        for (int i = 0; i < 26; i++) { //for loop to detect whether the character appearence is odd or even 
            if (freq[i] % 2 == 1) { //if the number of character appearence is an odd number,
                isEven = false; // isEven is false
            } 
        }
        if(isEven) { // if the string characters are evenly appeared,
            isEven = true;
            printf("\n%dth string has even number of characters.\n", counter); //print the conclusion of evency. 
        }
        counter++; //increase the counter to move on to the next string
    }
    
    return 0; 
}