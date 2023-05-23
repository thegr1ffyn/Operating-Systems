/*
Implement the paging technique in memory.
Your program should:
"	Get the page size and memory size from the user.
"	Generate a random sequence for free frames with max capacity at memory_size/page_size
"	Offer the following options to the user for selection:
1.	Process Allocation
2.	Free Frames Display
3.	Process Deallocation
4.	Display Page Table 
5.	Exit
"	In case the user selects 1 then ask the user for the size and ID of the process and allocates the free frames to the process and display the allocated frames
"	In case the user selects 2 then your program should display the free frames available
"	In case option 3 is selected then ask the user for the process ID which needs to be deallocated and free the allocated frames.
"	In case option 4 is selected ask the user for the process ID and display the page table for the process with ID entered by the user.
In case option 5 is selected your program should get exit.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FRAMES 100

int free_frames[MAX_FRAMES];
int allocated_frames[MAX_FRAMES];
int page_table[MAX_FRAMES];

int main() {

	int page_size, memory_size;

	// Inputting page size
	printf("Enter page size: ");
	scanf("%d", &page_size);

	//Inputting Memory Size
	printf("Enter memory size: ");
	scanf("%d", &memory_size);

	//Simulates allocation of free physical frames for a process needing
	int max_capacity = memory_size / page_size;
		for (int i = 0; i < max_capacity; i++) {
    			free_frames[i] = i;
		}

//Menu for User GUI to choose from
while (true) {
    printf("\nPaging Technique in Memory\n\n");
    printf("\nChoose an option:\n");
    printf("[1] Process Allocation:\n");
    printf("[2] Free Frames Display\n");
    printf("[3] Process Deallocation\n");
    printf("[4] Display Page Table\n");
    printf("[5] Exit\n");
    printf("Your choice=>  ");
    //inputs the option from the user
    int option;
    scanf("%d", &option);

    // this code is main runner code. What it does is that if Process ALlocation is wanted by user then it takes the process ID and process size as well. If it exceeds the limits then it prints an error
    if (option == 1) {
        int process_id, process_size;
        printf("Enter process ID: ");
        scanf("%d", &process_id);
        printf("Enter process size: ");
        scanf("%d", &process_size);

        if (process_size > max_capacity) {
            printf("Process size exceeds memory capacity.\n");
            continue;
        }
         if (free_frames[0] == -1) {
            printf("No free frames available.\n");
            continue;
        }

        //this code allocates the drames to the given process ids with their sizes
        for (int i = 0; i < process_size; i++) {
            allocated_frames[i] = free_frames[0];
            free_frames[0] = free_frames[1];
            free_frames[max_capacity - 1] = -1;
        }

        for (int i = 0; i < process_size; i++) {
            page_table[i] = allocated_frames[i];
        }

	//this code will print the allocated frames
        printf("Allocated frames: ");
        for (int i = 0; i < process_size; i++) {
            printf("%d ", allocated_frames[i]);
        }
        printf("\n");
    } 
// if user asked for option 2 then this code runs

else if (option == 2) {
        printf("Free frames: ");
        for (int i = 0; i < max_capacity; i++) {
            if (free_frames[i] != -1) {
                printf("%d ", free_frames[i]);
            }
        }
        printf("\n");
    }
// if user asked for option 3 then this code runs to display process disallocation by taking process id and then deallocating
else if (option == 3) {
        int process_id;
        printf("Enter process ID: ");
        scanf("%d", &process_id);

        for (int i = 0; i < max_capacity; i++) {
            if (page_table[i] == process_id) {
                page_table[i] = -1;
                free_frames[max_capacity - 1] = page_table[i];
                max_capacity++;
            }
        }

        printf("Frames deallocated.\n");
    }

//if user asked for option 4 then this code runs and displayes the page table 

else if (option == 4) {
        int process_id;
        printf("Enter process ID: ");
        scanf("%d", &process_id);

        for (int i = 0; i < max_capacity; i++) {
            if (page_table[i] == process_id) {
                printf("Page %d -> Frame %d\n", i, page_table[i]);
            }
        }
    } 
	
else if (option == 5) {
        break;
    } else {
        printf("Invalid option.\n");
    }
}

return 0;
}
