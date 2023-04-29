#include <stdio.h>
#include <stdlib.h>

int **graph;
int n;

void greedyvcover();
void getinputgraph();

int main()
{
    getinputgraph();
    greedyvcover();

    return 0;
}

void getinputgraph()
{
    int i, j, k, count;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    graph = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        printf("how many vertices are adjacent to vertex %d= ?", i);
        scanf("%d", &count);
        graph[i] = (int *)malloc((count + 1) * sizeof(int));
        if (count)
            printf("Enter vertex numbers in increasing order:- ");
        k = 0;

        while (k < count)
        {
            scanf("%d", &graph[i][k]);
            k++;
        }
        graph[i][k] = -1;
    }
}

void greedyvcover()
{
    int *degree = (int *)malloc(n * sizeof(int));
    int i, j, k, max_deg, max_deg_index, cover_size = 0;

    for (i = 0; i < n; i++)
    {
        degree[i] = 0;
        while (graph[i][degree[i]] != -1)
            degree[i]++;
    }

    while (1)
    {

        max_deg = -1;
        for (i = 0; i < n; i++)
        {
            if (degree[i] > max_deg)
            {
                max_deg = degree[i];
                max_deg_index = i;
            }
        }

        if (max_deg == 0)
            break;

        degree[max_deg_index] = -2;
        cover_size++;

        for (j = 0; graph[max_deg_index][j] != -1; j++)
        {
            k = graph[max_deg_index][j];
            if (degree[k] >= 1)
                degree[k]--;
        }
    }

    printf("Vertex cover: ");
    for (i = 0; i < n; i++)
    {
        if (degree[i] == -2)
            printf("%d ", i);
    }
    printf("\nVertex cover size: %d\n", cover_size);

    free(degree);
    for (i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
}

