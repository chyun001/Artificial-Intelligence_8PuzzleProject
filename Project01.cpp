#include <iostream>
#include <vector>
using namespace std;

//Stores the Puzzle in a Node class which contains g(n) and h(n)
class Node 
{
public:
	vector<int> Puzzle;
	int Gn = 1;
	int Hn = 0;
};

//Returns the goal state of the puzzle
vector<int> ReturnPuzzleGoal()
{
	vector<int> Puzzle;
	Puzzle.push_back(1);
	Puzzle.push_back(2);
	Puzzle.push_back(3);
	Puzzle.push_back(4);
	Puzzle.push_back(5);
	Puzzle.push_back(6);
	Puzzle.push_back(7);
	Puzzle.push_back(8);
	Puzzle.push_back(0);

	return Puzzle;
}

//Displays the puzzle on screen
void DisplayPuzzle(vector<int> Puzzle)
{
	cout << Puzzle.at(0) << " " << Puzzle.at(1) << " " << Puzzle.at(2)  << endl;
	cout << Puzzle.at(3) << " " << Puzzle.at(4) << " " << Puzzle.at(5)  << endl;
	cout << Puzzle.at(6) << " " << Puzzle.at(7) << " " << Puzzle.at(8)  << endl;
	cout << endl;
}

//Sorts the unvisited nodes in the vector least to greatest using g(n) + h(n)
void SortNodes(vector<Node*> Puzzle)
{
	for(int i = 0; i < Puzzle.size(); ++i)
	{
		for(int j = i + 1; j < Puzzle.size(); ++j)
		{
			if(Puzzle.at(i)->Gn + Puzzle.at(i)->Hn > Puzzle.at(j)->Gn + Puzzle.at(j)->Hn)
			{
				vector<int> HoldPuzzle = Puzzle.at(i)->Puzzle;
				int Gn = Puzzle.at(i)->Gn;
				int Hn = Puzzle.at(i)->Hn;
				
				Puzzle.at(i)->Puzzle = Puzzle.at(j)->Puzzle;
				Puzzle.at(i)->Gn = Puzzle.at(j)->Gn;
				Puzzle.at(i)->Hn = Puzzle.at(j)->Hn;
				
				Puzzle.at(j)->Puzzle = HoldPuzzle;
				Puzzle.at(j)->Hn = Hn;
				Puzzle.at(j)->Gn = Gn;
			}
		}
	}
}

//Returns the blank index
int ReturnBlankLocation(vector<int> Puzzle)
{
	for (int i = 0; i < Puzzle.size(); ++i)
	{
		if (Puzzle.at(i) == 0)
			return i;
	}
	return NULL;
}

//Returns the number index
int ReturnNumberLocation(vector<int> Puzzle, int Number)
{
	for (int i = 0; i < Puzzle.size(); ++i)
	{
		if (Puzzle.at(i) == Number)
			return i;
	}
	return NULL;
}

//Checks to see if the node is in the visited vector
bool AlreadyVisitedNode(Node Up, vector<Node*> NodesVisited)
{
	for(int i = 0; i < NodesVisited.size(); ++i)
	{
		if(Up.Puzzle == NodesVisited.at(i)->Puzzle)
			return true;
	}
	return false;
}

//Calculates the heuristic using "Misplaced Tile."
int MisplacedTile(vector<int> Puzzle)
{
	int Heuristic = 0;
	for(int i = 0; i < Puzzle.size() - 1; ++i)
	{
		if(Puzzle.at(i) != i + 1)
			Heuristic += 1;
	}
	return Heuristic;
}

//Calculates the heuristic using "ManhattanDistance."
int ManhattanDistance (vector<int> Puzzle)
{
	int Heuristic = 0;
	
	//Moving 1 to correct position assuming there are no obstacles
	int Number01 = ReturnNumberLocation(Puzzle, 1);
	if(Number01 != 0)
	{
		if(Number01 > 5)
		{
			Heuristic += 1;
			Number01 -= 3;
		}
		if(Number01 > 2)
		{
			Heuristic += 1;
			Number01 -= 3;
		}
		while(Number01 > 0)
		{
			Heuristic += 1;
			Number01 -= 1;
		}
		
	}
	//Moving 2 to correct position assuming there are no obstacles
	int Number02 = ReturnNumberLocation(Puzzle, 2);
	if(Number02 != 1)
	{
		if(Number02 > 5)
		{
			Heuristic += 1;
			Number02 -= 3;
		}
		if(Number02 > 2)
		{
			Heuristic += 1;
			Number02 -= 3;
		}
		if(Number02 == 0)
		{
			Heuristic += 1;
			Number02 += 1;
		}
		if(Number02 == 2)
		{
			Heuristic += 1;
			Number02 -= 1;
		}
	}
	//Moving 3 to correct position assuming there are no obstacles
	int Number03 = ReturnNumberLocation(Puzzle, 3);
	if(Number03 != 2)
	{
		if(Number03 > 5)
		{
			Heuristic += 1;
			Number03 -= 3;
		}
		if(Number03 > 2)
		{
			Heuristic += 1;
			Number03 -= 3;
		}
		while(Number03 < 2)
		{
			Heuristic += 1;
			Number03 += 1;
		}
	}
	//Moving 4 to correct position assuming there are no obstacles
	int Number04 = ReturnNumberLocation(Puzzle, 4);
	if(Number04 != 3)
	{
		if(Number04 > 5)
		{
			Heuristic += 1;
			Number04 -= 3;
		}
		else if(Number04 < 3)
		{
			Heuristic += 1;
			Number04 += 3;
		}
		while(Number01 > 3)
		{
			Heuristic += 1;
			Number04 -= 1;
		}
		
	}
	//Moving 5 to correct position assuming there are no obstacles
	int Number05 = ReturnNumberLocation(Puzzle, 5);
	if(Number05 != 4)
	{
		if(Number05 > 5)
		{
			Heuristic += 1;
			Number05 -= 3;
		}
		else if(Number05 < 3)
		{
			Heuristic += 1;
			Number05 += 3;
		}
		if(Number05 == 3)
		{
			Heuristic += 1;
			Number05 += 1;
		}
		if(Number05 == 5)
		{
			Heuristic += 1;
			Number05 -= 1;
		}
		
	}
	//Moving 6 to correct position assuming there are no obstacles
	int Number06 = ReturnNumberLocation(Puzzle, 6);
	if(Number06 != 5)
	{
		if(Number06 > 5)
		{
			Heuristic += 1;
			Number06 -= 3;
		}
		else if(Number06 < 3)
		{
			Heuristic += 1;
			Number06 += 3;
		}
		while(Number06 < 5)
		{
			Heuristic += 1;
			Number06 += 1;
		}
		
	}
	//Moving 7 to correct position assuming there are no obstacles
	int Number07 = ReturnNumberLocation(Puzzle, 7);
	if(Number07 != 6)
	{
		if(Number07 < 3)
		{
			Heuristic += 1;
			Number07 += 3;
		}
		if(Number07 < 6)
		{
			Heuristic += 1;
			Number07 += 3;
		}
		while(Number07 > 6)
		{
			Heuristic += 1;
			Number07 -= 1;
		}
		
	}
	//Moving 8 to correct position assuming there are no obstacles
	int Number08 = ReturnNumberLocation(Puzzle, 8);
	if(Number08 != 7)
	{
		if(Number08 < 3)
		{
			Heuristic += 1;
			Number08 += 3;
		}
		if(Number08 < 6)
		{
			Heuristic += 1;
			Number08 += 3;
		}
		if(Number08 == 6)
		{
			Heuristic += 1;
			Number08 += 1;
		}
		if(Number08 == 8)
		{
			Heuristic += 1;
			Number08 -= 1;
		}
	}
	return Heuristic;
}

//Checks to see if the blank piece (0) can be moved up
bool MoveUpCheck(vector<int> Puzzle)
{
	if (ReturnBlankLocation(Puzzle) > 2)
		return true;
	else
		return false;
}
//Checks to see if the blank piece (0) can be moved down
bool MoveDownCheck(vector<int> Puzzle)
{
	if (ReturnBlankLocation(Puzzle) < 6)
		return true;
	else
		return false;
}
//Checks to see if the blank piece (0) can be moved left
bool MoveLeftCheck(vector<int> Puzzle)
{
	int index = ReturnBlankLocation(Puzzle);
	if (index != 0 && index != 3 && index != 6)
		return true;
	else
		return false;
}
//Checks to see if the blank piece (0) can be moved right
bool MoveRightCheck(vector<int> Puzzle)
{
	int index = ReturnBlankLocation(Puzzle);
	if (index != 2 && index != 5 && index != 8)
		return true;
	else
		return false;
}
//Swaps the position of two pieces in the puzzle
vector<int> Swap(vector<int> Puzzle, int Position)
{
	int HoldNumber = Puzzle.at(Position);
	Puzzle.at(ReturnBlankLocation(Puzzle)) = HoldNumber;
	Puzzle.at(Position) = 0;
	return Puzzle;
}
//Moves the blank piece up and returns the new puzzle
Node MoveUp(Node NewPuzzle)
{
	Node * MovedNode = new Node;
	MovedNode->Puzzle = Swap(NewPuzzle.Puzzle, ReturnBlankLocation(NewPuzzle.Puzzle) - 3);
	return * MovedNode;
}
//Moves the blank piece down and returns the new puzzle
Node MoveDown(Node NewPuzzle)
{
	Node * MovedNode = new Node;
	MovedNode->Puzzle = Swap(NewPuzzle.Puzzle, ReturnBlankLocation(NewPuzzle.Puzzle) + 3);
	return * MovedNode;
}
//Moves the blank piece left and returns the new puzzle
Node MoveLeft(Node NewPuzzle)
{
	Node * MovedNode = new Node;
	MovedNode->Puzzle = Swap(NewPuzzle.Puzzle, ReturnBlankLocation(NewPuzzle.Puzzle) - 1);
	return * MovedNode;
}
//Moves the blank piece right and returns the new puzzle
Node MoveRight(Node NewPuzzle)
{
	Node * MovedNode = new Node;
	MovedNode->Puzzle = Swap(NewPuzzle.Puzzle, ReturnBlankLocation(NewPuzzle.Puzzle) + 1);
	return * MovedNode;
}

//Contains UCS and A* algorithm
Node Search(vector<int> Puzzle, vector<int> Puzzle_Goal, int AlgorithmChoice)
{
	//Variables used to keep track of the state of the expansion
	int ExpandedNodes = 0;
	int MaximumNodes = 0;
	int MaximumDepth = 0;
	bool Expanded = false;
	
	//NodeVector keeps track of the cost of each node while NodeVisited stores the Nodes visited
	vector<Node*> NodeVector;
	vector<Node*> NodeVisited;

	//Takes the initial puzzle and converts it to a node
	Node * InitialNode = new Node;
	InitialNode->Puzzle = Puzzle;
	InitialNode->Gn = 0;

	//Push the inital node/puzzle onto NodeVector
	NodeVector.push_back(InitialNode);
	MaximumNodes = NodeVector.size();

	//Displays the initial state to be expanded
	cout << "Expanding State" << endl;
	cout << "----------------" << endl;
	DisplayPuzzle(InitialNode->Puzzle);

	while(1)
	{
		//Stores the size of the node vector (Used to keep track)
		if(MaximumNodes < NodeVector.size())
			MaximumNodes = NodeVector.size();
			
		//Checks to see if NodeVector is empty
		if (NodeVector.empty())
		{
			cout << "Failure!" << endl;
			break; //return a failure node
		}
		
		//Hold the lowest cost node to be expanded
		Node HoldTopNode = *NodeVector.front();
		NodeVisited.push_back(NodeVector.front());

		//Pop the front of the vector
		NodeVector.erase(NodeVector.begin());
		
		//Stores the maximum depth (Used to keep track)
		if(MaximumDepth < HoldTopNode.Gn)
			MaximumDepth = HoldTopNode.Gn;

		
		//If the current held node is goal, return that node
		if (HoldTopNode.Puzzle == Puzzle_Goal)
		{
			cout << "Goal!" << endl;
			cout << "---------" << endl;
			DisplayPuzzle(HoldTopNode.Puzzle);
			cout << "To solve this problem the search algorithm expanded a";
			cout << " total of ";
			cout << ExpandedNodes;
			cout << " nodes." << endl;
			
			cout << "The maximum number of nodes in the vector at any one time"; 
			cout << " was ";
			cout << MaximumNodes;
			cout << "." << endl;
			
			cout << "The depth of the goal node was "; 
			cout << MaximumDepth;
			cout << "." << endl;
			
			return HoldTopNode;
			//break;
		}

		//Displays the puzzle with the cost and heuristic
		if(AlgorithmChoice == 1 && HoldTopNode.Gn != 0)
		{
			cout << "Expanding node with g(n) = " << HoldTopNode.Gn << endl;
			cout << "----------------------------" << endl;
			DisplayPuzzle(HoldTopNode.Puzzle);
		}
		else if((AlgorithmChoice == 2 || AlgorithmChoice == 3) && HoldTopNode.Gn != 0)
		{
			cout << "Expanding node below with g(n) = " << HoldTopNode.Gn;
			cout << " and h(n) = " << HoldTopNode.Hn << endl;
			cout << "---------------------------------------------------" << endl;
			DisplayPuzzle(HoldTopNode.Puzzle);
		}
		
		//Four Operators -> Up, Down, Left, Right
		if(MoveUpCheck(HoldTopNode.Puzzle) == true)
		{
			Node * HoldUp = new Node;
			*HoldUp = MoveUp(HoldTopNode); //Perform up swap and store the new puzzle
			if(AlgorithmChoice == 1)
				HoldUp->Gn = HoldTopNode.Gn + 1; //Incrememnt the cost by one
			if(AlgorithmChoice == 2)
				HoldUp->Hn = MisplacedTile(HoldUp->Puzzle);
			if(AlgorithmChoice == 3)
				HoldUp->Hn = ManhattanDistance(HoldUp->Puzzle);
			if(AlreadyVisitedNode(*HoldUp, NodeVisited) == false) //If not in visited, push onto NodeVector
			{
				NodeVector.push_back(HoldUp);
				if(AlgorithmChoice == 2 || AlgorithmChoice == 3)	
					HoldUp->Gn = HoldTopNode.Gn + 1;
				Expanded = true; //Parent node was expanded
			}
		}
		if(MoveDownCheck(HoldTopNode.Puzzle) == true)
		{
			Node * HoldDown = new Node;
			*HoldDown = MoveDown(HoldTopNode);
			if(AlgorithmChoice == 1)
				HoldDown->Gn = HoldTopNode.Gn + 1;
			if(AlgorithmChoice == 2)
				HoldDown->Hn = MisplacedTile(HoldDown->Puzzle);
			if(AlgorithmChoice == 3)
				HoldDown->Hn = ManhattanDistance(HoldDown->Puzzle);
			if(AlreadyVisitedNode(*HoldDown, NodeVisited) == false)
			{
				NodeVector.push_back(HoldDown);
				if(AlgorithmChoice == 2 || AlgorithmChoice == 3)	
					HoldDown->Gn = HoldTopNode.Gn + 1;
				Expanded = true;
			}
		}
		if(MoveLeftCheck(HoldTopNode.Puzzle) == true)
		{
			Node * HoldLeft = new Node;
			*HoldLeft = MoveLeft(HoldTopNode);
			if(AlgorithmChoice == 1)
				HoldLeft->Gn = HoldTopNode.Gn + 1;
			if(AlgorithmChoice == 2)
				HoldLeft->Hn =MisplacedTile(HoldLeft->Puzzle);
			if(AlgorithmChoice == 3)
				HoldLeft->Hn = ManhattanDistance(HoldLeft->Puzzle);
			if(AlreadyVisitedNode(*HoldLeft, NodeVisited) == false)
			{
				NodeVector.push_back(HoldLeft);
				if(AlgorithmChoice == 2 || AlgorithmChoice == 3)		
					HoldLeft->Gn = HoldTopNode.Gn + 1;
				Expanded = true;
			}
		}
		if(MoveRightCheck(HoldTopNode.Puzzle) == true)
		{
			Node * HoldRight = new Node;
			*HoldRight = MoveRight(HoldTopNode);
			if(AlgorithmChoice == 1)
				HoldRight->Gn = HoldTopNode.Gn + 1;
			if(AlgorithmChoice == 2)
				HoldRight->Hn = MisplacedTile(HoldRight->Puzzle);
			if(AlgorithmChoice == 3)
				HoldRight->Hn = ManhattanDistance(HoldRight->Puzzle);
			if(AlreadyVisitedNode(*HoldRight, NodeVisited) == false)
			{
				NodeVector.push_back(HoldRight);
				
				if(AlgorithmChoice == 2 || AlgorithmChoice == 3)	
					HoldRight->Gn = HoldTopNode.Gn + 1;
				Expanded = true;
			}

		}
		//If the parent node was expanded, then increment Expanded. (Used to keep track)
		if(Expanded == true)
		{
			Expanded = false;
			++ExpandedNodes;
		}
		SortNodes(NodeVector); //Sort the vector of nodes by cost
	}
	return *InitialNode; //Returning inital puzzle means failure
}

//Uses a default puzzle
void DefaultPuzzle()
{
	vector<int> Puzzle;
	Puzzle.push_back(0);
	Puzzle.push_back(1);
	Puzzle.push_back(2);
	Puzzle.push_back(4);
	Puzzle.push_back(5);
	Puzzle.push_back(3);
	Puzzle.push_back(7);
	Puzzle.push_back(8);
	Puzzle.push_back(6);
	
	//Choice of Algorithm
	cout << "Enter your choice of algorithm" << endl;
	cout << "1. Uniform Cost Search" << endl;
	cout << "2. A* with the Misplaced Tile heuristic" << endl;
	cout << "3. A* with the Manhattan distance heuristic" << endl;

	int AlgoChoice;
	cin >> AlgoChoice;

	Search(Puzzle, ReturnPuzzleGoal(), AlgoChoice);
}

int main() 
{
	//Introduction
	cout << "Welcome to Christopher Hyun's 8-Puzzle Solver." << endl;
	cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;

	//Takes user input | 1 = default puzzle | 2 = custom puzzle |
	int UserDecision = 0;
	cin >> UserDecision;
	
	//Gives search a default puzzle
	if (UserDecision == 1)
		DefaultPuzzle();

	//Initiates a custom puzzle | 2 = custom puzzle |
	if (UserDecision == 2)
	{
		vector<int> Puzzle;
		cout << "Enter your puzzle, use a zero to represent the blank." << endl;
		cout << "Enter the first row, use space or tabs between numbers ";
		
		int Row01N1;
		int Row01N2;
		int Row01N3;
		cin >> Row01N1 >> Row01N2 >> Row01N3;
		
		cout << "Enter the second row, use space or tabs between numbers ";
		int Row02N1;
		int Row02N2;
		int Row02N3;
		cin >> Row02N1 >> Row02N2 >> Row02N3;
		
		cout << "Enter the third row, use space or tabs between numbers ";
		int Row03N1;
		int Row03N2;
		int Row03N3;
		cin >> Row03N1 >> Row03N2 >> Row03N3;
		
		Puzzle.push_back(Row01N1);
		Puzzle.push_back(Row01N2);
		Puzzle.push_back(Row01N3);
		Puzzle.push_back(Row02N1);
		Puzzle.push_back(Row02N2);
		Puzzle.push_back(Row02N3);
		Puzzle.push_back(Row03N1);
		Puzzle.push_back(Row03N2);
		Puzzle.push_back(Row03N3);
		
		//Choice of Algorithm | 1 = UCS | 2 = Misplaced | 3 = Manhattan |
		cout << "Enter your choice of algorithm" << endl;
		cout << "1. Uniform Cost Search" << endl;
		cout << "2. A* with the Misplaced Tile heuristic" << endl;
		cout << "3. A* with the Manhattan distance heuristic" << endl;
		
		int AlgoChoice;
		cin >> AlgoChoice;
		Node EndGoal = Search(Puzzle, ReturnPuzzleGoal(), AlgoChoice); //Initiate search
	}

	system("pause");
	return 0;
}