#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <Windows.h>
#include <cmath>
using namespace std;

vector<vector<int>> adjacencyMatrix = {{0, 10, 13, 18, 20, 19, 13, 8, 7, 18, 13, 12, 11, 9, 4, 6, 5, 18, 9, 22, 15, 999, 999, 15, 12},
									   {10, 0, 5, 18, 15, 20, 18, 10, 4, 8, 5, 3, 7, 5, 9, 9, 10, 4, 999, 22, 5, 20, 30, 999, 7},
									   {13, 5, 0, 12, 10, 18, 15, 8, 4, 11, 6, 6, 6, 14, 15, 16, 16, 9, 28, 20, 4, 18, 25, 25, 10},
									   {18, 18, 12, 0, 7, 6, 3, 5, 11, 23, 999, 21, 15, 3, 14, 15, 12, 16, 30, 6, 15, 10, 8, 30, 12},
									   {20, 15, 10, 7, 0, 14, 10, 8, 12, 24, 999, 15, 16, 15, 19, 20, 19, 7, 25, 10, 16, 5, 10, 999, 16},
									   {19, 20, 18, 6, 10, 0, 3, 8, 18, 30, 999, 999, 20, 16, 15, 22, 20, 25, 30, 7, 26, 10, 4, 30, 15},
									   {13, 18, 15, 3, 10, 2, 0, 5, 15, 21, 25, 19, 10, 10, 14, 20, 18, 20, 30, 5, 26, 14, 14, 35, 15},
									   {8, 10, 8, 4, 5, 10, 8, 0, 9, 25, 20, 15, 3, 3, 14, 16, 12, 16, 20, 10, 15, 10, 14, 30, 10},
									   {7, 4, 4, 11, 12, 18, 15, 9, 0, 13, 14, 9, 5, 5, 12, 9, 10, 18, 30, 21, 9, 30, 20, 25, 4},
									   {18, 8, 11, 23, 24, 30, 21, 25, 13, 0, 7, 9, 999, 999, 21, 20, 20, 19, 35, 34, 5, 30, 999, 32, 21},
									   {13, 5, 6, 999, 999, 999, 25, 20, 14, 7, 0, 5, 21, 18, 19, 18, 18, 21, 23, 20, 4, 19, 18, 26, 10},
									   {12, 3, 6, 21, 15, 999, 19, 15, 9, 9, 5, 0, 16, 15, 19, 19, 15, 14, 27, 20, 6, 29, 31, 35, 15},
									   {11, 7, 6, 15, 16, 20, 10, 3, 5, 999, 21, 16, 0, 6, 16, 15, 8, 12, 24, 18, 10, 16, 20, 30, 9},
									   {9, 5, 14, 3, 15, 16, 10, 3, 5, 999, 18, 15, 6, 0, 7, 12, 7, 19, 9, 18, 40, 25, 31, 34, 10},
									   {4, 9, 15, 14, 19, 15, 14, 14, 12, 21, 19, 19, 16, 7, 0, 10, 7, 26, 23, 19, 21, 22, 29, 30, 15},
									   {6, 9, 16, 15, 20, 22, 20, 16, 9, 20, 18, 19, 15, 12, 10, 0, 6, 19, 15, 23, 19, 29, 34, 26, 6},
									   {5, 10, 16, 12, 19, 20, 18, 12, 10, 20, 18, 15, 8, 7, 7, 6, 0, 21, 19, 20, 15, 22, 26, 20, 9},
									   {18, 4, 9, 16, 7, 25, 20, 16, 18, 19, 21, 14, 12, 19, 26, 19, 21, 0, 999, 25, 16, 18, 21, 40, 22},
									   {9, 999, 28, 30, 25, 30, 30, 20, 13, 35, 23, 27, 24, 29, 23, 15, 19, 999, 0, 35, 16, 30, 31, 5, 16},
									   {22, 22, 20, 6, 10, 7, 5, 10, 21, 34, 20, 20, 18, 18, 19, 23, 20, 25, 35, 0, 26, 6, 10, 26, 10},
									   {15, 5, 4, 15, 16, 26, 26, 15, 9, 5, 4, 6, 10, 14, 21, 19, 15, 16, 16, 26, 0, 29, 31, 26, 9},
									   {999, 20, 18, 10, 5, 10, 14, 10, 13, 30, 19, 29, 16, 25, 22, 29, 22, 18, 30, 6, 29, 0, 5, 40, 20},
									   {999, 30, 25, 8, 10, 4, 14, 14, 20, 999, 18, 31, 20, 31, 29, 34, 26, 21, 31, 10, 31, 5, 0, 999, 30},
									   {15, 999, 25, 30, 999, 30, 35, 30, 25, 32, 26, 35, 30, 34, 30, 26, 20, 40, 5, 26, 26, 40, 999, 0, 25},
									   {12, 7, 10, 12, 16, 15, 15, 10, 4, 21, 10, 15, 9, 10, 15, 6, 6, 22, 16, 10, 9, 20, 30, 25, 0}};

// 1 Kolkata	// 2 New Delhi   		// 3 Jaipur					// 4 Hyderabad	// 5 Mumbai
// 6 Chennai	// 7 Vijaywada		// 8 Nagpur 				// 9 Lucknow 	// 10 Srinagar
// 11 Shimla	// 12 Chandigarh	// 13 Bhopal				// 14 Raipur	// 15 Bhubneshwar
// 16 Patna		// 18 Ranchi		// 18 Gandhinagar			// 19 Dispur	// 20 Bengaluru
// 21 Dehra Dun	// 22 Panaji		// 23 Thiruvananthapuram	// 24 Itanagar	// 25 Prayagraj

map<int, string> m{{1, "Kolkata"}, {2, "New Delhi"}, {3, "Jaipur"}, {4, "Hyderabad"}, {5, "Mumbai"}, {6, "Chennai"}, {7, "Vijaywada"}, {8, "Nagpur"}, {9, "Lucknow"}, {10, "Srinagar"}, {11, "Shimla"}, {12, "Chandigarh"}, {13, "Bhopal"}, {14, "Raipur"}, {15, "Bhubneshwar"}, {16, "Patna"}, {17, "Ranchi"}, {18, "Gandhinagar"}, {19, "Dispur"}, {20, "Bengaluru"}, {21, "Dehra Dun"}, {22, "Panaji"}, {23, "Thiruvananthapuram"}, {24, "Itanagar"}, {25, "Prayagraj"}};
int NO_PARENT = -1;

map<int, pair<int, int>> points{{1, {138, 51}}, {2, {70, 33}}, {3, {62, 38}}, {4, {79, 66}}, {5, {47, 60}}, {6, {88, 75}}, {7, {97, 68}}, {8, {81, 56}},{9,{88,39}},{10,{62,15}},{11,{62,15}},{12,{64,25}},{13,{75,48}},{14,{102,55}},{15,{126,57}},{16,{119,42}},{17,{117,49}},{18,{34,48}},{19,{162,41}},{20,{69,76}},{21,{76,27}},{22,{57,72}},{23,{70,85}},{24,{180,37}},{25,{97,43}}};

void CoutCentered(string text, int x, int endll)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);							 // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);							 // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize;										 // Gets the size of the screen
	if (NewSBSize.X > text.size())
	{
		int newpos = ((NewSBSize.X - text.size() + x) / 2); // Calculate the number of spaces to center the specific text.
		for (int i = 0; i < newpos; i++)
			cout << " "; // Prints the spaces
	}
	if (endll)
		cout << text << endl; // Prints the text centered :]
	else
		cout << text;
}

void CoutCenteredXY(string text, int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);							 // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);							 // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize;										 // Gets the size of the screen
	int ypos = NewSBSize.Y;
	ypos /= 2;
	ypos += y;
	for (int i = 0; i < ypos; i++)
		cout << endl;
	if (NewSBSize.X > text.size())
	{
		int newpos = ((NewSBSize.X - text.size() + x) / 2); // Calculate the number of spaces to center the specific text.
		for (int i = 0; i < newpos; i++)
			cout << " "; // Prints the spaces
	}

	cout << text << endl; // Prints the text centered :]
}
bool quadrant(int x1, int y1, int x2, int y2)
{
	int q;
	if (x2 > x1 and y2 > y1)
		q = 1;
	else if (x2 < x1 and y2 > y1)
		q = 4;
	else if (x2 < x1 and y2 < y1)
		q = 3;
	else if (x2 > x1 and y2 < y1)
		q = 2;
	// cout << q << "    fvxf" << endl;
	if (q == 1 or q == 3)
		return true;
	else
		return false;
}
void printPathInMap(vector<int> pts)
{
	fstream newfile;
	newfile.open("map.txt", ios::in);
	string tp[93];
	int i = 0;
	while (getline(newfile, tp[i]))
	{
		i++;
	}

	int x1 = 138, y1 = 51, x2 = 70, y2 = 33, m = 0;
	for (int i = 0; i < pts.size() - 1; i++)
	{
		int p1 = pts[i], p2 = pts[i + 1];
		for (auto i : points)
		{
			if (i.first == p1)
			{
				x1 = i.second.first;
				y1 = i.second.second;
			}
			if (i.first == p2)
			{
				x2 = i.second.first;
				y2 = i.second.second;
			}
		}
		// cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		if (abs(x2 - x1) <= 2)
		{
			i = 1;
			int x = x1 < x2 ? x1 : x2;
			int xmax = x1 > x2 ? x1 : x2;
			int y = y1 < y2 ? y1 : y2;
			int ymax = y1 > y2 ? y1 : y2;
			while (i <= 93)
			{
				if (i >= y and i <= ymax)
				{
					if (tp[i - 1][x] == ' ')
						tp[i - 1][x] = '*';
				}
				// cout << tp << endl;
				i++;
			}
		}
		if (abs(y2 - y1) <= 2)
		{
			int x = x1 < x2 ? x1 : x2;
			int xmax = x1 > x2 ? x1 : x2;
			int y = y1 < y2 ? y1 : y2;
			i = 1;
			// cout<<"sdfasdf"<<endl;
			int ymax = y1 > y2 ? y1 : y2;
			while (i <= 93)
			{
				if (i == y)
				{
					for (int j = x; j <= xmax; j++)
					{
						if (tp[i - 1][j] == ' ')
							tp[i - 1][j] = '*';
					}
				}
				// cout << tp << endl;
				i++;
			}
		}
		bool flag = quadrant(x1, y1, x2, y2);
		// cout << flag << endl;
		if (!flag)
		{
			int temp = y1;
			y1 = y2;
			y2 = temp;

			int x = 1, y = 0;
			if (x1 > x2)
			{
				x = x1;
			}
			else
			{
				x = x2;
			}
			if (x1 < x2)
			{
				int temp = x1;
				x1 = x2;
				x2 = temp;
			}
			if (y1 > y2)
			{
				int temp = y1;
				y1 = y2;
				y2 = temp;
			}
			int d1 = abs(x2 - x1);
			int d2 = abs(y2 - y1);
			// cout<<d1<<d2<<endl;
			if (d1 > d2)
				m = round((double)d1 / d2);
			else
				m = round((double)d2 / d1);
			// cout << m << endl;
			while (y < 93)
			{
				if (x >= x2 and y >= y1 and y <= y2)
				{
					x -= m;
					if (tp[y][x] == ' ')
						tp[y][x] = '*';
					// cout<<x<<" "<<y<<endl;
				}
				y++;
			}
		}
		else
		{

			int x = 0, y = 0;
			int d1 = abs(x2 - x1);
			int d2 = abs(y2 - y1);
			if (d1 > d2)
				m = round((double)d1 / d2);
			else
				m = round((double)d2 / d1);
			// cout << m << endl;
			int xc = (x1 < x2) ? x1 : x2;
			if (y1 > y2)
			{
				int temp = y1;
				y1 = y2;
				y2 = temp;
			}
			while (y < 93)
			{
				if (x <= (abs(x2 - x1)) and y >= y1 and y <= y2)
				{
					x += m;
					if (tp[y][x + xc] == ' ')
						tp[y][x + xc] = '*';
					// cout<<x<<" "<<y<<endl;
				}
				// cout << tp << "\n";
				y++;
			}
		}
	}
	for (int i = 0; i < 94; i++)
	{
		CoutCentered(tp[i], 0, 1);
	}
	// delete[] tp;
	// in
	newfile.close();
}

string path;
vector<int> pt;
void printPath(int currentVertex, vector<int> parents)
{
	if (currentVertex == NO_PARENT)
	{
		return;
	}
	printPath(parents[currentVertex], parents);
	path += '(';
	path += to_string(currentVertex + 1);
	pt.push_back(currentVertex + 1);
	path += ')';
	path += m[currentVertex + 1];
	path += " -> ";
}

void printSolution(int startVertex, int endvertex, vector<int> distances, vector<int> parents)
{
	int nVertices = distances.size();
	cout<<endl<<endl;
	CoutCentered("Google Maps", 0, 0);
	cout << endl
		 << endl;
	CoutCentered("Originating City       Destination City       Distance  \t\t     Path", 0, -10);
	for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
	{
		if (vertexIndex == endvertex)
		{
			string s = "";
			s += '(';
			s += to_string(startVertex + 1);
			s += ')';
			s += m[startVertex + 1];
			s += "\t\t";
			s += '(';
			s += to_string(vertexIndex + 1);
			s += ')';
			s += m[(vertexIndex + 1)];
			s += "\t\t";
			s += to_string(distances[vertexIndex] * 100);
			s += " Km";
			cout << endl;
			CoutCentered(s, -28, 0);
			printPath(vertexIndex, parents);
			path=path.substr(0,path.length()-4);
			cout << "  " << path << endl;
			printPathInMap(pt);
			path.clear();
			pt.clear();
		}
	}
}

void dijkstra(vector<vector<int>> adjacencyMatrix, int startVertex, int endvertex)
{
	int nVertices = adjacencyMatrix[0].size();
	vector<int> shortestDistances(nVertices);
	vector<bool> added(nVertices);
	for (int vertexIndex = 0; vertexIndex < nVertices;
		 vertexIndex++)
	{
		shortestDistances[vertexIndex] = INT_MAX;
		added[vertexIndex] = false;
	}
	shortestDistances[startVertex] = 0;
	vector<int> parents(nVertices);
	parents[startVertex] = NO_PARENT;
	for (int i = 1; i < nVertices; i++)
	{
		int nearestVertex = -1;
		int shortestDistance = INT_MAX;
		for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
		{
			if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance)
			{
				nearestVertex = vertexIndex;
				shortestDistance = shortestDistances[vertexIndex];
			}
		}
		added[nearestVertex] = true;
		for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
		{
			int edgeDistance = adjacencyMatrix[nearestVertex][vertexIndex];
			if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex]))
			{
				parents[vertexIndex] = nearestVertex;
				shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
			}
		}
	}
	printSolution(startVertex, endvertex, shortestDistances, parents);
}

int city(string str)
{
	bool flag = true;
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			flag = false;
		}
	}
	if (flag)
	{
		int a = stoi(str);
		if (a > 0 and a < 26)
		{
			return a - 1;
		}
	}
	else
	{
		for (auto i : m)
		{
			if (i.second == str)
			{
				return i.first - 1;
			}
		}
	}
	return -1;
}

void capitalize(string &s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (i == 0)
		{
			s[i] = toupper(s[i]);
		}
		else
		{
			s[i] = tolower(s[i]);
		}
		if (s[i] == ' ')
		{
			s[i + 1] = toupper(s[i + 1]);
			i++;
		}
	}
}

void GoogleLogo()
{
	ifstream file;
	file.open("Logo.txt");
	if (!file.is_open())
	{
		cout << "Unable to open the file." << endl;
		return;
	}
	string line;
	while (getline(file, line))
	{
		CoutCentered(line, 0, 1);
	}
	file.close();
}
void Animate()
{
	string line;
	cout << endl
		 << endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);							 // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);							 // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize;
	int i = 0, t = 0, d = (NewSBSize.X / 40);
	string str = "[";
	// str[0]='[';
	int j = 1;
	while (i < 40 + 1)
	{
		// string str(NewSBSize.X, ' ');
		t += d;
		for (int k = j; k < j + d; k++)
		{
			str += '#';
		}
		// j+=d;
		const char *prompt = str.c_str();
		printf("\r%*s\r%s]", sizeof(prompt) - 1, "", prompt);
		fflush(stdout);
		Sleep(50);
		i++;
	}
}
void IndiaMap()
{
	ifstream file;
	file.open("map.txt");
	if (!file.is_open())
	{
		cout << "Unable to open the file." << endl;
		return;
	}
	string line;
	while (getline(file, line))
	{
		CoutCentered(line, 0, 1);
	}
	file.close();
}

void loading(int n, int dots) // n is the number of times the animation will run, dots is the number of dots to be printed in the end.
{
	const int trigger = 500; // ms
	int numDots = dots;
	string str;
	const char *prompt = str.c_str();
	int k = 0;
	while (k < n)
	{
		// Return and clear with spaces, then return and print prompt.
		// CoutCentered("", n+dots);
		printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
		fflush(stdout);

		// Print numDots number of dots, one every trigger milliseconds.
		for (int i = 0; i < numDots; i++)
		{
			Sleep(trigger);
			fputc('.', stdout);

			fflush(stdout);
		}
		k++;
	}
}

int main()
{
	GoogleLogo();
	string s;
	cout<<endl;
	CoutCentered("Press Enter to continue", 0, 0);
	cin.ignore();
	system("cls");
	GoogleLogo();
	Animate();
	system("cls");
	while (true)
	{
		IndiaMap();
		string a, b;
		fflush(stdin);
		CoutCentered("Enter the Source City (Name or code) :", 10, 0);
		getline(cin, a);
		capitalize(a);
		CoutCentered("Enter the Destination City (Name or Code) :", 10, 0);
		getline(cin, b);
		capitalize(b);
		int c = city(a);
		int d = city(b);
		if (c == -1 or d == -1)
		{
			cout << "Invalid Input" << endl;
			system("cls");
			continue;
		}
		system("cls");
		cout << endl
			 << endl;
		;
		CoutCenteredXY("Please a while, we are calculating the shortest path for you....", 0, -20);
		cout << endl
			 << endl;
		Animate();
		system("cls");
		dijkstra(adjacencyMatrix, c, d);
		char e;
		cout << endl;
		CoutCentered("Enter X to Exit or any other key to continue...", 0, 0);
		cin >> e;
		fflush(stdin);
		system("cls");
		if (e == 'X' or e == 'x')
			break;
		CoutCenteredXY("Reloading Application...", 0, -20);
		Animate();
		system("cls");
	}
	return 0;
}