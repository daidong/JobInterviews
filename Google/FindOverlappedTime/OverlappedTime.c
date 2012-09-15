#include <stdio.h>

#define N 20

typedef struct TimeElement{
  int id;
  int type;
  long value;
} te;

void copyTo(te a, te b){
  b.id = a.id;
  b.type = a.type;
  b.value = a.value;
}

int pivotPartition(te list[], int s, int e){
  long pivot = list[s].value;
  int mid = s;
  int largeS = s;
  int largeE = s;
  int curr = s + 1;

  for (curr; curr < e; curr++){
    if (list[curr].value > pivot){
      largeE = curr;
    } else {
      te tmp;
      //copyTo(list[curr], tmp);
      tmp.id = list[curr].id;
      tmp.type = list[curr].type;
      tmp.value = list[curr].value;
      
      int j = curr;
      for (j; j > largeS; j--){
	list[j].id = list[j-1].id;
	list[j].type = list[j-1].type;
	list[j].value = list[j-1].value;
      }
      //copyTo(list[j-1], list[j]);
      list[largeS].id = tmp.id;
      list[largeS].type = tmp.type;
      list[largeS].value = tmp.value;
      //copyTo(tmp, list[largeS]);
      largeS++;
      mid++;
    }
  }
  return mid;
}
void sort(te list[], int s, int e){
  if (e - s == 1)
    return;
  if (e == s)
    return;

  int mid = pivotPartition(list, s, e);
  sort(list, s, mid);
  sort(list, mid + 1, e);
}

int main(){
  FILE *fp = NULL;
  if ((fp = fopen("times.txt", "r")) == NULL){
    printf("Not Openned\n");
    return 0;
  }

  te nodes[20];
  int i = 0;
  long start = 0;
  long end = 0;
  int id = 0;
  while (fscanf(fp, "%ld %ld %d\n", &start, &end, &id) != EOF){
    nodes[i].value = start;
    nodes[i].id = id;
    nodes[i].type = 0;
    i++;
    nodes[i].value = end;
    nodes[i].id = id;
    nodes[i].type = 1;
    i++;
  }
  
  sort(nodes, 0, i);

  int j = 0;
  for (j = 0; j < i; j++){
    printf("%d %d %ld\n", nodes[j].id, nodes[j].type, nodes[j].value);
  }
  
  int max = 0;
  int currOverlapped = 0;
  for (j = 0; j < i; j++){
    if (nodes[j].type == 0){
      currOverlapped++;
      if (currOverlapped >= max){
	max = currOverlapped;
	start = nodes[j].value;
      }
    } else {
      currOverlapped--;
      if (currOverlapped == (max - 1))
	end = nodes[j].value;
    }
  }

  printf("Max Overlapped times: %d, From %ld to %ld\n", max, start, end);
  return 1;
}
