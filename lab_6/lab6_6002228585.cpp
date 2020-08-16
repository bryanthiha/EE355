// Bryan Thiha 	
// 6002228585
// 04/01/20


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// delete dynamic memory, change variable names, beautify spacing, transfer to classroom got and then tame out unnecessary, 
//look into not hardcoding 10

void read_file()
{
	ifstream infile;

	int x, y;

	infile.open("input.txt");

	int input[10][3];

	infile >> y;

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			
			infile >> x;
																	// Storing all numbers into array 
			input[i][j] = x;

			cout << input[i][j] << " "; 

		}
		cout << endl;

	}
	infile.close();

	cout << endl;

	int distance[10][10];

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			distance[i][j] = sqrt(pow((input[i][1] - input[j][1]), 2) + pow((input[i][2] - input[j][2]), 2));

			cout << distance[i][j] << " ";
		}
		cout << endl ;
	}

	cout << endl;
}


int** in_file()
{

	ifstream infile;

	int entry, size;

	infile.open("input.txt");

	int** input = new int*[10];

	for(int i = 0; i < 10; i++)
	{
		input[i] = new int[3];
	}
    


	infile >> size;

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			
			infile >> entry;
																	// Storing all numbers into array 
			input[i][j] = entry; 

		}

	}
	infile.close();

	return input;

}

int** edges()
{

	int** input = in_file();
	//int distance[10][10];

	int** distance = new int*[10];

	for(int i = 0; i < 10; i++)
	{
		distance[i] = new int[10];
	}



	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			distance[i][j] = sqrt(pow((input[i][1] - input[j][1]), 2) + pow((input[i][2] - input[j][2]), 2));

			//cout << distance[i][j] << " ";
		}
		//cout << endl ;
	}

	//cout << endl;

	return distance;

	delete[] distance;
}

class Edge
{
	public:
		int source;
		int dest;
		int weight;

};

int find(int parent[], int i)  
{  
    if (parent[i] == i)
    {
    	return i;
    }  
          
    return find(parent, parent[i]);  
}

void unite(int parent[], int x, int y)  
{  
    //int x_par = find(parent, x);  
    //int y_par = find(parent, y);  
    //if(x_par != y_par) 
    //{  
        parent[x] = y;  
    //}  
}

bool sort_weight(Edge a, Edge b)
{
	return a.weight < b.weight;
}

bool sort_order(Edge a, Edge b)
{
	return a.source < b.source;
}

void swap(Edge &x) 
{ 
	int temp;
    temp = x.source;
    x.source = x.dest;
    x.dest = temp;
}

void Kruskal()
{
	int** array = edges();

	Edge* input = new Edge[100];

	int* parent = new int[10];

	int count = 0;

	for(int i = 0; i < 10; i++)
	{
		parent[i] = i;
	}

	int k = 0;

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			input[k].source = i+1;
			input[k].dest = j+1;
			input[k].weight = array[i][j];

			//cout << input[k].source << " " << input[k].dest << " " << input[k].weight << endl;

			k++;
		}
		//cout << endl;
	}
	
	sort(input, input + 100, sort_weight);

	Edge current_Edge;
	int src_parent;
	int dest_parent;
	Edge* output = new Edge[10];

	for(int i = 0; i < 100; i++)
	{
		current_Edge = input[i];

		src_parent = find(parent, current_Edge.source);
		dest_parent = find(parent, current_Edge.dest);

		if(src_parent != dest_parent)
		{
			unite(parent, src_parent, dest_parent);

			output[count] = current_Edge;
			count++;
		}
	}

	for(int k = 0; k < count; k++)
	{
		if(output[k].source > output[k].dest)
		{
			swap(output[k]);
		}
	}

	sort(output, output + count, sort_order);

	
	ofstream outfile;	
	outfile.open("output.txt");

	outfile << "The total number of edges: " << count << endl;

	cout << count << endl;

	for(int k = 0; k < count; k++)
	{
		cout << output[k].source << " " << output[k].dest << " " << output[k].weight << endl;

		outfile << output[k].source << " " << output[k].dest << endl;
		
	}

	outfile.close();

	delete[] output;
	
}    

int main()
{

	Kruskal();

		
}
