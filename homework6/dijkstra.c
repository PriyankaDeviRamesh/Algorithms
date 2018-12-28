#include <stdio.h>
#include <stdlib.h>
int a[50][50] , dist[20] , in_set[20] , p[20] , Parent[20] ;
void Print( int Vert )
{
    int i ;
    for ( i = 0 ; i < Vert ; i++ )
        printf("i = %d, Distance_from_Source_Vertex = %d \n", i + 1 , dist[i] ) ;
}
int sum( int Vert )
{
    int r,sum = 0 ;
    for( r = 0 ; r < Vert ; r++ )
        sum = sum + p[r] ;
    return sum ;
}
int Extract_Min( int Vert )
{
    int i , index , min_value = 5000 ;
    for ( i = 0 ; i < Vert ; i++ )
    {
        if ( dist[i] <= min_value && in_set[i] == 0 )
            min_value = dist[i] , index = i ;
    }
    p[index] = 0 ;
    return index ;
}
void Dijkstra ( int S , int Vert )
{
    int v , i , CheckEmpty = sum(Vert);

    while( CheckEmpty >0 )
    {
        v = Extract_Min(Vert) ;

        in_set[v] = 1 ;
        p[v] = 0 ;
        for( i = 0 ; i < Vert ; i++ )
        {
            if( a[v][i] > 0 )
            {
                if( dist[v] + a[v][i] < dist[i] )
                    dist[i] = dist[v] + a[v][i] , Parent[i] = v + 1 ;
            }
        }
        CheckEmpty = sum(Vert);
    }

    Print(Vert);
}
int main()
{
    int Vert , s ,t , Sour;
    printf ( "Enter_the_no_of_vertices: " ) ;
    scanf ( "%d" , &Vert ) ;

    printf ( "Enter_the_graph_in_adjacency_matrix_form:\n" ) ;
    for ( s = 0 ; s < Vert ; s++ )
    {
        for( t = 0 ; t < Vert ; t++ )
            scanf( "%d" , &a[s][t] );
    }
    for ( s = 0 ; s < Vert ; s++ )
        dist[s] = 5000 , in_set[s] = 0 , p[s] = 1 , Parent[s] = -1 ;

    printf ( "Enter_the_source_vertex: " ) ;
    scanf ( "%d" , &Sour ) ;
    dist[ Sour - 1 ] = 0 ;
    Dijkstra ( Sour , Vert ) ;
    return 0;
}
