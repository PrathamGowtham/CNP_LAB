#include<stdio.h>

struct edge {
    int u, v, dist, selected;
} e[100];

int parent[100], edge_count = 0;

void getdata(int total) {
    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            printf("Enter distance between Vertex %c and %c: ", i + 65, j + 65);
            scanf("%d", &e[edge_count].dist);
            e[edge_count].u = i;
            e[edge_count].v = j;
            e[edge_count++].selected = 0;
        }
    }
}

void sort() {
    struct edge temp;
    for (int i = 0; i < edge_count - 1; i++) {
        for (int j = 0; j < edge_count - i - 1; j++) {
            if (e[j].dist > e[j + 1].dist) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

int find(int i) {
    if (parent[i] == i)
        return i;
    return find(parent[i]);
}

void union_set(int u, int v) {
    int set_u = find(u);
    int set_v = find(v);
    parent[set_v] = set_u;
}

void kruskal(int total) {
    int edgeselected = 0;
    for (int i = 0; i < edge_count && edgeselected < total - 1; i++) {
        int set_u = find(e[i].u);
        int set_v = find(e[i].v);
        if (set_u != set_v) {
            e[i].selected = 1;
            edgeselected++;
            union_set(set_u, set_v);
        }
    }
}

int main() {
    int total;
    printf("Enter the number of nodes: ");
    scanf("%d", &total);

    for (int i = 0; i < total; i++)
        parent[i] = i;

    getdata(total);
    sort();
    kruskal(total);

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < edge_count; i++) {
        if (e[i].selected) {
            printf("%c <--> %c, Distance: %d\n", e[i].u + 65, e[i].v + 65, e[i].dist);
        }
    }

    return 0;
}

