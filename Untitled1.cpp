#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

struct Rectangle {
int width ;
int height ;
} ;

//rectangle command
enum CommandKind { ADD, SORT, PRINT, CLEAR, EXIT, INVALID} ;

//get command
const CommandKind getCommandKind(string s){
	if(s == "ADD")	return ADD;
	if(s == "SORT")	return SORT;
	if(s == "PRINT")	return PRINT;
	if(s == "CLEAR")	return CLEAR;
	if(s == "EXIT")	return EXIT;	
}

//input Rectangle
Rectangle getRectangle(){
	Rectangle R;
	cin >> R.height;
	cin >> R.width;
	return R;
	
}

//sort rectangle by it's height
bool sort_by_hieght( const Rectangle & lhs, const Rectangle & rhs )
{
   return lhs.height < rhs.height;
}

//print all rectangle
void print(vector<Rectangle> rectangles){
	vector<Rectangle>::iterator iter=rectangles.begin();
	
	for (iter = rectangles.begin(); iter != rectangles.end(); ++iter){
        cout << iter->height << endl;
        cout << iter->width << endl;
        
    }

}


int main() {
	vector<Rectangle> rectangles ;
	
	//getcommand modify data
	while ( true ) {
		string commandString;
		cin >> commandString;
		const CommandKind command = getCommandKind(commandString) ;
		switch ( command ) {
			case ADD : {
				const Rectangle& newRectangle = getRectangle() ;
				rectangles.push_back(newRectangle) ;
				break ;
			}
			case PRINT:
				print(rectangles);
				break ;
			case SORT: {
			sort(rectangles.begin(),rectangles.end(),sort_by_hieght) ; 
			break ;
			}	
			case CLEAR: rectangles.clear() ; break ;
			case EXIT: break ;
			default: assert (false) ; break ;
			}
			if ( command == EXIT ) break ;
			}
			
}


