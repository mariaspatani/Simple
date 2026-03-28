#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, head;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    int req[100], visited[100]={0};
    printf("Enter requests:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&req[i]);
    printf("Enter initial head: ");
    scanf("%d",&head);
    int pos = head, total = 0;
    printf("\nSeek Sequence: %d",pos);
    for(int i=0;i<n;i++){
        int min = 9999, index = -1;
        for(int j=0;j<n;j++){
            if(!visited[j]){
                int dist = abs(pos - req[j]);
                if(dist < min){
                    min = dist;
                    index = j;
                }
            }
        }
        visited[index] = 1;
        total += min;
        pos = req[index];
        printf(" -> %d",pos);
    }
    printf("\nTotal Seek Time = %d\n",total);
    return 0;
}
/*
Key Variables

    n: Number of disk requests (array size).

    head: Initial position of the disk head.

    req[100]: Array storing the disk track request positions.

    visited[100]={0}: Boolean array tracking which requests have been serviced (0 = unvisited, 1 = visited).

    pos: Current head position (starts at head).

    total: Accumulates the total seek time (head movement distance).

    min, index: Temporary variables to find the nearest unvisited request.

How It Works

The program takes user input for request count, track positions, and initial head position.
It then repeatedly finds the unvisited request closest to the current position using abs(pos - req[j]), 
services it (marks as visited, adds distance to total), updates pos, and prints the seek sequence until all requests are handled.

Core Loop Logic:

text
For each of n requests:
  Scan all unvisited requests
  Pick the one with minimum |current_pos - req[j]|
  Service it, add distance to total, mark visited
  Move head to that position

Sample Execution

Input: 5 requests [98, 183, 37, 122, 14], head = 53

Seek sequence might be: 53 -> 37 -> 14 -> 98 -> 122 -> 183
Total seek time = sum of absolute distances.
Output Format

text
Seek Sequence: 53 -> 37 -> 14 -> 98 -> 122 -> 183
Total Seek Time = 208
*/
