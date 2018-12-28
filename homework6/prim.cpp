#include <cstdio>
#include <vector>
#include <list>
#include <utility>
using namespace std;
struct prim
{
    int x,y ;
    int Weight;
};

void Insertqueue(struct prim heaps[], int index, struct prim val)
{
    heaps[index] = val;

    int i;
    struct prim prim1;

    for(i=index; i >= 1; i= i/2) {
        if (heaps[i / 2].Weight > heaps[i].Weight) 
	{
   	    prim1 = heaps[i / 2];
            heaps[i / 2] = heaps[i];
            heaps[i] = prim1;

         }
	 else {
            break;
          	}
    	}
}

void Heapy(struct prim heaps[], int siz, int index)
{
    int i = index;
    struct prim prim1;

    while((2 * i) < siz){

        if ((2 * i) + 1 >= siz) {
           if (heaps[i].Weight > heaps[2 * i].Weight) {
                prim1 = heaps[i];
                heaps[i] = heaps[2 * i];
                heaps[2 * i] = prim1;
                break;
           }
        }

        if (heaps[i].Weight > heaps[2 * i].Weight || heaps[i].Weight > heaps[2 * i + 1].Weight) {

if (heaps[2 * i].Weight <= heaps[(2 * i) + 1].Weight) {
                prim1 = heaps[2 * i];
                heaps[2 * i] = heaps[i];
                heaps[i] = prim1;
                i = 2 * i;
            } else if (heaps[2 * i].Weight > heaps[(2 * i) + 1].Weight) {
                prim1 = heaps[(2 * i) + 1];
                heaps[(2 * i) + 1] = heaps[i];
                heaps[i] = prim1;
                i = (2 * i) + 1;
            }
        } else {
           break;
        }
    }
}

void DeleteNode(struct prim heaps[], int siz, int index)
{

//
int edges;


    struct prim prim1 = heaps[index];
    heaps[index] = heaps[siz - 1];
    heaps[siz - 1] = prim1;

    int i = index;

 siz = --siz;

    Heapy(heaps, siz, i);
}

struct prim ExtractMin(struct prim heaps[], int siz)
{
    struct prim min_val = heaps[0];
    DeleteNode(heaps, siz, 0);
    return min_val;
}

void Prim(
            vector< list< pair<int, int> > > & adj_matrix,
            int Vertex,
            int Edge,
            int start_Vert,
            vector< list< pair<int, int> > > & MinSpan
         )
{
    int current = start_Vert, new_Vert;
    bool visited[Vertex + 1];
    struct prim var;
    struct prim PriorityQueue[2 * Edge];
    int QueueSize = 0;

    int i;

    for (i = 0; i <= Vertex; ++i) {        
        visited[i] = false;
    }

  i = 0;

    while (i < Vertex) {
        if (!visited[current]) {            
            visited[current] = true;     
            list< pair<int, int> >::iterator iter = adj_matrix[current].begin();

            while (iter != adj_matrix[current].end()) {
                if (!visited[(*iter).first]) {
                    var.x = current;
                    var.y = (*iter).first;
                    var.Weight = (*iter).second;
		 Insertqueue(PriorityQueue, QueueSize, var);
                    ++QueueSize;
                }

                ++iter;
            }

            var = ExtractMin(PriorityQueue, QueueSize);    
            --QueueSize;

            new_Vert = var.y;
            current = var.x;

            if (!visited[new_Vert]) {
                MinSpan[current].push_back(make_pair(new_Vert, var.Weight));
                MinSpan[new_Vert].push_back(make_pair(current, var.Weight));
            }

            current = new_Vert;
            ++i;
        } else {

            var = ExtractMin(PriorityQueue, QueueSize);
            --QueueSize;

  	    new_Vert = var.y;
            current = var.x;

            if (!visited[new_Vert]) {
                MinSpan[current].push_back(make_pair(new_Vert, var.Weight));
                MinSpan[new_Vert].push_back(make_pair(current, var.Weight));
            }

            current = new_Vert;
        }
    }
}

int main()
{
    int Vertices, Edges;
    int  vert1, vert2, Weight;
//int v1,v2;
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &Vertices);

    printf("Enter the Number of Edges -\n");
    scanf("%d", &Edges);

    vector< list< pair<int, int> > > adj_matrix(Vertices + 1);
    vector< list< pair<int, int> > > MinSpan(Vertices + 1);
     printf("Enter the Edges Vert1 -> Vert2, of weight W\n");
 
    for (int i = 1; i <= Edges; ++i) {
        scanf("%d%d%d", &vert1, &vert2, &Weight);

        adj_matrix[vert1].push_back(make_pair(vert2, Weight));
        adj_matrix[vert2].push_back(make_pair(vert1, Weight));
    }

    printf("\nAdjacency_Matrix-\n");
    for (int i = 1; i < adj_matrix.size(); ++i) {
        printf("adj_matrix[%d] ", i);

        list< pair<int, int> >::iterator iter = adj_matrix[i].begin();

        while (iter != adj_matrix[i].end()) {
            printf(" -> %d(%d)", (*iter).first, (*iter).second);
            ++iter;
        }
        printf("\n");
    }

    int start_Vert;

 printf("\nEnter_the_Starting_Vertex - ");
    scanf("%d", &start_Vert);
    Prim(adj_matrix, Vertices, Edges, start_Vert, MinSpan);

    printf("\nThe Minimum Spanning Tree-\n");
    for (int i = 1; i < MinSpan.size(); ++i) {
        printf("Minimum Spanning Tree: MinSpan[%d] ", i);

        list< pair<int, int> >::iterator iter = MinSpan[i].begin();

        while (iter != MinSpan[i].end()) {
            printf(" -> %d(%d)", (*iter).first, (*iter).second);
            iter = ++iter;
        }
        printf("\n\n");
    }

    return 0;
}


