#include <stdio.h>
#include <stdbool.h>

#define MAX_PEOPLE 50

typedef struct {
    int id;
} People;

typedef struct {
    People data[MAX_PEOPLE];
    int head;
    int tail;
    int count;
} Queue;


int main() {
    Queue q;
    int total_people=10;
    int report_interval=3;

    // TODO: 在这里添加你的代码
    q.head = 0;
    q.tail = 0;
    q.count = 0;
    for(int i=0; i<total_people; i++){
        q.data[i].id = i+1;
        q.count++;
        q.tail = q.tail+1;
    }

    while(q.count > 1){
        for(int i=1;i<report_interval;){
            if(q.data[q.head].id != 0){
                i++;
            }
            q.head = (q.head+1)%total_people;
        }
        while(q.data[q.head].id == 0){
            q.head = (q.head+1)%total_people;
        }
        q.data[q.head].id = 0;
        q.head = (q.head+1)%total_people;
        q.count--;
    }
    while(q.data[q.head].id == 0){
        q.head = (q.head+1)%total_people;
    }
    printf("最后剩下的人是: %d\n", q.data[q.head].id);

    return 0;
}