#include <stdio.h>

#define ARR_MAX		10
#define NODE_MAX	3

int arr[ARR_MAX][ARR_MAX];
int deg[ARR_MAX][ARR_MAX];

typedef struct
{
	int x;
	int y;
} IDX;

typedef struct
{
	IDX idx;
	IDX innerVecA;
	int innerVecADist;
	IDX innerVecB;
	int innerVecBDist;
} NODE;

int square_dist(int ax, int ay, int bx, int by)
{
	return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

bool outage_condition(int i, int j)
{
	return (i == -1 || i == ARR_MAX || j ==-1 || j == ARR_MAX);
}

inline void cache_deg(int i, int j)
{
	if(arr[i][j] == 0) return;

	for(int a=i-1;a<=i+1;++a)
	{
		for(int b=j-1;b<=j+1;++b)
		{
			if(a==i && b == j) continue;
			if(outage_condition(a, b)) continue;
			++deg[a][b];
		}
	}
}

bool _node_condition(int i, int j)
{
	if(!outage_condition(i-1, j) && !outage_condition(i+1, j))
	{
		if(arr[i-1][j] == 1 && arr[i+1][j]) return false;
	}

	if(!outage_condition(i, j-1) && !outage_condition(i, j+1))
	{
		if(arr[i][j-1] == 1 && arr[i][j+1]) return false;
	}

	return true;
}

bool _ext_cross_product(IDX a, IDX b, IDX c, IDX d)
{
	// vector ab
	IDX vecAB = {b.x - a.x, b.y - a.y};
	// vector ac
	IDX vecAC = {c.x - a.x, c.y - a.y};
	// vector ad
	IDX vecAD = {d.x - a.x, d.y - a.y};

	int ext_AB2AC = vecAB.x * vecAC.y - vecAB.y * vecAC.x;
	int ext_AB2AD = vecAB.x * vecAD.y - vecAB.y * vecAD.x;

	// parallel vector
	if(ext_AB2AD == 0)
	{
		return true;
	}

	return (ext_AB2AC * ext_AB2AD > 0);
}

int main()
{
	int nodeCnt = 0;
	NODE node[NODE_MAX];
	// Get input
	for(int i=0;i<ARR_MAX;++i)
	{
		for(int j=0;j<ARR_MAX;++j)
		{
			scanf("%1d", &arr[i][j]);
			cache_deg(i, j);
		}
	}

	// Get nodes
	for(int i=0;i<ARR_MAX;++i)
	{
		for(int j=0;j<ARR_MAX;++j)
		{
			if(arr[i][j] == 0) continue;

			if(deg[i][j] <= 3 && _node_condition(i,j))
			{
				if(nodeCnt + 1 > NODE_MAX)
				{
					return printf("0\n")*0;
				}
				node[nodeCnt].idx = {i, j};
				++nodeCnt;
			}
		}
	}
	if(nodeCnt != NODE_MAX)
	{
		return printf("0\n")*0;
	}

	// Process #1
	bool flag = false;
	for(int i=0;i<NODE_MAX;++i)
	{
		NODE* tA = &node[(i+1)%NODE_MAX];
		NODE* tB = &node[(i+2)%NODE_MAX];
		node[i].innerVecA = {(tA->idx.x - node[i].idx.x), (tA->idx.y - node[i].idx.y)};
		node[i].innerVecB = {(tB->idx.x - node[i].idx.x), (tB->idx.y - node[i].idx.y)};
		node[i].innerVecADist = square_dist(0, 0, node[i].innerVecA.x, node[i].innerVecA.y);
		node[i].innerVecBDist = square_dist(0, 0, node[i].innerVecB.x, node[i].innerVecB.y);

		// inner cross product
		if((node[i].innerVecA.x)*(node[i].innerVecB.x) + (node[i].innerVecA.y)*(node[i].innerVecB.y) == 0)
		{
			// square distance
			if(node[i].innerVecADist == node[i].innerVecBDist)
			{
				flag = true;
			}
		}
	}

	if(flag == false)
	{
		return printf("0\n")*0;
	}

	// Process #2
	for(int i=0;i<ARR_MAX;++i)
	{
		for(int j=0;j<ARR_MAX;++j)
		{
			if
			(
				_ext_cross_product(node[0].idx, node[1].idx, node[2].idx, {i, j}) &&
				_ext_cross_product(node[1].idx, node[2].idx, node[0].idx, {i, j}) &&
				_ext_cross_product(node[2].idx, node[0].idx, node[1].idx, {i, j})
			)
			{
				if(arr[i][j] == 0) return printf("0\n")*0;
				else continue;
			}
			else
			{
				if(arr[i][j] == 0) continue;
				else return printf("0\n")*0;
			}
		}
	}

	// Print output
	for(int i=0;i<NODE_MAX;++i)
	{
		printf("%d %d\n", node[i].idx.x + 1, node[i].idx.y + 1);
	}


	return 0;
}
